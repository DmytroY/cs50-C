#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number, temp;
    int i, n[16];
    bool valid;
    string paySys;

start:
    number = get_long("Number:");
    //if (number <= 0)
    if (number < 0 || number >= 1e16)
    {
        goto start;
    }

    // Determining payment system   
    paySys="INVALID";
    temp=number/1e12;
    if (temp == 4) { paySys="VISA";}
    temp=number/1e13;
    if (temp == 34 || temp == 37) {paySys="AMEX";}
    temp=number/1e15;
    if (temp == 4) { paySys="VISA";}
    temp=number/1e14;
    if (temp >= 51 && temp <= 55) {paySys="MASTERCARD";}
    //printf("%s \n",paySys);

    // Luhn algorithm
    // Step 0. Preparation - put decimal places digits of "number" in to array n(16)
    temp=number;
    for (i=0; i<16; i++)
    {
        n[i]=temp%10;
        temp=temp/10;
    }

    // Step 1. every 2nd *2 then summ digits
    temp=0;
    for (i=1; i<16; i+=2)
    {
        temp=temp+(int)(2*n[i])/10+(int)(2*n[i]%10);
    }

    // Step 2. Add digits which was not used in Step 1
    for (i=0; i<16; i+=2)
    {
        temp=temp+n[i];
    }

    // Step 3. Last digit should be 0
    if(temp%10 == 0)
    {
        printf("%s\n",paySys);
    } 
    else
    {
        printf("INVALID\n");
    }
}
