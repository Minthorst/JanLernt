#include <cs50.h>
#include <stdio.h>

int main(void)
{

    //ask for CC
    long cc;
    cc = get_long("whats you CC No.?\n");

    //Luhns alg
    long x = cc;
    long s1 = 0;
    long s2 = 0;
    long st = 0;


    do
    {
        //get last digit
        s1 = x % 10;
        //add last digit to total
        st = st + s1;
        //get rid of last digit
        x = x / 10;
        //double last digit
        s2 = (x % 10) * 2;
        //add both digits to total
        st = st + (s2 % 10) + (s2 / 10);
        //get rid of last digit
        x = x / 10;
    }
    //stopp when no digits left
    while (x > 0);

    st = st % 10;

    if (st != 0)
    {
        printf("INVALID\n");
    }

    else
    {

        //check if VISA
        if (((cc > 4000000000000 && cc < 4999999999999) || (cc > 4000000000000000 && cc < 4999999999999999)))
        {
            printf("VISA\n");
        }

        //check if AMEX
        else if (((cc > 340000000000000 && cc < 349999999999999) || (cc > 370000000000000 && cc < 379999999999999)))
        {
            printf("AMEX\n");
        }

        //check if Master
        else if (cc > 5100000000000000 && cc < 5599999999999999)
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
}

