#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int hasLower = 0, hasUpper = 0, hasDigitOrSymbol = 0;

    printf("Enter string: ");
    fgets(password, sizeof(password), stdin);

    if (strlen(password) < 6) {
        printf("INVALID PASSWORD\n");
        return 0;
    }

    for (int i = 0; password[i]; i++) {
        if (islower(password[i])) hasLower = 1;
        else if (isupper(password[i])) hasUpper = 1;
        else if (isdigit(password[i]) || ispunct(password[i])) hasDigitOrSymbol = 1;
    }

    if (hasLower && hasUpper && hasDigitOrSymbol)
        printf("VALID PASSWORD\n");
    else
        printf("INVALID PASSWORD\n");

    return 0;
}
