#include <stdio.h>
#include <ctype.h>

void ConvertToUpperCase (char *sPtr);


int main (void)
{
	char string[] = "characters  and $32.98";
	
	printf("Character before conversion : %s", string);
	ConvertToUpperCase (string);
	
	printf("\nCharacter after conversion : %s", string);
	
	return 0;	
}

void ConvertToUpperCase (char *sPtr)
{
	while (*sPtr != '\0')
	{
		if (islower( *sPtr ))
		{
			*sPtr = toupper(*sPtr);
		}
		
		++*sPtr;
	}
}