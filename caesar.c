// request key digit and incript message with Caesar's code

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int i, k;
    string keys=argv[1], plaintext;
    char c;

    // Must be one argument in command line
    if (argc!=2)
    {
        printf("Usage: ./caesar key\n");
        return 1; 
    }
    // A argument must be a digit  
    for (i=0; i<strlen(keys); i++)
    {
        if(isdigit(keys[i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 2;
        }
    }

    // Convert string to int
    k=atoi(keys);
    k=k%26;
    // Prompt for plaintext
    plaintext=get_string("plaintext:  ");
    printf("ciphertext: ");
    for (i=0; i<strlen(plaintext); i++)
    {
        // Uppercase letter range
        if (plaintext[i]>=65 && plaintext[i]<=90)
        {
            //shift 
            c=plaintext[i]+k;
            // if jump over range
            if (c<65 || c>90)
            {
                c=c-26;
            }
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
            goto print;
        }
        // Other simbols
        c=plaintext[i];
print:        
        printf("%c",c);
    }
    printf("\n");
}
