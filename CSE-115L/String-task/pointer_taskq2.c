#include <stdio.h>
#include <stdlib.h>

int max(int *p, int size) {
    int maxElement = p[0]; 
    for (int i = 1; i < size; i++) {
        if (p[i] > maxElement) {
            maxElement = p[i];
        }
    }
    return maxElement;
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

    int maxElement = max(arr, size);
    printf("The largest element is: %d\n", maxElement);

    free(arr);

    return 0;
}
