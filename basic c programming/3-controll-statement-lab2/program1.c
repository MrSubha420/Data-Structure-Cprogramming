/*

Write a C program to input age and check in one message whether the person is a valid voter (age ≥ 18) or not.

*/


#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("You are a valid voter.\n");
    } else {
        printf("You are NOT a valid voter.\n");
    }

    return 0;
}
