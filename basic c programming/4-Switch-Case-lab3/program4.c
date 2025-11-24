/*

Problem Statement:
Write a C program to convert temperature between Celsius and Fahrenheit.
The user will choose:
1) Celsius to Fahrenheit
2) Fahrenheit to Celsius
The program should convert the value based on the selected option.

Formula:
Celsius to Fahrenheit: F = (C × 9/5) + 32
Fahrenheit to Celsius: C = (F − 32) × 5/9

*/

#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    int choice;

    printf("===== Temperature Converter =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("Temperature in Celsius: %.2f\n", celsius);
            break;

        default:
            printf("Invalid choice! Please run the program again.\n");
    }

    return 0;
}


