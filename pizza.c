#include <stdio.h>

int main (void)
{
    int pizza[] = {1,1,0,0,1};
    int tacos[] = {1,0,1,0,1};

    int both[10];

    for (int i = 0; i < 5; i++)
    {
        if (pizza[i] == 1 && tacos[i] == 1)
        {
            both[i] = 1;
        }
        else both[i] = 0;

        printf("%d || ", both[i]);
    }
}