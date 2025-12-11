/*
print triangle star pattern :
       *
      * *
     * * *
    * * * *
   * * * * *

Algorithm:
1. Start
2. Initialize an integer variable n to define the number of rows.
3. Use an outer loop that runs from 1 to n (for each row).
4. Inside the outer loop, calculate the number of spaces needed for the current row.
5. Use an inner loop to print the calculated number of spaces.
6. Use another inner loop to print stars followed by a space for the current row number.   
 
*/

#include <stdio.h>

int main() {
    int n = 5;
    int row, col, s;

    // outer loop
    for (row = 1; row <= n; row++) {
        int numberofspace = n - row; // calculate number of spaces

        // printing spaces
        for (s = 1; s <= numberofspace; s++) {
            printf(" ");
        }

        // printing stars
        for (col = 1; col <= row; col++) {
            printf("* ");
        }

        // next line
        printf("\n");
    }
    return 0;
}


/*
print inverted peramid triangle star pattern :

* * * * * 
 * * * * 
  * * * 
   * * 
    * 
    
Algorithm:
1. Start
2. Initialize an integer variable n to define the number of rows.
3. Use an outer loop that runs from 1 to n (for each row).
4. Inside the outer loop, calculate the number of spaces needed for the current row.
5. Use an inner loop to print the calculated number of spaces.
6. Use another inner loop to print stars followed by a space for the decreasing number of stars in each row.
*/


 #include <stdio.h>

int main() {
    int n = 5;
    int row, col;

    for (row = 1; row <= n; row++) {
        int numberofspace = row;          // calculate number of spaces
        int numberofcol = (n + 1) - row;  // calculate number of columns

        // printing stars
        for (col = 1; col <= numberofcol; col++) {
            printf("* ");
        }
        printf("\n");

        // printing spaces
        for (int s = 1; s <= numberofspace; s++) {
            printf(" ");
        }
    }

    return 0;
}

