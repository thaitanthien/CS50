from cs50 import get_float

# This program calculates the minimum number of coins required to give a user change

# Input the amount of money
while True:
    n = get_float("Change owed: ")
    if n > 0:
        break

# Round cents to the nearest penny
cents = int(round(n * 100))

# Calculate the number of each coins
quater = int(cents / 25)
dime = int((cents % 25) / 10)
nickel = int((cents % 25 % 10) / 5)
penny = int(cents % 25 % 10 % 5)

# Print the minimum number of coins
print(f"{quater + dime + nickel + penny}")
