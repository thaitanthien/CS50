#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool isDigit(char c)
{
    return '0' <= c && c <= '9';
}

// Validating the Input
bool isInputValid(int argc, string argv[]);


int main(int argc, string argv[])
{

    if (isInputValid(argc, argv)) // address:
    {
        // Convert the key's type from string to number
        char *ptr;                              // Or use: int key = atoi(argv[1]);
        long key = strtol(argv[1], &ptr, 10);

        string text = get_string("plantext: "); // Input a plaintext

        // Encrypt the text
        for (int i = 0; i < strlen(text); i++)
        {
            if (text[i] >= 65 && text[i] <= 90)             // Uppercase letters
            {
                text[i] = (char)((((int) text[i] - 65 + key) % 26) + 65);
            }
            else if (text[i] >= 97 && text[i] <= 122)       // Lowercase letters
            {
                text[i] = (char)((((int) text[i] - 97 + key) % 26) + 97);
            }
        }

        printf("ciphertext: %s\n", text);   // Output ciphertext
        return 0;
    }

    printf("Usage: ./caesar key");
    return 1;

}

bool isInputValid(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) == 0)   // No command-line arguments, or two or more
    {
        return false;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // if (argv[1][i] < '0' || argv[1][i] > '9') // Character(s) of the command line argument is not a decimal digit
        if (!isDigit(argv[1][i]))
        {
            return false;
        }
    }

    return true;
}