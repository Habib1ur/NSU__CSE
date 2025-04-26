#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int attendance;
    float examMarks;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Load data from file
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

// Save data to file with better formatting
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

// Add student with attendance and exam marks input
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Student list is full!\n");
        return;
    }

    Student *s = &students[studentCount];
    printf("Enter Student ID: ");
    scanf("%d", &s->id);

    // Check for duplicate ID
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == s->id) {
            printf("A student with this ID already exists!\n");
            return;
        }
    }

    getchar(); // Clear buffer
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

// Display all students
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

// Update attendance by ID
void updateAttendance() {
    int id, found = 0;
    printf("Enter Student ID to update attendance: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        Student *s = &students[i];
        if (s->id == id) {
            printf("Enter new attendance count: ");
            scanf("%d", &s->attendance);
            saveToFile();
            printf("Attendance updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Update exam marks by ID
void updateExamMarks() {
    int id, found = 0;
    printf("Enter Student ID to update exam marks: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        Student *s = &students[i];
        if (s->id == id) {
            printf("Enter new exam marks: ");
            scanf("%f", &s->examMarks);
            saveToFile();
            printf("Exam marks updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Generate report with average
void generateReports() {
    if (studentCount == 0) {
        printf("No students available to generate reports!\n");
        return;
    }

    float totalMarks = 0;
    printf("\nStudent Reports:\n");
    printf("ID   Name                 Attendance Exam Marks\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%-4d %-20s %-10d %.2f\n",
               students[i].id,
               students[i].name,
               students[i].attendance,
               students[i].examMarks);
        totalMarks += students[i].examMarks;
    }

    float average = totalMarks / studentCount;
    printf("\nAverage Exam Marks: %.2f\n", average);
}

// Delete student by ID
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
            printf("Student with ID %d deleted successfully.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Menu
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
            case 7: printf("Exiting the system...\n"); break;
            default: printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 7);
}

// Entry point
int main() {
    loadFromFile();
    menu();
    return 0;
}