/*Problem2:Write a C program to create a user-defined function named find_fact() to find the factorial of a given number.
Note: dont use recursion.
Example -
    Input: 5
    Output: 120

Algorithm - 
   Start
   Read a number n
   Call function find_fact(n)
   Initialize fact = 1
   Use a for loop from 1 to n
   Multiply fact with loop variable
   Return factorial value
   Display the result
   Stop
*/

#include <stdio.h>

long find_fact(int n)
{
    long fact = 1;
    int i;

    for(i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial = %ld", find_fact(num));
    return 0;
}
