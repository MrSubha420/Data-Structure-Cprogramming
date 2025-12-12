/*
Program6:  Write a C program check the given number is prime or not prime.

Algorithm:
Step 1: Start
Step 2: Read the number n
Step 3: If n <= 1, then it is not prime
Step 4: Set a counter count = 0
Step 5: For each i from 2 to n-1:
    • If n % i == 0, set count = 1 and break
Step 6: If count == 0, number is prime
    Else number is not prime
Step 7: Stop
*/
//If we given logic n-1 then time complexity will be O(n).
//to oftimize If we given logic n/2 then time complexity will be O(n/2). 
#include <stdio.h>

int main() {
    int n, i, flag = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    // numbers less than or equal to 1 are not prime
    if (n <= 1) {
        printf("%d is not a prime number.\n", n);
        return 0;
    }

    // check divisibility
    for (i = 2; i <= n-1; i++) {
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }

    // result
    if (flag == 0)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}
