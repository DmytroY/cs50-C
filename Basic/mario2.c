#include <stdio.h>
#include <cs50.h>

//request pyramid height and build like this:
//     #  #
//    ##  ##
//   ###  ###
//  ####  ####
// #####  #####
int main(void)
{
    int h,c,r;
mark:
    h = get_int("Please input the height of the piramid, an integer value ir range of[1,8]:\n");
    if (h<1 || h>8)
    {
        printf("Warning! Must be an integer value ir range of[1,8]:\n");
        goto mark;
     }
// By row
    for (r=1; r<=h; r++)
    {
    // By column
        // Left part of piramid
        for(c = 1; c <= h; c++)
        {
            if(c <= (h-r))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        // Gap
        printf("  ");

        // Right part of piramid
        for(c = 1; c <= h; c++)
        {
            if(c <= r)
            {
                printf("#");
            }
        }
        // Move cursor to the next string
        printf("\n");
    }
}
