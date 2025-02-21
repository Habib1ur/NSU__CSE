#include <stdio.h>

int main() {
    int n; 
    
    
    printf("Enter a value for N pattern: "); 
    scanf("%d", &n); 

    if(n)
    // Loop for N pattern
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (j == 0 || j == n - 1 || i == j)
                printf("%d ", i + j + 2);
            else
                printf("  "); 
        }
        printf("\n"); 
    }

    return 0;
}
