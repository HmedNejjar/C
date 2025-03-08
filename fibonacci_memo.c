#include <stdio.h>
#define MAX 100

long fibonacci (int x, long long *memo);

int main (void)
{
    int n;
    long long fib, memofib[MAX];

    for (int i = 0; i < MAX; i++)
    {
        memofib[i] = -1;
    }

    printf("Type in number: ");
    scanf("%d", &n);

    fib = fibonacci(n, memofib);

    printf("Fib(%d) = %lld", n, fib);

}

long fibonacci (int x, long long *memo)
{
    if (x < 0 || x >= MAX)
    {
        return -1;
    }
    
    
    if (memo[x] != -1)
    {
        return memo[x];
    }

    if (x == 0)
    {
        memo[x] = 0;
    }

    else if (x == 1)
    {
        memo[x] = 1;
    }


    else
    {
    memo[x] = fibonacci(x-1, memo) + fibonacci(x-2, memo);
    }    

    return memo[x];
}