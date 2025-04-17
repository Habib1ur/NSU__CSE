#include <stdio.h> 
int main()
{
    char str[100]; // declare a string
    int i; 
    printf("Input the string:"); // asking input from user
    gets(str); // taking input from user
    printf("The first words of the string:"); // printing for output
    for (i = 0; str[i] != ' ' && str[i] != '\0'; i++)
    {                         
        printf("%c", str[i]); // print all letters of first word
    }

    return 0;
}