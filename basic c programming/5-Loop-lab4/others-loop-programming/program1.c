// Write a program in count the total odd number present in between 1 to n 
#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {   // Check if number is odd
            count++;
        }
    }

    printf("Total number of odd numbers between 1 and %d = %d\n", n, count);

    return 0;
}
