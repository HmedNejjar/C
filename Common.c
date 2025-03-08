#include <stdio.h>
#include <string.h>


char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strsSize == 0) return "";

    if (strsSize == 1)  return strs[0];
       
    int minLength = strlen(strs[0]);

    for (int i = 1; i < strsSize; i++)
    {
        if (strlen(strs[i]) < minLength)
        {
            minLength = strlen(strs[i]);
        } 
    }
    char* prefix = (char*)malloc((minLength + 1) * sizeof(char));

    for (int i = 0; i < minLength; i++)
    {
        char c = strs[0][i];

        for (int j = 1; j < strsSize; j++)
        {
            if (strs[j][i] != c)
            {
                prefix[i] = '\0';
                return prefix;
            }
            prefix[i] = c; 
        }
    }
    prefix[minLength] = '\0';
    return prefix;
}
   