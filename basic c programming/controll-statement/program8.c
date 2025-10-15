#include <stdio.h>

int main() {
    int a, b, c;

    // Input three numbers
    printf("Enter first number (a): ");
    scanf("%d", &a);
    printf("Enter second number (b): ");
    scanf("%d", &b);
    printf("Enter third number (c): ");
    scanf("%d", &c);

    // Display entered numbers
    printf("\nYou entered: a=%d, b=%d, c=%d\n", a, b, c);

    // Find the largest number using nested if-else
    if (a > b) {
        if (a > c)
            printf("\nLargest number is: %d\n", a);
        else
            printf("\nLargest number is: %d\n", c);
    } else {
        if (b > c)
            printf("\nLargest number is: %d\n", b);
        else
            printf("\nLargest number is: %d\n", c);
    }

    return 0;
}
