#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    srand(time(NULL));

    int a = rand () % 100;
    int b = rand () % 100;

    int correct, wrong;
    char user;

    int opIndex = rand() % 4;
    char op;
    if (opIndex == 0)
    {
        op = '+';
        correct = a + b;
    }
    else if (opIndex == 1)
    {
        op = '-';
        correct = a - b;
    }
    else if (opIndex == 2)
    {
        op = '*';
        correct = a * b;
    }
    else 
    {
        op = '/';
        if (b != 0)
        {
            correct = a / b;
        }
        else
        {
            b = 1;
            correct = a / b;
        }
    }

    int choices[4];
    int correctIndex = rand() % 4;

    for (int i = 0; i < 4; i++)
    {
        if (i == correctIndex)
        {
            choices[i] = correct;
        }
        else
        {
            do
            {
                wrong = rand() %201 -100;
            } while (wrong != correct);

            choices[i] = wrong;
        }
    }

    printf("%d %c %d = \n", a, op, b);
    for (int i = 0; i < 4; i++)
    {
        printf("|| %c) %d ||",97+i, choices[i]);
    }

    printf("Type in choice (a - d): ");
    scanf("%c", &user);

    if ((int) user - 97 == correctIndex + 1)
    {
        printf("Correct");
    }
    else printf("Hmar");
}