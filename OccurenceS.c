#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle)
{
    char* result = strstr(haystack, needle);

    if (result != NULL)
    {
        return result - haystack;
    }
    else return -1;
}