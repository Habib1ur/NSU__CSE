#include <stdio.h>
#include <stdlib.h>

int main() {
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    char **employees = (char **)malloc(numEmployees * sizeof(char *));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    getchar();

    for (int i = 0; i < numEmployees; i++) {
        char temp[100];
        printf("Enter name of employee %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        employees[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        if (employees[i] == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        strcpy(employees[i], temp);
    }

    printf("\nList of Employees:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: %s", i + 1, employees[i]);
    }

    for (int i = 0; i < numEmployees; i++) {
        free(employees[i]);
    }
    free(employees);

    return 0;
}
