/* Print Rhombus star pattern
 
          *********
         *********
        *********
       *********
      *********    

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


