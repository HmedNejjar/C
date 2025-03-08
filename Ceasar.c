#include <stdio.h>
#include <math.h>

#define size 1000

void ceasar(char a[], int b);

int main (void)
{
	int key;
	char text[size];
	
	printf("Type in the key: ");
	scanf("%i", &key);
	
	getchar();
	
	printf("PlainText (decrypterd): ");
	fgets(text, size, stdin);
	printf("\n");
	
	
	ceasar(text, key);
	
	return 0;
}

void ceasar(char a[], int b)
{
	printf("CypherText (encryped): ");
	
	for (int i = 0; a[i] != '\0' && a[i] != '\n'; i++)
	{
		if (a[i] >= 'A' && a[i]<= 'Z')
		{
			a[i] = (a[i] - 'A' + b) %26 + 'A';
		}
		
		if (a[i] >= 'a' && a[i]<= 'z')
		{
			a[i] = (a[i] - 'a' + b) %26 + 'a';
		}
		
		printf("%c", a[i]);
	}
	
}