#include <stdio.h>

int main()
{
    char x;
    printf("Input an Alphabet: ");
    scanf("%c", &x);
    if (x>='A' && x<='Z' || x>='a' && x<='z' )
    {
        printf("Next character is: %c",x+1);
    }else{
        printf("ERORR! Please input a alphabet.");
    }
    
    return 0;
}