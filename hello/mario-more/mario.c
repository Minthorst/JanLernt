#include <cs50.h>
#include <stdio.h>



int main(void)
{
    int n, i, j, k;

//get input between 1 and 8
    do
    {
        n = get_int("How high should the Pyramid be?\n");
    }
    while (n > 8 || n < 1);

    // loop n times
    for (i = 0; i < n; i++)
    {

        for (j = i; j < n - 1; j++)
        {
            printf(" ");
        }

        for (k = i; k > -1; k--)
        {
            printf("#");
        }

        printf("  ");

        for (k = i; k > -1; k--)
        {
            printf("#");
        }


        printf("\n");
    }



}


