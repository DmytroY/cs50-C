// incript message based on simple substitution code, substitution alphabet should be provided as argument in comand line

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define KEYLEN 26

int main(int argc, string argv[])
{
    // Must be one argument in command line
    if (argc != 2)
    {
        printf("Usage: ./ substitution key\n");
        return 1; 
    }
    
    string key = argv[1];
    
    // Key must contain 26 characters.
    if (strlen(key) != KEYLEN)
    {
        printf("Key must contain 26 characters.\nUsage: ./ substitution key\n");
        return 1;
    }
    
    // key must comtain letters only, also we convert toupper
    for (int i = 0; i < KEYLEN; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("key must comtain letters only\n");
            return 1;
        }
        key[i] = toupper(key[i]);
    }

    // letters in the key must be unic
    for (int i = 0; i < KEYLEN; i++)
    {
        for (int j = i + 1; j < KEYLEN; j++)
        {
            if (key[i] == key[j])
            {
                printf("key simbols must be unique\n");
                return 1;                
            }
        }
    }
    
    // Prompt for plaintext
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    int code;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // cript uppercase letter
        if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            code = plaintext[i] - 65;
            printf("%c", key[code]);
        }
        
        // cript lowercase letter
        else if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            code = plaintext[i] - 97;
            printf("%c", tolower(key[code]));
        }
        // Other simbols
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    
    // finalize string
    printf("\n");

}
