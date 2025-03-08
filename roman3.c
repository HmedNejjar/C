#include <stdio.h>
#include <string.h>

int romanToInt(char* s)
{
    typedef struct
    {
        char Roman;
        int Int;
    }RomanInt;

    RomanInt const Number[] = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D',500}, {'M', 1000}};

    int len = strlen(s);
    int total = 0;

    for (int i = 0; i < len; i++)
    {

        int value;
        for (int j = 0; j < 7; j++)
        {
            if (s[i] == Number[j].Roman)
            {
                value = Number[j].Int;
                break;
            }
        }

        if (i+1 < len && value < Number[strchr("IVXLCDM", s[i+1]) - "IVXLCDM"].Int)
        {
            total -= value;
        }
        else{
            total += value;
        }
    }

    return total;
}

int main (void)
{
    char *s = {"XI"};
    printf("%d", romanToInt(s));
}