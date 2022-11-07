#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int i = 0;

int main(int argc, string argv[])
{

// if no or more than one comand line Input = Error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

//assign cipher strg
    string cipher = argv[1];

//make cipher all lower && break if cipher uses other than letters
    for (i = 0; cipher[i] != 0; i++)
    {
        if (isalpha(cipher[i]))
        {
            cipher[i] = tolower(cipher[i]);
        }
        else
        {
            printf("Only use letters\n");
            return 1;
        }
    }

// check that cipher is 26 chars
    if (i != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

//make sure no double are used
    for (i = 0; i < 26 ; i++)
    {
        for (int j = i + 1; j < 25; j++)
        {
            if (cipher[i] == cipher[j])
            {
                printf("Please use every letter only once.\n");
                return 1;
            }
        }

    }
    string text = get_string("text: \n");
    string ctext = text;


    for (i = 0 ; text[i] != 0 ; i++)
    {
        if (islower(text[i]))
        {
            ctext[i] = (cipher[(text[i] - 97)]);
        }
        else if (isupper(text[i]))
        {
            ctext[i] = (cipher[(text[i] - 65)]) - 32;
        }
        else
        {
            ctext[i] = text[i];
        }
    }

    printf("ciphertext: %s\n", ctext);

}








