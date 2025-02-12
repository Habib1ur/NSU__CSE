#include <stdio.h>
#include <math.h>
int main()
{
    float x, sum;
    printf("Enter x value: ");
    scanf("%f", &x);
    sum = pow(x, 3) + pow(x, 2) - (12 * x) - 12;
    if (sum >= 0)
    {
        float result = sqrt(sum);
        printf("The answer is : %.2f", result);
    }
    else
    {
        printf("Math error!\nnegative value can not be inside root");
    }

    return 0;
}