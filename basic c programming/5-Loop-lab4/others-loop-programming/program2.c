// count prime number present 1 to n 
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
