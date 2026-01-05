/*
Problem3: Write a C program to check whether a given number is a Strong number using user-defined functions. Create a separate function find_fact() to find the factorial of a digit.

Example-
Input: 145
calculate 1! + 4! + 5! = 145
Output: 145 is a Strong number

Algorithm-

Start
Read number n
Store original number in temp
Extract each digit
Find factorial using find_fact()
Add factorial values
Use if–else to compare sum and original number
Return result
Display output
Stop
*/

#include <stdio.h>

int find_fact(int n)
{
    int fact = 1, i;
    for(i = 1; i <= n; i++)
        fact = fact * i;
    return fact;
}

int check_strong(int n)
{
    int temp = n, digit, sum = 0;

    while(temp != 0)
    {
        digit = temp % 10;
        sum = sum + find_fact(digit);
        temp = temp / 10;
    }

    if(sum == n)
        return 1;
    else
        return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(check_strong(num))
        printf("%d is a Strong number", num);
    else
        printf("%d is not a Strong number", num);

    return 0;
}

