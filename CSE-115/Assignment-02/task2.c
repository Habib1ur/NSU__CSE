#include <stdio.h>

int main()
{
    int t;
    printf("Enter time in second: ");
    scanf("%d", &t);
    printf("\nConverted time: %dhour  ", t/3600);
    printf("%dminutes  ", t%3600/60);
    printf("%dseconds.", t%60);
    return 0;
}