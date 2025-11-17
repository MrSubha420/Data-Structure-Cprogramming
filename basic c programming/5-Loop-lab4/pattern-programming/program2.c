/*
print triangle star pattern :
       *
      * *
     * * *
    * * * *
   * * * * *
   
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
   
 */

/* 
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
*/
