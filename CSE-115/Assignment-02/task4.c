#include <stdio.h>

int main() {
    int a, b, c, temp;

    printf("Enter three integers (a, b, c): ");
    scanf("%d %d %d", &a, &b, &c);

    temp = a;
    a = c;
    c = b;
    b = temp;

    printf("After cyclic swap:\n");
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
