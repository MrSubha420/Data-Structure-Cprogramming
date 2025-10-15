/*
-----------------------------------------------------------
Problem Statement:
Write a C program to swap two numbers using a third variable.

Description:
The program should take two numbers as input from the user
and then interchange their values using a temporary variable.

Example:
Input:
  a = 5, b = 10
Output:
  After swapping: a = 10, b = 5
-----------------------------------------------------------
*/

#include <stdio.h>

int main() {
    int a, b, temp;

    // Input two numbers
    printf("Enter first number (a): ");
    scanf("%d", &a);
    printf("Enter second number (b): ");
    scanf("%d", &b);

    // Display before swapping
    printf("\nBefore swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    // Swap using third variable
    temp = a;
    a = b;
    b = temp;

    // Display after swapping
    printf("\nAfter swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
