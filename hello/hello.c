#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask name//
    string name = get_string("What's your name?");

    //greet with name//
    printf("hello, %s\n", name);
}