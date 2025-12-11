/* Print Rhombus star pattern
 
          *********
         *********
        *********
       *********
      *********  
Alogorithm:
1. Start
2. Initialize three integer variables i, j, and k for loop control.
3. Use an outer loop that runs from 1 to n (for each row).
4. Inside the outer loop, use an inner loop to print the leading spaces for the current row.
5. Use another inner loop to print the stars for the current row.
*/

 #include <stdio.h>

int main() {
    int i, j, k;

    // outer loop
    for (i = 1; i <= 5; i++) {

        // printing spaces
        for (j = 1; j <= 5 - i; j++) {
            printf(" ");
        }

        // printing stars
        for (k = 1; k <= 5; k++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}


