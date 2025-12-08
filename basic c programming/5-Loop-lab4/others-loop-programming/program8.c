/*
Problem Statement: 

Write a C program to count how many prime numbers exist between 1 and a given number n.
A prime number is a number greater than 1 that has no divisors other than 1 and itself.

Algorithm: 

Start
Input the value of n
Set count = 0
For each number i from 2 to n:
Assume isPrime = 1
Check for every number j from 2 to √i:
If i % j == 0, set isPrime = 0 and break
If isPrime == 1, increment count
Print the value of count
Stop

*/


#include <stdio.h>

int main() {
    int n, i, j, count = 0, isPrime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 2; i <= n; i++) {  
        isPrime = 1;  // assume number is prime

        for (j = 2; j * j <= i; j++) {  // check divisors
            if (i % j == 0) {
                isPrime = 0;  // not prime
                break;
            }
        }

        if (isPrime == 1) {
            count++;  // count prime number
        }
    }

    

    printf("Total prime numbers between 1 and %d = %d\n", n, count);

    return 0;
}
