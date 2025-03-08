#include <stdio.h>

#define cols 10
#define rows 6

int main (void)
{
    int i, j, ascii[rows][cols];
    printf("     ");

    for (j = 0; j < cols; j++)
    {
        printf("%d || ", j);

        if(j %10 == 9)
        {
            printf("\n");
        }
    }

    for (i = 0; i < rows; i++)
    {
        printf ("%d || ", i+4);

        for (j = 0; j < cols; j++)
        {
            ascii[i][j] = 10*(i+4) + j;
            printf("%c || ", ascii[i][j]);

            if(ascii[i][j] %10 == 9)
        {
            printf("\n");
        }
        }
    }
}