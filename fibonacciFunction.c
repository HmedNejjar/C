#include <stdio.h>

long fibonacci(int x);

int main (void)
{
    int n;
    long fib;

    printf("Type in the number: ");
    scanf("%d", &n);

    fib = fibonacci(n);
    printf("Fib(%d) = %d", n, fib);
}

long fibonacci(int x)
{
    if (x == 0) return 0;
    if (x == 1) return 1;

    return fibonacci(x-1) + fibonacci(x-2);
}

