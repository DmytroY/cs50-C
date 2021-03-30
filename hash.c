#include <stdio.h>
#include <crypt.h>

int main(int argc, char *argv[])
{
    char *hash;
    if(argc != 3)
    {
        printf("Usage: ./hash password salt\n");
        return 1;
    }
    hash=crypt(argv[1],argv[2]);
    printf("hash: %s\n",hash);
    return 0;
}
