from cs50 import get_int, get_string

# This program prints out a half-pyramid of a specified height

# Input the pyramid's height
while True:
    n = get_int("Height: ")
    if (n >= 1 and n <= 8):
        break

# Generate the desired half-pyramid
for i in range(n):
    for j in range(n-i-1):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print()