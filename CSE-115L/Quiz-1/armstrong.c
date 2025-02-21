#include <stdio.h>

int main()
{
    // Armstrong is a number where the sum each digit cube is the same as the given number. ex: 153= 1*1*1 + 5*5*5 + 3*3*3 = 153.
    int num, arm=0, origin,d;
    printf("Enter a number: ");
    scanf("%d",&num);
    origin = num;
    while(num>0)
    {
        d=num%10;
        arm+= d*d*d;
        num/=10;

    }

    if(arm==origin)
    {
        printf("The number is an armstrong.");
    }else{
        printf("it is not an armstrong");
    }
    
    return 0;
}