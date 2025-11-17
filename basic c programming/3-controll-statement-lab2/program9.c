/*
-----------------------------------------------------------
Problem Statement:
Write a C program to determine the type of a triangle
based on the lengths of its three sides using if-else statements.

Conditions:
1. A triangle is valid if the sum of any two sides > third side.
2. If all sides are equal → Equilateral
3. If exactly two sides are equal → Isosceles
4. If all sides are different → Scalene

Example:
Input:  a=5, b=5, c=5
Output: Triangle is Equilateral
-----------------------------------------------------------
*/

#include <stdio.h>

int main() {
    int a, b, c;

    // Input three sides
    printf("Enter three sides of triangle: ");
    scanf("%d %d %d", &a, &b, &c);

    // Check validity first
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        // Valid triangle
        if (a == b && b == c)
            printf("Triangle is Equilateral.\n");
        else if (a == b || b == c || a == c)
            printf("Triangle is Isosceles.\n");
        else
            printf("Triangle is Scalene.\n");
    } else {
        // Invalid triangle
        printf("Not a valid triangle.\n");
    }

    return 0;
}
