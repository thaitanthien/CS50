import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    rows = db.execute("""SELECT symbol, SUM(shares) as totalShares
                         FROM transactions
                         WHERE user_id=:user_id
                         GROUP BY symbol
                         HAVING totalShares > 0;
                      """, user_id=session["user_id"])
    holdings = []
    grand_total = 0
    for row in rows:
        stock = lookup(row["symbol"])
        holdings.append({
            "symbol": stock["symbol"],
            "name": stock["name"],
            "shares": row["totalShares"],
            "price": usd(stock["price"]),
            "total": usd(stock["price"] * row["totalShares"])
        })
        grand_total += stock["price"] * row["totalShares"]
    rows = db.execute("SELECT cash FROM users WHERE id=:user_id", user_id=session["user_id"])
    cash = rows[0]["cash"]
    grand_total += cash

    return render_template("index.html", holdings=holdings, cash=usd(cash), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        if not request.form.get("symbol"):
            return apology("missing symbol", 400)
        if not request.form.get("shares"):
            return apology("missing shares", 400)
        if not request.form.get("shares").isdigit():
            return apology("invalid number of shares", 400)

        symbol = request.form.get("symbol").upper()
        shares = int(request.form.get("shares"))
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol", 400)

        rows = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = rows[0]["cash"]
        updated_cash = cash - shares * stock['price']
        if updated_cash < 0:
            return apology("can't afford")
        db.execute("UPDATE users SET cash=:updated_cash WHERE id=:id",
                    updated_cash=updated_cash, id=session["user_id"])
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :price)",
                    user_id=session["user_id"],
                    symbol=stock['symbol'],
                    shares=shares,
                    price=stock['price'])
        flash("Bought!")
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute("SELECT symbol, shares, price, transacted FROM transactions WHERE user_id=:user_id", user_id=session["user_id"])
    for i in range(len(rows)):
        rows[i]["price"] = usd(rows[i]["price"])
    return render_template("history.html", rows = rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    else:
        if not request.form.get("symbol"):
            return apology("missing symbol", 400)

        symbol = request.form.get("symbol").upper()
        stock = lookup(symbol)
        if stock is None:
            return apology("invalid symbol", 400)

        return render_template("quoted.html", stock={
            'name': stock['name'],
            'symbol': stock['symbol'],
            'price': usd(stock['price'])})


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        if not request.form.get("username"):
            return apology("Username is not available")
        if not request.form.get("password"):
            return apology("missing password", 400)
        if not request.form.get("confirmation") or request.form.get("password") != request.form.get("confirmation"):
            return apology("password don't match", 400)
        try:
            rows = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                               username=request.form.get("username"),
                               hash=generate_password_hash(request.form.get("password")))
        except:
            return apology("username already exists", 403)
        if rows is None:
            return apology("register error", 403)
        session["user_id"] = rows
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        rows = db.execute("SELECT symbol FROM transactions WHERE user_id=:user_id GROUP BY symbol HAVING SUM(shares) > 0", user_id=session["user_id"])
        return render_template("sell.html", symbols = [ row["symbol"] for row in rows ])
    else:
        if not request.form.get("symbol"):
            return apology("missing symbol", 400)
        if not request.form.get("shares"):
            return apology("missing shares", 400)
        if not request.form.get("shares").isdigit():
            return apology("invalid number of shares", 400)

        symbol = request.form.get("symbol").upper()
        shares = int(request.form.get("shares"))
        stock = lookup(symbol)

        rows = db.execute("""SELECT symbol, SUM(shares) as totalShares FROM transactions
                           WHERE user_id=:user_id GROUP BY symbol HAVING totalShares > 0""", user_id=session["user_id"])
        for row in rows:
            if symbol == row["symbol"]:
                if shares > row["totalShares"]:
                    return apology("too many shares")

        rows = db.execute("SELECT cash FROM users WHERE id=:id", id=session["user_id"])
        cash = rows[0]["cash"]
        updated_cash = cash + shares * stock["price"]

        db.execute("UPDATE users SET cash=:updated_cash WHERE id=:id",
                    updated_cash=updated_cash, id=session["user_id"])

        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (:user_id, :symbol, :shares, :price)",
                    user_id=session["user_id"],
                    symbol=stock["symbol"],
                    shares= -1 * shares,
                    price=stock["price"])

        flash("Sold!")
        return redirect("/")


@app.route("/change_password", methods=["GET", "POST"])
def changePassword():
    if request.method == "GET":
        return render_template("change_password.html")
    else:
        password = request.form.get("password")
        newPassword = request.form.get("newPassword")
        confirmation = request.form.get("confirmation")
        if not password:
            return apology("missing password", 400)
        if not newPassword:
            return apology("missing new password", 400)
        if not confirmation or newPassword != confirmation:
            return apology("new password don't match", 400)

        rows = db.execute("SELECT * FROM users WHERE id=:id", id=session["user_id"])
        if not check_password_hash(rows[0]["hash"], password):
            return apology("wrong password", 403)

        db.execute("UPDATE users SET hash=:hash WHERE id=:id", hash=generate_password_hash(newPassword), id=session["user_id"])

        flash("Changed password!")
        return redirect("/")


@app.route("/add_cash", methods=["GET", "POST"])
def add_cash():
    if request.method == "GET":
        return render_template("add_cash.html")
    else:
        amount = request.form.get("cash")
        if not amount or amount == 0:
            return apology("missing additional cash", 400)

        db.execute("UPDATE users SET cash = cash + :amount WHERE id=:id", amount=amount, id=session["user_id"])
        flash("Added cash!")
        return redirect("/")


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
