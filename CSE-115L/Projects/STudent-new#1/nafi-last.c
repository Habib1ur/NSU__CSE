#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_USERS 50

typedef struct {
    int id;
    char name[50];
    int attendance;
    float examMarks;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// ---------------- User Auth ----------------
int loginUser();
void registerUser();

// ---------------- Student File Handling ----------------
void loadFromFile() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) return;

    char line[100];
    fgets(line, sizeof(line), fp); // Skip header
    fgets(line, sizeof(line), fp); // Skip underline

    while (fscanf(fp, "%d %49s %d %f",
                  &students[studentCount].id,
                  students[studentCount].name,
                  &students[studentCount].attendance,
                  &students[studentCount].examMarks) == 4) {
        studentCount++;
    }

    fclose(fp);
}

void saveToFile() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error saving data!\n");
        return;
    }

    fprintf(fp, "ID   Name                 Attendance Exam Marks\n");
    fprintf(fp, "-----------------------------------------------\n");

    for (int i = 0; i < studentCount; i++) {
        fprintf(fp, "%-4d %-20s %-10d %.2f\n",
                students[i].id,
                students[i].name,
                students[i].attendance,
                students[i].examMarks);
    }

    fclose(fp);
}

// ---------------- Student Management ----------------
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    Student *s = &students[studentCount];
    printf("Enter Student ID: ");
    scanf("%d", &s->id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == s->id) {
            printf("A student with this ID already exists!\n");
            return;
        }
    }

    getchar(); // Clear newline
    printf("Enter Student Name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = 0;

    printf("Enter Attendance: ");
    scanf("%d", &s->attendance);

    printf("Enter Exam Marks: ");
    scanf("%f", &s->examMarks);

    studentCount++;
    saveToFile();
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students available!\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID   Name                 Attendance Exam Marks\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-4d %-20s %-10d %.2f\n",
               students[i].id,
               students[i].name,
               students[i].attendance,
               students[i].examMarks);
    }
}

void updateAttendance() {
    int id, found = 0;
    printf("Enter Student ID to update attendance: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter new attendance count: ");
            scanf("%d", &students[i].attendance);
            saveToFile();
            printf("Attendance updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found!\n");
}

void updateExamMarks() {
    int id, found = 0;
    printf("Enter Student ID to update exam marks: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter new exam marks: ");
            scanf("%f", &students[i].examMarks);
            saveToFile();
            printf("Exam marks updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found!\n");
}

void generateReports() {
    if (studentCount == 0) {
        printf("No students available to generate reports!\n");
        return;
    }

    float total = 0;
    printf("\nStudent Reports:\n");
    printf("ID   Name                 Attendance Exam Marks\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-4d %-20s %-10d %.2f\n",
               students[i].id,
               students[i].name,
               students[i].attendance,
               students[i].examMarks);
        total += students[i].examMarks;
    }
    printf("\nAverage Exam Marks: %.2f\n", total / studentCount);
}

void deleteStudent() {
    int id, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveToFile();
            printf("Student with ID %d deleted.\n", id);
            break;
        }
    }

    if (!found) printf("Student not found.\n");
}

// ---------------- Menu ----------------
void menu() {
    int choice;
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Attendance\n");
        printf("4. Update Exam Marks\n");
        printf("5. Generate Reports\n");
        printf("6. Delete Student\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: updateAttendance(); break;
            case 4: updateExamMarks(); break;
            case 5: generateReports(); break;
            case 6: deleteStudent(); break;
            case 7: printf("Exiting system...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 7);
}

// ---------------- Authentication ----------------
void registerUser() {
    char username[30], password[30];
    printf("Register New Account\n");
    printf("Enter Username: ");
    scanf("%s", username);
    printf("Enter Password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error registering user.\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);
    fclose(fp);
    printf("User registered successfully!\n");
}

int loginUser() {
    char username[30], password[30], fileUser[30], filePass[30];
    printf("Login to System\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("No users registered yet.\n");
        return 0;
    }

    while (fscanf(fp, "%s %s", fileUser, filePass) == 2) {
        if (strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// ---------------- Main ----------------
int main() {
    int choice;
    printf("Welcome to Student Management System\n");

    // Loop until login is successful
    while (1) {
        printf("1. Register\n2. Login\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
            printf("Now login to continue.\n");
        }

        if (loginUser()) {
            printf("Login successful!\n");
            break; // Successful login, exit loop
        } else {
            printf("Login failed. Please try again.\n");
        }
    }

    loadFromFile(); // Load student data before menu
    menu(); // Show student management menu
    return 0;
}