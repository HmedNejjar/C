#include <stdio.h>
#include <stdlib.h>
int ModifyMin (int* nums, int numsSize, int multiplier)
{    
   int index = 0;

   for (int i = 1; i < numsSize; i++)
   {
        if (nums[i] < nums[index])
        {
            index = i;
        }
   }
    nums[index] = nums[index] * multiplier;
   return nums[index];
}

int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize)
{
    int* result = (int*) malloc(numsSize * sizeof(int));
    for (int a = 0; a < k; a++)
    {
        ModifyMin(nums, numsSize, multiplier);
    } 
    for (int i = 0; i < numsSize; i++)
    {
        result[i] = nums[i];
    }
    *returnSize = numsSize;
    return result;
}

