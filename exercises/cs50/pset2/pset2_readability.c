#include <cs50.h>
#include <stdio.h>
#include <string.h>

// This program computes the approximate grade level needed to comprehend some text
int letters = 0;
int words = 0;
int sentences = 0;

int main(void)
{

    string text = get_string("Text: "); // getting user input
    
    // count the number of letters in the text
    for (int i = 0; i < strlen(text); i++) 
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) 
        {
            letters += 1;
        }
    }
    
    // count the number of words in the text
    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] == ' ')
        {
            words += 1;
        }
    }
    words++;
    
    // count the number of sentences in the text
    for (int i = 0; i < strlen(text); i++) 
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') 
        {
            sentences += 1;
        }
    }


    // Coleman-Liau index
    float L = (float) letters * 100 / (float) words;
    float S = (float) sentences * 100 / (float) words;
    
    float index = (0.0588 * L) - (0.296 * S) - 15.8;    // calculate Coleman-Liau index
    int roundIndex = index + 0.5;       // round the index to nearest integer
    
    if (roundIndex >= 16) 
    {
        printf("Grade 16+\n");
    }
    else if (roundIndex < 1) 
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", roundIndex);
    }
    
    return 0;
}