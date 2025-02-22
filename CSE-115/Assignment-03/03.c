#include <stdio.h>

int main() {
    int a, x;
    long result = 1;

    printf("Enter the base value a: ");
    scanf("%d", &a);
    printf("Enter the exponent value x: ");
    scanf("%d", &x);

    for (int i = 0; i < x; ++i) {
        result *= a;
    }

    printf("%d ^ %d is: %ld\n", a, x, result);

    return 0;
}
