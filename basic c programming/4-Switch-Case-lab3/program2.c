/*
problem : 
Write a C program for a Food Ordering System.  
The menu contains 5 food items with fixed prices.
The user will enter the item number and the quantity.
Using switch case, calculate and display the total bill.
If the user enters an invalid choice, print "Invalid Choice".
*/

#include <stdio.h>

int main() {
    int choice, qty;
    int price = 0, total = 0;

    printf("------ FOOD ORDERING SYSTEM ------\n");
    printf("1. Burger   - Rs. 80\n");
    printf("2. Pizza    - Rs. 150\n");
    printf("3. Sandwich - Rs. 60\n");
    printf("4. Coffee   - Rs. 40\n");
    printf("5. Momos    - Rs. 90\n");
    printf("----------------------------------\n");

    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    printf("Enter quantity: ");
    scanf("%d", &qty);

    switch(choice) {
        case 1: price = 80; break;
        case 2: price = 150; break;
        case 3: price = 60; break;
        case 4: price = 40; break;
        case 5: price = 90; break;
        default:
            printf("Invalid Choice\n");
            return 0;
    }

    total = price * qty;

    printf("\n------ BILL DETAILS ------\n");
    printf("Item Price : Rs. %d\n", price);
    printf("Quantity   : %d\n", qty);
    printf("Total Bill : Rs. %d\n", total);
    printf("--------------------------\n");

    return 0;
}



