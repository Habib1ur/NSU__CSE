#include <stdio.h>

int main()
{
    char x;
    printf("Input an Alphabet: ");
    scanf("%c", &x);
    if (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z')
    {
        if (x == 'z')
        {
            printf("Next character is: a");
        }
        else if (x == 'Z')
        {
            printf("Next character is: A");
        }
        else
        {
            printf("Next character is: %c", x + 1);
        }
    }
    else
    {
        printf("ERORR! Please input a alphabet.");
    }

    return 0;
}