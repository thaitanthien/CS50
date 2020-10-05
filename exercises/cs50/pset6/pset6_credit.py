from cs50 import get_int

""" This program reports whether user's credit card number
is a valid American Express, MasterCard, or Visa card number """

def main():

    # Input a credit card number
    credit = get_int("Number: ")

    # Assign returned tuple from isValid(credit)
    ValidCard, count = isValid(credit)

    if ValidCard:
        # Check what kind of credit card it is
        if isAmex(credit, count):
            print("AMEX")
        elif isMaster(credit, count):
            print("MASTERCARD")
        elif isVisa(credit, count):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


# Check if a credit card number is valid
def isValid(credit):

    sumDigits = 0
    count = 1

    while credit > 0:
        digit = credit % 10

        if (count % 2) == 0:
            # Digit at odd position
            digit = digit * 2
            sumDigits += digit % 10 + int(digit / 10)
        else:
            # Digit at even position
            sumDigits += digit

        # Update for the new loop
        count += 1
        credit = int(credit / 10)

    # Number of digits
    count -= 1

    # Return a tuple
    return (sumDigits % 10 == 0), count


# Check if credit card is American Express
def isAmex(credit, count):
    if count == 15 and int(credit / 1e13) == 34 or int(credit / 1e13) == 37:
        return True
    return False

# Check if credit card is Master Card
def isMaster(credit, count):
    if count == 16 and (int(credit / 1e14) >= 51) and (int(credit / 1e14) <= 55):
        return True
    return False

# Check if credit card is Visa
def isVisa(credit, count):
    if (count == 13 and int(credit / 1e12) == 4) or (count == 16 and int(credit / 1e15) == 4):
        return True
    return False


main()