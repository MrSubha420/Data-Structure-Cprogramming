/* 
Algorithm:
Start with first two Fibonacci numbers:
a = 0, b = 1

Print a

Compute next number as next = a + b

Update a and b for the next iteration

Repeat using a loop
*/

#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next;

    printf("Enter how many terms you want: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }

    return 0;
}
/* 

Example Input/Output:
Input: Enter how many terms you want: 7
Output: Fibonacci Series: 0 1 1 2 3 5 8 
*/

