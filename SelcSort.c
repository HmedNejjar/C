#include <stdio.h>

int findSmallest(int arr[], int arrLength)
{
    int smallest = arr[0], small_index = 0;

    for (int i = 1; i < arrLength; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
            small_index = i;
        }
    }

    return small_index;
}

int* selectionSort(int arr[], int arrLength)
{
    int* sorted = (int*) malloc(arrLength * sizeof(int));

    for(int i = 0; i < arrLength; i++)
    {   int small_ind = findSmallest(arr, arrLength);
        int small = arr[small_ind];

        sorted[i] = small;
        arr[small_ind] = 99999999999999;
        printf("%d ", sorted[i]);
    }

    return sorted;
}

int main (void)
{
    int arr[10] = {10, 50, 7, 5, 30, 12, 80, 1, 0, -5};
    int length = 10;

    printf("original array: ");
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");

    printf("Sorted array: ");
    selectionSort(arr, length);
    
}