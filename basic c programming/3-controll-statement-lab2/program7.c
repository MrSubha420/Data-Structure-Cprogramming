/*
-----------------------------------------------------------
Problem Statement:
Write a C program to implement student grade calculation
based on the following table.

Grade Criteria:
-----------------------------------------------------------
EX  - Marks > 90
O   - Marks between 80 and 90
A   - Marks between 70 and 80
B   - Marks between 60 and 70
C   - Marks between 50 and 60
FAIL - Marks < 50
-----------------------------------------------------------

Input:
- The program should take CGPA as input from the user.

Process:
- Calculate marks using the formula:
      marks = (10 - 0.75) * cgpa

Output:
- Display the calculated marks and corresponding grade.
-----------------------------------------------------------
*/

#include <stdio.h>

int main() {
    float cgpa, marks;

    // Input CGPA from user
    printf("Enter your CGPA: ");
    scanf("%f", &cgpa);

    // Calculate marks using the given formula
    marks = (10 - 0.75) * cgpa;

    // Display calculated marks
    printf("Calculated Marks: %.2f\n", marks);

    // Determine grade based on marks
    if (marks > 90)
        printf("Grade: EX\n");
    else if (marks >= 80 && marks <= 90)
        printf("Grade: O\n");
    else if (marks >= 70 && marks < 80)
        printf("Grade: A\n");
    else if (marks >= 60 && marks < 70)
        printf("Grade: B\n");
    else if (marks >= 50 && marks < 60)
        printf("Grade: C\n");
    else
        printf("Grade: FAIL\n");

    return 0;
}
