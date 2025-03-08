#include <stdio.h>


int isPalindrome(long x)
{
    if (x < 0)
    {
        return -1;
    }

    long reverse = 0, original = x;
    while ( x > 0 )
    {
        long digit  = x % 10;

        reverse = reverse * 10 + digit;

        x /= 10;
    }


    if (original == reverse) printf("%ld is a palindrome.\n", original);
    

    else printf("%ld is a not palindrome.\n", original);
}


int main (void)
{
    long num;

    printf("Check for number: ");
    scanf("%ld", &num);

    isPalindrome(num);
}