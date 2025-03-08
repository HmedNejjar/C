#include <stdio.h>
#define SIZE 5

void reverseArray(int *arr, int size);

int main (void)
{
	int array[SIZE] = {1, 2, 4, 3, 5};
	
	printf("Original Array :\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d, ", array[i]);
	}
	
	printf("\n");
	
	reverseArray(array, SIZE);
	
		printf("Reversed Array :\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
	
	return 0;	
}


void reverseArray(int *arr, int size)
{
	
	int temp;
	
	for (int i = 0; i < size / 2; i++)
	{
		temp = *(arr + i);
		*(arr + i) = *(arr + size -1 -i);
		*(arr + size -1 -i) = temp;
	}
}