#include <stdio.h>

int sum(int* arr, int len)
{
    if (len == 0) return 0;
    if (len == 1) return arr[0];

    else
    {
        int result = arr[0] + sum(arr + 1, len-1);
        return result;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Sum: %d\n", sum(arr, size));
    return 0;
}