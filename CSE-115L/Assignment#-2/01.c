#include <stdio.h>
#include <ctype.h>
int main()
{
    char str[100];
    int freq[26] = {0}, i;
    printf("Enter a string: ");
    gets(str); // user input

    for (i = 0; str[i] != '\0'; i++) // loop to iterate through the given string
    {
        if (isalpha(str[i])) // checking if character is a letter or not
        {
            char lower = tolower(str[i]); // converting letter in lowercase
            int index = lower - 'a';

            if (!freq[index]) // checking if the letter has not been freq before
            {
                freq[index] = 1; // marking letter as freq
            }
        }
    }
    printf("Unique letters in the input string:\n"); // printing for output
    int first = 1;                                   // flaging to control comma in output
    for (i = 0; i < 26; i++)                         // for for printing letter
    {
        if (freq[i]) // checking if the letter has already encounter
        {
            if (!first)
            {
                printf(", ");
            }
            printf("%c", i + 'a'); // printing unique letters
            first = 0;
        }
    }

    return 0;
}