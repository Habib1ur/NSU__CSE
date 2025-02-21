#include <stdio.h>

int main()
{
    int d,y,w;
    printf("Enter days: ");
    scanf("%d",&d);
    if(d>=0)
    {
        y=d/365;
        w=d%365/7;
        d=d%365%7;
        printf("Years: %d week: %d day: %d",y,w,d);
    }else{
        printf("please enter valid value!");
    }
    return 0;
}