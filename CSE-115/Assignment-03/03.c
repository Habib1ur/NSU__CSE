#include <stdio.h>
#include<math.h>

int main()
{
    int a,x,z;
    printf("Enter the value for Base(a) and Power(x): ");
    scanf("%d%d",&a,&x);
    z=pow(a,x);
    printf("%d^%d: %d",a,x,z);
    return 0;
}