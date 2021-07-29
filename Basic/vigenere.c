// request key word and incript message with Chiffre de Vigenère
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int shift(char c);

int main(int argc, string argv[])
{
    int i, j, k; // i-counter for plaintext, j - counter for keyword, k - shift
    string plaintext, keys=argv[1];
    char c;
    // Must be one argument in command line
    if (argc!=2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1; 
    }
    // A argument must be a word  
    for (i=0; i<strlen(keys); i++)
    {
        if(isalpha(keys[i]) == 0)
        {
            printf("invalid keyword\n");
            return 1;
        }
    }
// ========= Argument is OK, lets start coding =========
    plaintext=get_string("plaintext:  ");
    printf("ciphertext: ");
    j=0;
    for (i=0; i<strlen(plaintext); i++)
    {
        k=shift(keys[j]);     
        // Uppercase letter range
        if (plaintext[i]>=65 && plaintext[i]<=90)
        {
            //shift message char
            c=plaintext[i]+k;
            // if jump over range
            if (c<65 || c>90)
            {
                c=c-26;
            }
            // Next character of keyword
             if( j < strlen(keys)-1 ) { j++; } else { j=0; }

            goto print;
        }
        // Lowercase letter range
        if (plaintext[i]>=97 && plaintext[i]<=122)
        {
            c=plaintext[i]+k;
            if (c<97 || c>122)
            {
                c=c-26;
            }
            // Next character of keyword
            if( j < strlen(keys)-1 ) { j++; } else { j=0; }
            goto print;
        }
        // Other simbols
        c=plaintext[i];
print:        
        printf("%c",c);
    }
    printf("\n");
}
// ========= User defined routines ========
// Convert key word char to a shift dimention
int shift(char c)
{
    if(isupper(c))  { return ((int)c-65); }
    return ((int)c-97);
}
