/*

Program to print a diamond pattern of stars
  Example for n=5:
      *
     ***
    *****
   *******
  *********
   *******
    *****
     ***
      *
Algorithm:
1. Start
2. Initialize an integer variable n to define the number of rows for the upper half of the diamond.
3. Use an outer loop that runs from 1 to n (for each row of the upper half).
4. Inside the outer loop, use an inner loop to print the leading spaces for the current row.
5. Use another inner loop to print the stars for the current row.
6. After completing the upper half, use another outer loop that runs from n-1 down to 1 (for each row of the lower half).
7. Inside this outer loop, repeat the process of printing leading spaces and stars for the lower half.
*/#include <stdio.h>

int main() {
    int n, row, space, star;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    // Upper half
    for(row = 1; row <= n; row++) {
        // Print spaces
        for(space = 1; space <= n - row; space++) {
            printf(" ");
        }
        // Print stars
        for(star = 1; star <= 2 * row - 1; star++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower half
    for(row = n - 1; row >= 1; row--) {
        // Print spaces
        for(space = 1; space <= n - row; space++) {
            printf(" ");
        }
        // Print stars
        for(star = 1; star <= 2 * row - 1; star++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
