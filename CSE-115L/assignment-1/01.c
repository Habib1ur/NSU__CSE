// Q: Write a program that computes the summation of the following series using for loop: 10000+2000+400+...+8

#include <stdio.h>

int main()
{
    int sum = 0;
    for (int i = 10000; i >= 8; i /= 5)
    {
        sum += i;
    }
    printf("total:%d", sum);
    return 0;
}