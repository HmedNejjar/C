#include <stdio.h>

#define ROWS 6
#define COLUMNS 10


int main (void)
{
	int i, j, ascii[ROWS][COLUMNS];
	
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)  
		{
			ascii[i][j] = 10*(i+4)+j;	// setting ASCII values in the array
		}
	}
	
	printf(" ");
	
	for (j = 0; j < COLUMNS; j++)  //printing the first line
	{
		printf("%d ", j);
	}
	printf("\n");
	
	for (i = 0; i < ROWS; i++)
	{
		printf("%i ", i+4); //printing first number of each column (4, 5...9)
		
		for (j = 0; j < COLUMNS; j++)
		{
			printf("%c ", ascii[i][j]); //printing the ASCII Values stored in the array from 40 to 99
		}
		printf("\n");
	}
		
	
}