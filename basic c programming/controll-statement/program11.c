/*
-----------------------------------------------------------
Problem Statement:
Create a mini-banking program with login system 

Steps:
1. Ask for username and password.
2. If both match (username = "subhadip", password = "12345"),
   then allow banking operations using switch-case:
   - Deposit Money
   - Withdraw Money
   - Check Balance
   - Exit
-----------------------------------------------------------

Author: Subhadip Manna
-----------------------------------------------------------
*/

#include <stdio.h>

int main() {
    char u1, u2, u3, u4, u5, u6, u7, u8;   // username letters
    char p1, p2, p3, p4, p5;               // password digits
    int choice;
    float balance = 0.0, amount;

    printf("\n------------------------------------------");
    printf("\n       Welcome to Secure Banking System   ");
    printf("\n------------------------------------------");

    // Taking username
    printf("\n\nEnter Username (subhadip): ");
    scanf(" %c%c%c%c%c%c%c%c", &u1, &u2, &u3, &u4, &u5, &u6, &u7, &u8);

    // Taking password
    printf("Enter Password (12345): ");
    scanf(" %c%c%c%c%c", &p1, &p2, &p3, &p4, &p5);

    // Check username and password (no loops or arrays)
    if (u1=='s' && u2=='u' && u3=='b' && u4=='h' && 
        u5=='a' && u6=='d' && u7=='i' && u8=='p' &&
        p1=='1' && p2=='2' && p3=='3' && p4=='4' && p5=='5') {

        printf("\n Login Successful! Welcome, subhadip!\n");

        // Display menu
        printf("\n------------------------------------------");
        printf("\nSelect an operation:\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform selected operation using switch-case
        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance = balance + amount;
                    printf(" Successfully deposited ₹%.2f\n", amount);
                    printf(" New Balance: ₹%.2f\n", balance);
                } else {
                    printf(" Invalid deposit amount!\n");
                }
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= 0) {
                    printf(" Invalid withdrawal amount!\n");
                } else if (amount > balance) {
                    printf("Insufficient balance! Available: ₹%.2f\n", balance);
                } else {
                    balance = balance - amount;
                    printf("Successfully withdrawn ₹%.2f\n", amount);
                    printf(" New Balance: ₹%.2f\n", balance);
                }
                break;

            case 3:
                printf(" Current Balance: ₹%.2f\n", balance);
                break;

            case 4:
                printf("\nThank you for using Secure Banking System. Goodbye!\n");
                break;

            default:
                printf(" Invalid choice! Please select 1–4.\n");
        }
    } 
    else {
        printf("\n Login Failed! Invalid username or password.\n");
    }

    return 0;
}

