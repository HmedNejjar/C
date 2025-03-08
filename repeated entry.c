#include <stdio.h>

int main (void)
{
	int arr[] = {1, 5 ,2, 4, 1, 6, 8, 41, 25, 3, 32, 1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int x = 0;
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size - 1; j++)
		{
			if (arr[i] == arr[j])
			{
				x++;
			}
		}
	}
	
	
}