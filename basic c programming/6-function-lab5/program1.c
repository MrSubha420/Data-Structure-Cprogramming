/*program1. Write a program implement a simple calculator using the given function 
     - plus(): add two number 
     - minus(): substract two number
     - devide(): devide the number 
     - multiply() : multiplication of two number
     - modulo()  : find reminder
     - power() : find a^b = ?#include 
*/
#include<stdio.h>
// function to add two numbers
int plus(int a, int b)
{
    return a + b;
}

// function to subtract two numbers
int minus(int a, int b)
{
    return a - b;
}

// function to multiply two numbers
int multiply(int a, int b)
{
    return a * b;
}

// function to divide two numbers
float divide(int a, int b)
{
    return (float)a / b;
}

// function to find remainder
int modulo(int a, int b)
{
    return a % b;
}

// function to find power a^b
double power(int a, int b)
{
    return a^b;
}

int main()
{
    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulo\n");
    printf("6. Power (a^b)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Result = %d", plus(a, b));
            break;

        case 2:
            printf("Result = %d", minus(a, b));
            break;

        case 3:
            printf("Result = %d", multiply(a, b));
            break;

        case 4:
            if (b != 0)
                printf("Result = %.2f", divide(a, b));
            else
                printf("Division by zero not allowed");
            break;

        case 5:
            printf("Result = %d", modulo(a, b));
            break;

        case 6:
            printf("Result = %.2lf", power(a, b));
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}
