#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b)
{
   int len_a = strlen(a);
   int len_b = strlen(b);
   int max_len = (len_a > len_b ? len_a : len_b) + 1; 

   int total[max_len];

   int string1[len_a], string2[len_b];

   for (int i = 0; i < len_a; i++)
   {
    string1[i] = a[len_a - 1 -i] - '0';
   }

   for (int i = 0; i < len_b; i++)
   {
    string2[i] = b[len_b - 1 -i] - '0';
   }

   for (int i = 0; i < max_len; i++)
   {
    if (string1[i] + string2[i] != 1 && string1[i] + string2[i] != 0)
    {
        total[max_len - 1 -i] = 0;

        if (string1[i+1] == 0) string1[i+1] == 1;
        if (string2[i+1] == 0) string2[i+1] == 1;   
    }

    else total[max_len - 1 -i] = 1;    
}
   char final[max_len];  
   int j = 0;
   while( j < max_len)
   {
    final[j] = total[j] + '0';
    j++;
   }

   return final;
}