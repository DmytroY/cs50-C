// request text than determine Coleman-Liau index of the text

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Prompt for plaintext
    string text = get_string("Text: ");
    
    // Calculate letters, words and sentences
    int i, grade = 0, letters = 0, words = 1, sentences = 0;
    
    for (i = 0; i < strlen(text); i++)
    {
        // Calculate letters
        if isalpha(text[i])
        {
            letters++;
        }

        // consider words separated by whitespace
        if isspace(text[i])
        {
            words++;
        }
        //  Consider any sequence of characters that ends with a '.' or a '!' or a '?' to be a sentence
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // calculate and print grade
    grade = roundf(5.88 * letters / words - 29.6 * sentences / words - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
