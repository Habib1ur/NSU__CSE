#include <stdio.h>

int compare(char str1[], char str2[])
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0')
        return 0;
    else if (str1[i] == '\0')
        return -1;
    else
        return 1;
}

int main()
{
    char str1[100], str2[100];

    printf("Enter first string: ");
    gets(str1);

    printf("Enter second string: ");
    gets(str2);

    int result = compare(str1, str2);

    if (result == 0)
        printf("Strings are equal.\n");
    else if (result == 1)
        printf("First string is greater.\n");
    else
        printf("Second string is greater.\n");

    return 0;
}
