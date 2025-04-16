#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Input the string: ");
    fgets(str, sizeof(str), stdin);

    printf("The first word of the string: ");
    for (int i = 0; str[i] && str[i] != ' ' && str[i] != '\n'; i++) {
        printf("%c", str[i]);
    }

    return 0;
}
