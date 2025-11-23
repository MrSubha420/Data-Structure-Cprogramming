/* Problem Statement:
Write a program to check whether a given year is a leap year or not.

Algorithm:
Step 1: Start
Step 2: Read the year from the user
Step 3: If (year % 400 == 0) then
            It is a leap year
        Else if (year % 4 == 0 AND year % 100 != 0) then
            It is a leap year
        Else
            It is NOT a leap year
Step 4: Display the result
Step 5: Stop

  */


#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

    return 0;
}
