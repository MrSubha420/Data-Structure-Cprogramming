/*
Program to Convert a Binary Number into Decimal Using User-Defined Function.
 Steps to follow:
  step 1: Include necessary header files.
  step 2: Define a function to convert binary to decimal.
  step 3: In the main function, accept a binary number from the user.
  step 4: Call the conversion function and display the decimal equivalent.
*/

#include <stdio.h>

// Function to convert binary to decimal
int binaryToDecimal(long long binary)
{
   int decimal = 0, base = 1, lastDigit;

   while (binary > 0)
   {
      lastDigit = binary % 10;
      decimal = decimal + lastDigit * base;
      base = base * 2;
      binary = binary / 10;
   }

   return decimal;
}

int main()
{
   long long binary;
   int decimal;

   printf("Enter a binary number: ");
   scanf("%lld", &binary);

   decimal = binaryToDecimal(binary);

   printf("Decimal equivalent = %d\n", decimal);

   return 0;
}
