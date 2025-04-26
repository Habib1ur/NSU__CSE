#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[50];
    int attendance;
    float examMarks;
} Student;

Student students[100];
int studentCount = 0;

// Function to add a student
void addStudent()
{
    if (studentCount >= 100)
    {
        printf("Student list is full!\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%d", &students[studentCount].id);
    getchar();

    printf("Enter Student Name: ");
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0; // Remove newline

    students[studentCount].attendance = 0;
    students[studentCount].examMarks = 0.0;

    studentCount++;
    printf("Student added successfully!\n");
}

void displayStudents()
{
    if (studentCount == 0)
    {
        printf("No students available!\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("ID\tName\t\tAttendance\tExam Marks\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("%d\t%s\t\t%d\t\t%.2f\n", students[i].id, students[i].name, students[i].attendance, students[i].examMarks);
    }
}

void updateAttendance()
{
    int id, found = 0;
    printf("Enter Student ID to update attendance: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter new attendance count: ");
            scanf("%d", &students[i].attendance);
            printf("Attendance updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student not found!\n");
    }
}

void updateExamMarks()
{
    int id, found = 0;
    printf("Enter Student ID to update exam marks: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            printf("Enter new exam marks: ");
            scanf("%f", &students[i].examMarks);
            printf("Exam marks updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Student not found!\n");
    }
}

void generateReports()
{
    if (studentCount == 0)
    {
        printf("No students available to generate reports!\n");
        return;
    }
    printf("\nStudent Reports:\n");
    printf("ID\tName\t\tAttendance\tExam Marks\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("%d\t%s\t\t%d\t\t%.2f\n", students[i].id, students[i].name, students[i].attendance, students[i].examMarks);
    }
}

// Main menu function
void menu()
{
    int choice;
    do
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Update Attendance\n");
        printf("4. Update Exam Marks\n");
        printf("5. Generate Reports\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            updateAttendance();
            break;
        case 4:
            updateExamMarks();
            break;
        case 5:
            generateReports();
            break;
        case 6:
            printf("Exiting the system...\n");
            break;
        default:
            printf("Invalid choice! Please enter again.\n");
        }
    } while (choice != 6);
}

int main()
{
    menu();
    return 0;
}
