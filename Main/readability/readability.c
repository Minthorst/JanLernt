#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int letter, word, sentence;

int count_letters(string TEXT);
int count_words(string TEXT);
int count_sentences(string TEXT);


int main(void)
{
    string TEXT = get_string("Text: ");

    letter = count_letters(TEXT);
    word = count_words(TEXT);
    sentence = count_sentences(TEXT);

    // calculate grade
    float L = (((float) letter / (float) word) * 100);
    float S = ((float) sentence / (float) word);

    float index = 0.0588 * L - 0.296 * S * 100 - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", ((int) round(index)));
    }
}



int count_letters(string TEXT)
{
    // if char is lower or uppercase letter add letter
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if ((isupper(TEXT[i])) || (islower(TEXT[i])))
        {
            letter++;
        }
    }
    return letter;
}

int count_words(string TEXT)
{
    //add the first word
    word = 1;

    //add a word for each space
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if (TEXT[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

int count_sentences(string TEXT)
{
    //add sentence when !, . or ? appears
    for (int i = 0, n = strlen(TEXT); i < n; i++)
    {
        if ((TEXT[i] == '.') || (TEXT[i] == '!') || (TEXT[i] == '?'))
        {
            sentence++;
        }
    }
    return sentence;
}