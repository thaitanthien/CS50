from cs50 import get_int, get_string

# This program prints out a double half-pyramid of a specified height

# Input the half-pyramid's height
while True:
    n = get_int("Height: ")
    if (n >= 1 and n <= 8):
        break

# Generate the desired double half-pyramid
for i in range(n):
    for j in range(n-i-1):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print("  ", end="")
    for l in range(i+1):
        print("#", end="")
    print()