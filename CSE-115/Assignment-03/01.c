#include <stdio.h>

int main()
{
    int i,n,sum=0;
    printf("Enter n for (1+2+3+4+....+n): ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=i;
    }
    printf("the sum is: %d",sum);
    return 0;
}