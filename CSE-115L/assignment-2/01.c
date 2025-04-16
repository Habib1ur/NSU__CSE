#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[100];
    int freq[26] = {0};

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Unique letters in the input string:\n");

    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            char lower = tolower(str[i]);
            if (!freq[lower - 'a']) {
                freq[lower - 'a'] = 1;
                printf("%c, ", lower);
            }
        }
    }

    return 0;
}
