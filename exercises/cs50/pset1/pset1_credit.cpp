#include <cs50.h>
#include <stdio.h>
/* this program reports whether user's credit card number
is a valid American Express, MasterCard, or Visa card number */
int count;
// Validating credit card numbers
bool isCreditValid(long long credit)
{
    count = 1;
    int sumDigits = 0;
    do
    {
        int digit = credit % 10;

        if (count % 2 == 0)     // digit at odd position
        {
            digit = digit * 2;
            sumDigits += (digit / 10) + (digit % 10);
        }
        else                    // digit at even position
        {
            sumDigits += digit;    
        }

        // Update for next loop
        credit = credit / 10;
        count++;
    }
    while (credit > 0);

    count--;
    return (sumDigits % 10 == 0);
}

bool isAmex(long long credit)   // American Express
{
    if (count == 15 && ((int)(credit / 1e13) == 34 || (int)(credit / 1e13) == 37))
    {
        return true;
    }
    return false;
}

bool isMaster(long long credit) // MasterCard
{
    if (count == 16 && (int)(credit / 1e14) >= 51 && (int)(credit / 1e14) <= 55)
    {
        return true;
    }
    return false;
}

bool isVisa(long long credit)   // Visa card
{
    if ((count == 13 && (int)(credit / 1e12) == 4) ||
        (count == 16 && (int)(credit / 1e15) == 4))
    {
        return true;
    }
    return false;
}

int main()
{
    
    long long credit;
    credit = get_long("Number: ");     // prompts the user for a credit card number

    if (isCreditValid(credit))
    {
        if (isAmex(credit))
        {
            printf("AMEX\n");
        }
        else if (isVisa(credit))
        {
            printf("VISA\n");
        }
        else if (isMaster(credit))
        {
            printf("MASTERCARD\n");  
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
