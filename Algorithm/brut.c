#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{
    int i;
    char pass[50], salt[3];
    FILE *fp;
    string hash;

    if (argc != 2)
    {
        printf("Usage: ./brut hash\n");
        return 1;
    }

// Determine SALT
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    salt[2] = '\0';
// Open file with popular passwords
    if ((fp = fopen("dict.txt", "r")) == NULL)
    {
        printf("Can't open dictionary file dict.txt\n");
        return 1;
    }
// Read passwords by strings
nextStr:
    fgets(pass, 256, fp);
// Last char of readed string is \n, it should be changed to \0
    for (i = 0; pass[i] != 10; i++) { }
    pass[i] = 0;
// Compare generated and original hashes
    if (strcmp(crypt(pass, salt), argv[1]) == 0)
    {
        printf("%s\n", pass);
        return 0;
    }
    else
    {
        goto nextStr;
    }

    fclose(fp);
    return 0;
}
