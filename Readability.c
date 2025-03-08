#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define size 1000

int text_check(char a[]);

int main (void)
{
    char text[size];

    printf("Text: ");
    fgets(text, size, stdin);

    int score = text_check(text);

    if (score >= 16)
    {
        printf("Grade 16+");
    }

    else
    {
        printf("Grade : %i", score);
    }

}
int text_check(char a[])
{
    int letter = 0, word = 1, sentence = 0;
    int i;

    for (int i = 0; i < strlen(a); i++)
    {
        if (isalpha(a[i]))
        {
            letter++;
        }

        if (isspace(a[i]))
        {
            word++;
        }

        if (a[i] == '.' || a[i] == '?' || a[i] == '!')
        {
            sentence++;
        }

        
    }

    float L = (letter / (float) word) * 100;
        float S = (sentence / (float) word) * 100;

        float index = 0.0588 * L - 0.296 * S - 15.8;

        return (int) round(index);
}