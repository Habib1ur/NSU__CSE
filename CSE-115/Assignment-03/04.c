#include <stdio.h>
#include <math.h>

int main()
{
    int i, x, n, sum = 0, mul = 1, term, hor = 1, lob;
    printf("Enter x,n: ");
    scanf("%d %d", &x, &n);
    for (i = 1; i <= n; i++)
    {
        for (term = 0; term <= n; term++)
        {
            hor = pow(x, term);
            for (i = 1; i <= term; i++)
            {
                mul *= i;
            }
            sum += i;
        }
    }
    return 0;
}