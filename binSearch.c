#include <stdio.h>
#include <string.h>
#include <ctype.h>

int binSearch(char tar, char* arr);

int main (void)
{
    char list[26];
    char target;
    for (int i = 0; i < 26; i++)
    {
        list[i] = i + 'A';   
    }

    printf("Letter? : ");
    scanf("%c", &target);

    binSearch(target, list);
    
}

int binSearch(char tar, char* arr)
{
    int low = 0, high = strlen(arr) - 1;
    int mid;
do
{
    mid = (low + high) / 2;

    if((arr[mid] == tar) || (arr[mid] == tolower(tar))) 
    {   
        printf("target at position : %d", mid+1);
        return mid+1;
    }

   else if(arr[mid] < tar) low = mid + 1;
   else if (arr[mid] > tar) high = mid - 1;

   else 
   {
    printf("Non Existant");
    return -1;
   }
} while (low <= high);

}