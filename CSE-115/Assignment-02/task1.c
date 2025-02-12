#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    printf("Enter x value: ");
    scanf("%lf", &x);
    float sum = pow(3, x) + (x * x) - (12 * x) - 12;
    if (sum >= 0)
    {
        printf("The answer is : %.2f", sqrt(sum));
    }
    else
    {
        printf("Math error!\nnegative value can not be inside root");
    }

    return 0;
}