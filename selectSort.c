#include <stdio.h>
#include <string.h>

char findSmallest(char* a)
{   int smallest = a[0];
    int small_ind = 0;
    int len_a = strlen(a);
    for (int i = 1; len_a; i++)
    {  
         if(a[i] < smallest)
         {
            smallest = a[i];
            small_ind = i;
         } 
    }

    return small_ind;
}

char* selectionSort(char* a)
{
    int len_a = strlen(a);
    char b[len_a];
    char* result = (char*) malloc(len_a*sizeof(char));

    for (int i = 0; i < len_a; i++)
    {
        b[i] = a[i];
    }

    for (int i = 0; i < len_a; i++)
    {
        int smallestIndex = findSmallest(b);
        result[i] = b[smallestIndex];

        for (int j = 0; j < len_a - i - 1; j++)
        {
            b[j]  = b[j+1];
        }
    }
    return result;
}