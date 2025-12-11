/*

*/

#include <stdio.h>

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
            printf(" * ");
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
            printf(" * ");
        }
        printf("\n");
    }

    return 0;
}
