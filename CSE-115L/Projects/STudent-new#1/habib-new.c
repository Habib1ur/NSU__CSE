#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// ---------------- STRUCTURES ----------------
typedef struct {
    int id;
    char name[50];
    int class;
} Student;

typedef struct {
    char username[50];
    char password[50];
} Teacher;

// ---------------- GLOBALS ----------------
Student students[MAX];
int studentCount = 0;

// ---------------- FUNCTION PROTOTYPES ----------------
void teacherRegister();
int teacherLogin();
void loadStudents();
void saveStudents();
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

// ---------------- MAIN FUNCTION ----------------
int main() {
    loadStudents();
    int option;
    while (1) {
        printf("\n==== Student Management ====\n");
        printf("1. Register (Teacher)\n");
        printf("2. Login (Teacher)\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &option);

        if (option == 1) {
            teacherRegister();
        } else if (option == 2) {
            if (teacherLogin()) {
                int choice;
                while (1) {
                    printf("\n--- Menu ---\n");
                    printf("1. Add Student\n");
                    printf("2. View Students\n");
                    printf("3. Search Student\n");
                    printf("4. Update Student\n");
                    printf("5. Delete Student\n");
                    printf("6. Logout\n");
                    printf("Choose: ");
                    scanf("%d", &choice);

                    if (choice == 1) addStudent();
                    else if (choice == 2) viewStudents();
                    else if (choice == 3) searchStudent();
                    else if (choice == 4) updateStudent();
                    else if (choice == 5) deleteStudent();
                    else if (choice == 6) break;
                    else printf("Invalid option.\n");
                }
            }
        } else if (option == 3) {
            saveStudents();
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

// ---------------- TEACHER AUTH ----------------
void teacherRegister() {
    FILE *f = fopen("teachers.txt", "a");
    Teacher t;
    printf("Create Username: ");
    scanf("%s", t.username);
    printf("Create Password: ");
    scanf("%s", t.password);
    fprintf(f, "%s %s\n", t.username, t.password);
    fclose(f);
    printf("Teacher registered.\n");
}

int teacherLogin() {
    FILE *f = fopen("teachers.txt", "r");
    char uname[50], pass[50];
    char u[50], p[50];
    int found = 0;

    printf("Username: ");
    scanf("%s", uname);
    printf("Password: ");
    scanf("%s", pass);

    while (fscanf(f, "%s %s", u, p) != EOF) {
        if (strcmp(uname, u) == 0 && strcmp(pass, p) == 0) {
            found = 1;
            break;
        }
    }

    fclose(f);
    if (found) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Invalid credentials.\n");
        return 0;
    }
}

// ---------------- FILE FUNCTIONS ----------------
void loadStudents() {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) return;
    studentCount = 0;
    while (fscanf(f, "%d %s %d", &students[studentCount].id,
                  students[studentCount].name, &students[studentCount].class) != EOF) {
        studentCount++;
    }
    fclose(f);
}

void saveStudents() {
    FILE *f = fopen("students.txt", "w");
    for (int i = 0; i < studentCount; i++) {
        fprintf(f, "%d %s %d\n", students[i].id, students[i].name, students[i].class);
    }
    fclose(f);
}

// ---------------- STUDENT FUNCTIONS ----------------
void addStudent() {
    if (studentCount >= MAX) {
        printf("Student limit reached.\n");
        return;
    }
    Student *s = &students[studentCount];
    printf("Enter ID: ");
    scanf("%d", &s->id);
    printf("Enter Name: ");
    scanf("%s", s->name);
    printf("Enter Class: ");
    scanf("%d", &s->class);
    studentCount++;
    printf("Student added.\n");
}

void viewStudents() {
    printf("\n-- Student List --\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d | Name: %s | Class: %d\n",
               students[i].id, students[i].name, students[i].class);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Found - Name: %s, Class: %d\n", students[i].name, students[i].class);
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    int id;
    printf("Enter ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("New Name: ");
            scanf("%s", students[i].name);
            printf("New Class: ");
            scanf("%d", &students[i].class);
            printf("Student updated.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student not found.\n");
}
