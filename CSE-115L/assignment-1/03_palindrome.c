#include <stdio.h>

int main()
{

    int num, origin, sum = 0, r;
    printf("Enter a number: ");
    scanf("%d", &num);
    origin = num;
    while (num > 0)
    {
        r = num % 10;
        sum = r + (sum * 10);
        num /= 10;
    }
    if (sum == origin)
    {
        printf("%d is a palindrome", origin);
    }
    else
    {
        printf("%d is not a palindrome", origin);
    }
    return 0;
}