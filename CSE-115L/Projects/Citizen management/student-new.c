#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int id;
    char name[50];
    int class;
    int teacherID;
} Student;

typedef struct {
    int id;
    char name[50];
    char password[20];
} Teacher;

Student students[MAX];
Teacher teachers[MAX];
int studentCount = 0;
int teacherCount = 0;

// Function prototypes
void loadStudents();
void saveStudents();
void loadTeachers();
void saveTeachers();
void adminMenu();
void teacherMenu(int teacherID);
int loginAsAdmin();
int loginAsTeacher();
void addStudent();
void viewStudents();
void addTeacher();
void viewTeachers();

int main() {
    loadStudents();
    loadTeachers();

    int choice;
    while (1) {
        printf("\n==== Student Management System ====\n");
        printf("1. Admin Login\n");
        printf("2. Teacher Login\n");
        printf("3. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (loginAsAdmin()) adminMenu();
        } else if (choice == 2) {
            int teacherID = loginAsTeacher();
            if (teacherID != -1) teacherMenu(teacherID);
        } else if (choice == 3) {
            saveStudents();
            saveTeachers();
            break;
        } else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}

// ===================== File I/O ======================
void loadStudents() {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) return;
    studentCount = 0;
    while (fscanf(f, "%d %s %d %d", &students[studentCount].id, students[studentCount].name,
           &students[studentCount].class, &students[studentCount].teacherID) != EOF) {
        studentCount++;
    }
    fclose(f);
}

void saveStudents() {
    FILE *f = fopen("students.txt", "w");
    for (int i = 0; i < studentCount; i++) {
        fprintf(f, "%d %s %d %d\n", students[i].id, students[i].name,
                students[i].class, students[i].teacherID);
    }
    fclose(f);
}

void loadTeachers() {
    FILE *f = fopen("teachers.txt", "r");
    if (f == NULL) return;
    teacherCount = 0;
    while (fscanf(f, "%d %s %s", &teachers[teacherCount].id, teachers[teacherCount].name,
           teachers[teacherCount].password) != EOF) {
        teacherCount++;
    }
    fclose(f);
}

void saveTeachers() {
    FILE *f = fopen("teachers.txt", "w");
    for (int i = 0; i < teacherCount; i++) {
        fprintf(f, "%d %s %s\n", teachers[i].id, teachers[i].name, teachers[i].password);
    }
    fclose(f);
}

// ===================== Login ======================
int loginAsAdmin() {
    char user[20], pass[20];
    printf("Enter Admin Username: ");
    scanf("%s", user);
    printf("Enter Password: ");
    scanf("%s", pass);
    if (strcmp(user, "admin") == 0 && strcmp(pass, "admin") == 0) {
        printf("Login successful.\n");
        return 1;
    }
    printf("Invalid admin credentials.\n");
    return 0;
}

int loginAsTeacher() {
    int id;
    char pass[20];
    printf("Enter Teacher ID: ");
    scanf("%d", &id);
    printf("Enter Password: ");
    scanf("%s", pass);
    for (int i = 0; i < teacherCount; i++) {
        if (teachers[i].id == id && strcmp(teachers[i].password, pass) == 0) {
            printf("Login successful. Welcome, %s.\n", teachers[i].name);
            return id;
        }
    }
    printf("Invalid teacher credentials.\n");
    return -1;
}

// ===================== Admin Menu ======================
void adminMenu() {
    int choice;
    while (1) {
        printf("\n--- Admin Menu ---\n");
        printf("1. Add Teacher\n");
        printf("2. View Teachers\n");
        printf("3. Add Student\n");
        printf("4. View Students\n");
        printf("5. Back to Main Menu\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) addTeacher();
        else if (choice == 2) viewTeachers();
        else if (choice == 3) addStudent();
        else if (choice == 4) viewStudents();
        else if (choice == 5) break;
        else printf("Invalid choice.\n");
    }
}

// ===================== Teacher Menu ======================
void teacherMenu(int teacherID) {
    int choice;
    while (1) {
        printf("\n--- Teacher Menu ---\n");
        printf("1. View My Students\n");
        printf("2. Back to Main Menu\n");
        printf("Choose: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Students under Teacher ID %d:\n", teacherID);
            for (int i = 0; i < studentCount; i++) {
                if (students[i].teacherID == teacherID) {
                    printf("ID: %d, Name: %s, Class: %d\n", students[i].id,
                           students[i].name, students[i].class);
                }
            }
        } else if (choice == 2) break;
        else printf("Invalid choice.\n");
    }
}

// ===================== Core Functions ======================
void addStudent() {
    if (studentCount >= MAX) {
        printf("Student limit reached.\n");
        return;
    }
    Student s;
    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter Class: ");
    scanf("%d", &s.class);
    printf("Assign to Teacher ID: ");
    scanf("%d", &s.teacherID);
    students[studentCount++] = s;
    printf("Student added successfully.\n");
}

void viewStudents() {
    printf("\nList of All Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Class: %d, Teacher ID: %d\n",
               students[i].id, students[i].name,
               students[i].class, students[i].teacherID);
    }
}

void addTeacher() {
    if (teacherCount >= MAX) {
        printf("Teacher limit reached.\n");
        return;
    }
    Teacher t;
    printf("Enter Teacher ID: ");
    scanf("%d", &t.id);
    printf("Enter Name: ");
    scanf("%s", t.name);
    printf("Enter Password: ");
    scanf("%s", t.password);
    teachers[teacherCount++] = t;
    printf("Teacher added successfully.\n");
}

void viewTeachers() {
    printf("\nList of Teachers:\n");
    for (int i = 0; i < teacherCount; i++) {
        printf("ID: %d, Name: %s\n", teachers[i].id, teachers[i].name);
    }
}
