/* Program1: Print Rectangle Star Pattern
   * * * * * *
   * * * * * *
   * * * * * *
   * * * * * *
   * * * * * *
   * * * * * *
*/

/* 
Algorithm: 
1. Start
2. Initialize two integer variables i and j for loop control.
3. Use an outer loop that runs 6 times (for each row).
4. Inside the outer loop, use an inner loop that runs 6 times (for each column).
5. In the inner loop, print a star followed by a space.
6. After the inner loop, print a newline character to move to the next row.
*/

#include <stdio.h>

int main() {
    int i, j;

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            printf(" *");
        }
        printf("\n");
    }

    return 0;
}
