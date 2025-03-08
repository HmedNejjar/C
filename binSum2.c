#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int max_len = (len_a > len_b ? len_a : len_b);  

    char* result = (char*)malloc((max_len + 1) * sizeof(char));   

    int carry = 0, i = len_a - 1, j = len_b - 1, k = max_len - 1;
    result[max_len] = '\0';  

    while (i >= 0 || j >= 0 || carry) {
        int bit1 = (i >= 0) ? a[i--] - '0' : 0;  
        int bit2 = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        result[k--] = (sum % 2) + '0';  
        carry = sum / 2;  
    }

    if (result[0] == '0') {
        memmove(result, result + 1, max_len); 
    }

    return result;
}

