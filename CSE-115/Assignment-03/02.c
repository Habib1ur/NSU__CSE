#include <stdio.h>

int main()
{
    int i, n, mul = 1;
    printf("Enter a positive integer for factorial: ");
    scanf("%d", &n);
    if (n > 0)
    {
        for (i = 1; i <= n; i++)
        {
            mul *= i;
        }

        printf("%d!: %d", n, mul);
    }
    else
    {
        printf("ERROR! Enter a positive integer");
    }

        return 0;
}