#include <stdio.h>

// Function to calculate the common prefix length of two numbers
int findCommonPrefixLength(int num1, int num2) {
    int commonLength = 0;

    // Find the number of digits in each number
    int power1 = 1, power2 = 1;
    while (num1 / power1 >= 10) power1 *= 10;
    while (num2 / power2 >= 10) power2 *= 10;

    // Compare digits one by one from the most significant to least significant
    while (power1 > 0 && power2 > 0) {
        int digit1 = num1 / power1;
        int digit2 = num2 / power2;

        if (digit1 == digit2) {
            commonLength++;
            num1 %= power1; // Remove the most significant digit
            num2 %= power2; // Remove the most significant digit
            power1 /= 10;
            power2 /= 10;
        } else {
            break; // Stop if the digits don't match
        }
    }

    return commonLength; // Return the length of the common prefix
}

// Function to find the longest common prefix among all pairs of numbers in two arrays
int longestCommonPrefix(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    int maxPrefixLength = 0;

    for (int i = 0; i < arr1Size; i++) {
        for (int j = 0; j < arr2Size; j++) {
            int commonPrefix = findCommonPrefixLength(arr1[i], arr2[j]);
            if (commonPrefix > maxPrefixLength) {
                maxPrefixLength = commonPrefix; // Update max prefix length
            }
        }
    }

    return maxPrefixLength; // Return the maximum prefix length found
}

// Example usage
int main() {
    int arr1[] = {12345, 67890, 123};
    int arr2[] = {12367, 12567, 678};

    int result = longestCommonPrefix(arr1, 3, arr2, 3);
    printf("Longest Common Prefix Length: %d\n", result);

    return 0;
}
