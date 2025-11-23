
/*
-----------------------------------------------------------
Problem Statement:
Write a C program to implement a simple calculator using 
if-else statements.

Description:
The program should take two numbers and an operator (+, -, *, /, %)
from the user and perform the corresponding arithmetic operation.

Example:
Input:
  Enter first number: 10
  Enter second number: 5
  Enter operator: *
Output:
  Result = 50
-----------------------------------------------------------
*/

#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;

    // Input two numbers and operator
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);
    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);  // space before %c to ignore newline character

    // Perform operation using if-else
    if (op == '+')
        result = num1 + num2;
    else if (op == '-')
        result = num1 - num2;
    else if (op == '*')
        result = num1 * num2;
    else if (op == '/') {
        if (num2 != 0)
            result = num1 / num2;
        else {
            printf("Error: Division by zero is not allowed.\n");
            return 0;
        }
    }
    else if (op == '%') {
        // Using integer type for modulo
        int a = (int)num1, b = (int)num2;
        if (b != 0)
            result = a % b;
        else {
            printf("Error: Modulo by zero is not allowed.\n");
            return 0;
        }
    }
    else {
        printf("Invalid operator!\n");
        return 0;
    }

    // Display result
    printf("Result = %.2f\n", result);

    return 0;
}
