#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

void guess(int correct);

int main (void)
{   
    srand(time(NULL));

    int correct =1 + (rand() % N);

    guess(correct);
}

void guess(int correct)
{
    int low = 1, high = N, attempt = 0, UserGuess;
    printf("Guess the number: ");
    while(1)
    {
        scanf("%d", &UserGuess);
        if(UserGuess < low || UserGuess > high)
        {
            printf("Guess should be between 1 and %d\n",N);
        }

        if(UserGuess < correct)
        {
            attempt++;
            printf("Too Low!\nAttempts : %d\n", attempt);
            continue;
        }
        else if (UserGuess > correct)
        {
            attempt++;
            printf("Too high!\nAttempts : %d\n", attempt);
            continue;
        }

        else
        {
            attempt++;
            printf("NICEE!\nAttemps : %d\n", attempt);
            break;
        }
    }

    


}