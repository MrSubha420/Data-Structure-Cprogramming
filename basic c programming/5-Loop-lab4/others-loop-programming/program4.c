/*Problem Statement: 

Write a C program to input an integer and print its reverse.
Example: If the input is 1234, the output should be 4321.

Algorithm: 

Start
Input the number n
Initialize rev = 0
Repeat while n > 0:
Extract last digit: digit = n % 10
Build reverse number: rev = rev * 10 + digit
Remove last digit: n = n / 10
Print rev
Stop
*/

#include <stdio.h>

int main() {
    int n, rev = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10;         // get last digit
        rev = rev * 10 + digit; // form reverse number
        n = n / 10;             // remove last digit
    }

    printf("Reversed number = %d\n", rev);

    return 0;
}

