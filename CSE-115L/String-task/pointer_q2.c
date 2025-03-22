#include <stdio.h>

int oddSum(int *p, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (p[i] % 2 != 0) { 
            sum += p[i];
        }
    }
    return sum;
}

int main() {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = oddSum(arr, size);
    printf("Sum of odd elements: %d\n", sum);

    free(arr);

    return 0;
}
