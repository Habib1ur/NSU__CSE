#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int found = 0;

    printf("Input a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ' || str[i] == '\n') continue;

        for (int j = i + 1; str[j]; j++) {
            if (str[i] == str[j]) {
                printf("The first repeated character in %s is: %c\n", str, str[i]);
                found = 1;
                break;
            }
        }

        if (found) break;
    }

    if (!found) {
        printf("This string (%s) contains no repeated character.\n", str);
    }

    return 0;
}
