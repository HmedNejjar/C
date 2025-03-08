#include <stdio.h>
#include <string.h>

int romanToInt(char* s)
{
    typedef struct num
    {
        char roman;
        int integer;
    } number;

    number nums[] = {{'I',1},{'V',5},{'X', 10},{'L', 50},{'C',100},{'D', 500},{'M',1000}};

    int len = strlen(s);
    int total = 0;

    for (int i = 0; i < len; i++)
    {
        int value = 0;

        for (int j = 0; j < 7; j++)
        {
            if (s[i] == nums[j].roman)
            {
                value = nums[j].integer;
                break;
            }
        }

        if (i+1 < len && value < nums[strchr("IVXLCDM", s[i + 1]) - "IVXLCDM"].integer)
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
    char *s = {"LVIII"};
    printf("%d", romanToInt(s));
}