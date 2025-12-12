/* Program 5 Print Butterfly Pattern.

   *   *
   ** **
   *****
   *****
   ** **
   *   *  

Alogorithm: 
1. Start
2. Initialize n as half of the butterfly height
3. For i from 1 to n (for upper half):
4.     Print i stars
5.     Print (2*(n-i)) spaces
6.     Print i stars
7.     Move to next line
8. For i from n down to 1 (for lower half):
9.     Print i stars
10.    Print (2*(n-i)) spaces
11.    Print i stars
12.    Move to next line
13. End
*/
#include <stdio.h>

int main() {
    int n = 3; // half of the butterfly height

    // Upper half
    for (int i = 1; i <= n; i++) {
        // Left stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Spaces
        for (int j = 1; j <= 2*(n-i); j++) {
            printf(" ");
        }
        // Right stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half
    for (int i = n; i >= 1; i--) {
        // Left stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        // Spaces
        for (int j = 1; j <= 2*(n-i); j++) {
            printf(" ");
        }
        // Right stars
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
