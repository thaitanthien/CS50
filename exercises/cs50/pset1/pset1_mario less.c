#include <cs50.h>
#include <stdio.h>

// # This program prints out a half-pyramid of a specified height on Mario game

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");    // input the pyramid's height
    }
    while (n < 1 || n > 8);

    for (int i = 1; i <= n; i++)
    {
        for (int j = (n - i); j > 0; j--)
        {
            printf(" ");    // print spaces
        }
        for (int k = 1; k <= i; k++)
        {
            printf("#");    // print hashes
        }
        printf("\n");
    }

    return 0;
}
