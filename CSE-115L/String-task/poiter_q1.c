#include <stdio.h>

void swap(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

int main() {
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    swap(&a, &b, &c);

    printf("After swapping: a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
