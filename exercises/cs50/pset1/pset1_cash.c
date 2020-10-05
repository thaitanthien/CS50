#include <stdio.h>
#include <cs50.h>
#include <math.h>

// This program calculates the minimum number of coins required to give a user change
int main(void)
{
    
    float n;
    do
    {
        n = get_float("Change owed: \n");
    }
    while (n <= 0);

    int cents = round(n * 100); // round cents to the nearest penny

    int x1 = cents / 25;                    // number of quaters
    int x2 = (cents % 25) / 10;             // number of dimes
    int x3 = ((cents % 25) % 10) / 5;       // number of nickels
    int x4 = ((cents % 25) % 10) % 5;       // number of pennies

    printf("%i\n", x1 + x2 + x3 + x4);

    return 0;
}
