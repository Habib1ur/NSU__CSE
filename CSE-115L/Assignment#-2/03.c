#include <stdio.h> 
#include <ctype.h> 
int main()
{
    char password[50]; // declaring string to store the input string
    int i, small = 0, capital = 0, symbol = 0; 
    printf("Enter a string: "); 
    gets(password); // user input

    for (i = 0; password[i] != '\0'; i++)
    { 
        if (islower(password[i]))
        {              // checking if a lowercase letter is found
            small = 1; // setting small to 1
        }
        if (isupper(password[i]))
        {                // checking if a uppercase letter is found
            capital = 1; // seting capital to 1
        }
        if (isdigit(password[i]) || (!isalnum(password[i]) && password[i] != ' '))
        {               // checking if the character is a digit or a symbol
            symbol = 1; // seting symbol to 1
        }
    }
    if (i >= 6 && small == 1 && capital == 1 && symbol == 1)
    {                             // checking if all conditions meet the requirement
        printf("VALID PASSWORD"); 
    }
    else
    {
        printf("INVALID PASSWORD"); 
    }

    return 0; 
}
