#include <stdio.h>

int maxNum(int* arr, int len)
{
    if (len == 0) return -1;
    else
    {
        int max = arr[0];

        for(int i = 1; i < len; i++)
        {
            max = max > arr[i] ? max : arr[i];
        }
        return max;
    }
}