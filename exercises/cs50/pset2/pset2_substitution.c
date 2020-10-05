#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Validating the Key
bool isKeyValid(int argc, string argv[])
{
    int count = 0;
    if (argc == 2 && strlen(argv[1]) == 26)
    {
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (argv[1][i] < 65 || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 122)
            {
                count++;
            }
            if (count >= 2)
            {
                break;
            }
        }
        if (count)
        {
            printf("Usage: ./substitution  key");
            return 0;
        }
        else        // The user provides exactly one command-line argument
        {
            return 1;
        }
    }
    else if(argc == 2 && strlen(argv[1]) != 26) // Key is not 26 characters
    {
        printf("Key must contain 26 characters.");
    }
    else if (argc != 2)           // No command-line arguments, or two or more
    {
        printf("Usage: ./substitution  key");
        return 0;
    }
}

int main () {

    string text = get_string("plantext: "); // Prompt the user to input a plaintext
    for(int i = 0; i < strlen(text); i++) {
        if(((int) text[i] >= 65 && (int) text[i] <= 90))

        text[i] = argv[1][i];
    }

   return(0);
}