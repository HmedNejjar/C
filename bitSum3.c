#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char* addBinary (char* a, char* b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = (len_a > len_b ? len_a : len_b) + 1;
    int carry = 0;

    char* total = (char*) malloc((max_len+1)*sizeof(char));
    total[max_len] = '\0';

    int i = len_a - 1, j = len_b - 1, k = max_len - 1;

    do
    {
       char bit1 = (i >=0 ? a[i--] : '0');
       char bit2 = (j >=0 ? b[j--] : '0');

       int sum = (bit1 - '0') + (bit2 - '0') + carry;
       total[k--] = (sum % 2) + '0';
       carry = sum / 2;
       
    } while (i >=0 || j >= 0 || carry != 0);
    
    return total;
}

int main ()
{
  
    char* a = (char*) malloc(MAX * sizeof(char));
    char* b = (char*) malloc(MAX * sizeof(char));
    

  printf("a : ");
  scanf("%99s", a);

  printf("b : ");
  scanf("%99s", b);


    char* c = addBinary(a, b);

    printf("\nSum : %s", c);
    free(c);
}