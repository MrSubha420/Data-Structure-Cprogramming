/*
-----------------------------------------------------------
Problem Statement:
Write a C program to calculate an employee’s total salary 
based on performance rating and basic salary.

Rules:
-----------------------------------------------------------
Performance Rating | Bonus Percentage
-------------------|-----------------
Above 90           | 25%
80 – 90            | 20%
70 – 79            | 15%
60 – 69            | 10%
Below 60           | 0%

If basic salary < 10000 → Add ₹500 allowance.

Formula:
  total_salary = basic + (bonus% of basic) + allowance
-----------------------------------------------------------
*/

/*
  Algorithm: Salary Calculation Based on Performance

Start
Input the employee’s
Basic salary (basic)
Performance rating (rating)
Initialize
bonus = 0
allowance = 0
Calculate Bonus Based on Rating:
If rating > 90 → bonus = 25% of basic
Else if rating ≥ 80 → bonus = 20% of basic
Else if rating ≥ 70 → bonus = 15% of basic
Else if rating ≥ 60 → bonus = 10% of basic
Else → bonus = 0
Check Allowance Condition:
If basic < 10000 → allowance = 500
Otherwise → allowance = 0
Calculate Total Salary:
total_salary = basic + bonus + allowance
Display
Basic salary
Bonus
Allowance
Total salary
Stop
*/

#include <stdio.h>

int main() {
    float basic, rating, bonus, allowance = 0, total_salary;

    // Input from user
    printf("Enter Basic Salary: ");
    scanf("%f", &basic);
    printf("Enter Performance Rating (0-100): ");
    scanf("%f", &rating);

    // Determine bonus based on performance
    if (rating > 90)
        bonus = basic * 0.25;
    else if (rating >= 80)
        bonus = basic * 0.20;
    else if (rating >= 70)
        bonus = basic * 0.15;
    else if (rating >= 60)
        bonus = basic * 0.10;
    else
        bonus = 0;

    // Check for allowance
    if (basic < 10000)
        allowance = 500;

    // Calculate total salary
    total_salary = basic + bonus + allowance;

    // Display details
    printf("\n---------- Salary Breakdown ----------\n");
    printf("Basic Salary     : ₹%.2f\n", basic);
    printf("Performance Bonus: ₹%.2f\n", bonus);
    printf("Allowance        : ₹%.2f\n", allowance);
    printf("-------------------------------------\n");
    printf("Total Salary     : ₹%.2f\n", total_salary);

    return 0;
}
