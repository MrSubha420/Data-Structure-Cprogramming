/*
Write a c program to calculate the monthly electricity bill of a consumer.
Requirements:
         - Accept consumer name and number of units consumed.
         - Use the following tariff:
              First 100 units → ₹6/unit
              Next 100 units → ₹8/unit
              Remaining units → ₹10/unit
         -Add a fixed meter charge of ₹50.
         - Display a formatted bill summary.
Steps to follow:
   step 1: Include necessary header files.
   step 2: Define a function to calculateBill the total bill based on units consumed.
   step 3: In the main function, accept consumer name and units consumed.
   step 4: Call the bill calculation function and display the formatted bill summary.
*/
#include <stdio.h>

// Function to calculate total electricity bill
float calculateBill(int units)
{
   float bill = 0;

   if (units <= 100)
   {
      bill = units * 6.0;
   }
   else if (units <= 200)
   {
      bill = (100 * 6) + ((units - 100) * 8);
   }
   else
   {
      bill = (100 * 6) + (100 * 8) + ((units - 200) * 10);
   }

   bill = bill + 50; // Fixed meter charge
   return bill;
}

int main()
{
   char name[50];
   int units;
   float totalBill;

   printf("Enter Consumer Name: ");
   scanf("%s", name);

   printf("Enter Units Consumed: ");
   scanf("%d", &units);

   totalBill = calculateBill(units);

   printf("\n----- Electricity Bill Summary -----\n");
   printf("Consumer Name   : %s\n", name);
   printf("Units Consumed  : %d\n", units);
   printf("Total Bill      : Rs. %.2f\n", totalBill);
   printf("-----------------------------------\n");

   return 0;
}
