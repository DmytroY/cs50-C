# include <stdio.h>
# include <stdlib.h>

int fact(int);

int main(int argc, char *argv[])
{
// Check correctness of argument
    if (argc != 2 || atoi(argv[1]) < 1)
    {
        printf("Usage: ./factorial digit(Natural number)\n");
        return 1;
    }
    printf("Factorial of %s is %i \n", argv[1], fact(atoi(argv[1])));
    return 0;
}

// Subroutine for factorial calculating with recursion
int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n*fact(n-1);
}
