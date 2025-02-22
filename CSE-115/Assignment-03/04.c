#include <stdio.h>
int main() {
    int n;
    float x, sum = 1.0, term = 1.0;

    printf("Enter the value of x: ");
    scanf("%f", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        term *= x / i;
        sum += term;
    }

    printf("The sum of the series is: %.3f\n", sum);

    return 0;
}
