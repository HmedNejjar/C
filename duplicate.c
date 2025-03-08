#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    if (numsSize == 0) return 0;
    int counter = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[counter - 1])
        {
            nums[counter ] = nums[i];
            counter++;
        }
    }
        return counter;
    
}