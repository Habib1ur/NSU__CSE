#include <stdio.h>
int main()
{
    char str[100];
    int i, j;
    printf("Input a string: "); 
    gets(str); // user input
    for (i = 0; str[i] != '\0'; i++)
    { 
        for (j = i + 1; str[j] != '\0'; j++)
        { 
            if (str[i] == str[j]) // checking if there is any repeatation of characters in the given string
            {
                printf("The first repeated character in %s is:%c", str, str[i]); 
                return 0; 
            }
        }
    }
    printf("This string (%s) contains no repeated character.", str); // Print if no repeat character found

    return 0;
}