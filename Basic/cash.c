#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Calculate how many coins should be issued for change
// Coins nominals are 25c, 10c, 5c, 1c
int main(void)
{
    int cents;
    int coins = 0;
start:    
    // geting amount in cents
    cents = (int)roundf(100*get_float("Change?\n"));
    if( cents <= 0 )
    {
        goto start;
    }

    // Count of 25c coins
    while (cents >= 25)
    {
        coins++;
        cents=cents-25;
    }

    // Add 10c coins
    while (cents >= 10)
    {
        coins++;
        cents=cents-10;
    }
 
    // Add 5c coins
    while (cents >= 5)
    {
        coins++;
        cents=cents-5;
    }

    // Add 1c coins
    while (cents >= 1)
    {
        coins++;
        cents=cents-1;
    }
    printf("%i\n",coins);
}
