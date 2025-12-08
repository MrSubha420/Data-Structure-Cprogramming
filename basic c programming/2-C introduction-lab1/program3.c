/*
-----------------------------------------------------------
Problem Statement:
Write a C program to swap two numbers without using a third variable.

Description:
The program should take two numbers as input from the user
and then interchange their values without using a temporary variable.

Hint:
You can use arithmetic operations (addition and subtraction)
or bitwise XOR operator to perform swapping.

Example:
Input:
  a = 5, b = 10
Output:
  After swapping: a = 10, b = 5
-----------------------------------------------------------
*/

#include <stdio.h>

int main() {
    int a, b;

    // Input two numbers
    printf("Enter first number (a): ");
    scanf("%d", &a);
    printf("Enter second number (b): ");
    scanf("%d", &b);

    // Display before swapping
    printf("\nBefore swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    // Swap without using third variable
    a = a + b;
    b = a - b;
    a = a - b;

    // Display after swapping
    printf("\nAfter swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
