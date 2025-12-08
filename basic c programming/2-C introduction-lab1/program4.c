//Find simple interest
/* formula (P * T * R) /100 
Where:

P = Principal amount

R = Rate of interest

T = Time in years

*/


#include <stdio.h>

int main() {
    float p, r, t, si;

    printf("Enter Principal Amount (P): ");
    scanf("%f", &p);

    printf("Enter Rate of Interest (R): ");
    scanf("%f", &r);

    printf("Enter Time in Years (T): ");
    scanf("%f", &t);

    si = (p * r * t) / 100;

    printf("Simple Interest = %.2f\n", si);

    return 0;
}
