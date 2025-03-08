#include <stdio.h>
#include <stdlib.h>

int* comp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}


int* sort(int* arr, int len)
{
    qsort(arr, len, sizeof(int), comp);

    return arr;
}

int main() {
    int arr[] = {5, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, n);


    for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
}