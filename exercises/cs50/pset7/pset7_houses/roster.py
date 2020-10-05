from sys import argv, exit
from cs50 import SQL

# Check command_line arguments
if len(argv) != 2:
    print("Usage: python roster.py house")
    exit(1)

entered_house = argv[1]

# Set up a database connection so Python scrip interact with SQL database
db = SQL("sqlite:///students.db")


# Query database for all students in specified house
rows = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", entered_house)

# Print out result
for row in rows:
    first, middle, last, birth = row["first"], row["middle"], row["last"], row["birth"]
    print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")
