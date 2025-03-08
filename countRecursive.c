#include <stdio.h>

int size(int* arr)
{
    return 1 + size(arr + 1);
}