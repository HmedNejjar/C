#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
    srand(time(NULL));
    int a, b, c, d, e, f;
    
    a = 1 + rand() % 5;
    b = 1 + rand() % 5;
    c = 1 + rand() % 5;
    d = 1 + rand() % 5;
    e = 1 + rand() % 5;
    f = 1 + rand() % 5;

    int choices[6] = {a, b, c, d, e, f};
    int correctIndex = rand() % 4;

    for (int i = 0; i < 6; i++)
    {
        int j = rand() % 6;

        int tmp = choices[i];
        choices[i] = choices[j];
        choices[j] = tmp;
    }

    printf("Choose:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", choices[i]);
    }
    int answer;
    scanf("%d", &answer);

    if (answer == f)
    {
        printf("好的!\n");
    }
    else printf("Hmar\n");
}