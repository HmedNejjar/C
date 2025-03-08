#include <stdio.h>
#include <string.h>

int romanToInt(char* s)
{
int integer[] = {1, 5 ,10, 50, 100, 500, 1000};
char roman [] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};


int total = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        int value = 0;
        for (int j = 0; j < 7; j++)
        {
            if (s[i] == roman[j])
            {
                value = integer[j];
                break;
            }
        }   

        if (i + 1 < strlen(s) && value < integer[strchr(roman, s[i+1])-roman])
        {
            total -= value;
        }
        else
        {
            total += value;
        }
    }
    return total;
}

int main (void)
{
    char *s = {"MCMXCIV"};
    printf("%d", romanToInt(s));
}