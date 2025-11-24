/*

-------------------------------------------
        SWITCH CASE IN C 
-------------------------------------------

DEFINITION:
A switch case in C is a selection control statement that allows
you to execute one block of code from multiple choices based 
on the value of an expression.

SYNTAX:
switch(expression) {
    case value1:
        // statements
        break;

    case value2:
        // statements
        break;

    ...

    default:
        // statements

}

*/



#include <stdio.h>

int main() {
    int choice;

    printf("Enter a number between 1 to 3: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You selected ONE");
            break;

        case 2:
            printf("You selected TWO");
            break;

        case 3:
            printf("You selected THREE");
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}

