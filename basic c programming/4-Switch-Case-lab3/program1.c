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


Used Keywords: 
  1. switch- 
          Used to start the switch statement.
          It checks the value of an expression.
  2. case-
          Used to match specific values inside the switch block.
  3. break-
          Used to exit from the switch after a case executes.
          Prevents fall-through.
  4. default - 
           Executes when no case matches.



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

