/*
program 5 : write a C program check the given number is paindrome or not.

Algorithm:
Step 1: Start
Step 2: Read the number n
Step 3: Store n in a temporary variable temp
Step 4: Initialize rev = 0
Step 5: Repeat while n > 0
    • Extract last digit: digit = n % 10
    • Build reverse: rev = rev * 10 + digit
    • Remove last digit: n = n / 10
Step 6: Compare rev with temp
    • If both are equal → Number is palindrome
    • Else → Not palindrome
Step 7: Stop

*/

#include <stdio.h>

int main() {
    int n, temp, rev = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;  // store original number

    // reverse number
    while (n > 0) {
        digit = n % 10;        // get last digit
        rev = rev * 10 + digit; // append digit
        n = n / 10;            // remove last digit
    }

    // check palindrome
    if (rev == temp) {
        printf("%d is a palindrome number.\n", temp);
    } else {
        printf("%d is not a palindrome number.\n", temp);
    }

    return 0;
}
