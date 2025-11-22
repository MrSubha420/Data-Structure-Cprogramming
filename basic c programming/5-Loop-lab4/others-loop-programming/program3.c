/* Problem Statement:

Write a program that takes an integer as input and calculates the sum of its digits using a while loop.
For example, if the user enters 538, the program should output 16 (5 + 3 + 8).

Algorithm : 

Start
Input the number n
Initialize sum = 0
Repeat while n > 0
Extract last digit: digit = n % 10
Add digit to sum: sum = sum + digit
Remove last digit: n = n / 10
End loop
Display sum
Stop

*/

#include <stdio.h>

int main() {
    int n, sum = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (n > 0) {
        digit = n % 10;    // get last digit
        sum = sum + digit; // add to sum
        n = n / 10;        // remove last digit
    }

    printf("Sum of digits = %d\n", sum);

    return 0;
}

