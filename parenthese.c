#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s)
{
    if (strlen(s) % 2 != 0) return false;

    char* r = (char*) malloc(strlen(s) * sizeof(char)); // Allocate correct size
    int index = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        switch (s[i])
        {
            case '(':
                r[index++] = ')';
                break;
            case '{':
                r[index++] = '}';
                break;
            case '[':
                r[index++] = ']';
                break;
            default:
                if (index == 0 || r[--index] != s[i]) { // Check matching closing brackets
                    free(r);
                    return false;
                }
                break;
        }
    }
    
    bool valid = (index == 0); // If index is 0, all brackets matched
    free(r);
    return valid;
}

int main() {
    char test[100];

    printf("Type in: ");
    fgets(test, 100, stdin);
    
    
    printf("Test : %s\n", isValid(test) ? "Valid" : "Invalid");
    

    return 0;
}

