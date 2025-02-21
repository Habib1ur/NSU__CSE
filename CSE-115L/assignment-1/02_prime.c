#include <stdio.h>

int main()
{
    
    int num,divisible=0,i;  
    printf("Enter a number: "); 
    scanf("%d",&num); 
    for ( i = 1; i <=num; i++) 
    {
        if(num%i==0){
            divisible++; 
        }
    }

    
    if(divisible==2) 
    {
        printf("%d is a prime Number",num); 
    }else{
        printf("%d is not a prime Number",num); 
    }
    
    
    return 0;
}