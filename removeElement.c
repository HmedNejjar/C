#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int counter = 1;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == val)
        {
            nums[i] = nums[i+1];
        if (nums[i] != nums[counter - 1])
        {
            nums[counter ] = nums[i];
            counter++;
        }
        }
    }
    return counter;
}