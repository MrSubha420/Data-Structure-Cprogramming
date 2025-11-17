#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    switch(num1 > num2 && num1 > num3) {
        case 1:
            // This block executes if num1 is greater than both num2 and num3
            printf("%d is the largest number.\n", num1);
            break;
        case 0:
            // This block executes if num1 is NOT the largest, so we compare num2 and num3
            switch(num2 > num3) {
                case 1:
                    // This block executes if num2 is greater than num3
                    printf("%d is the largest number.\n", num2);
                    break;
                case 0:
                    // This block executes if num2 is NOT greater than num3.
                    // This means either num3 is largest or all are equal.
                    switch(num1 == num2 && num2 == num3) {
                        case 1:
                            printf("All numbers are equal.\n");
                            break;
                        case 0:
                            printf("%d is the largest number.\n", num3);
                            break;
                    }
                    break;
            }
            break;
    }

    return 0;
}
