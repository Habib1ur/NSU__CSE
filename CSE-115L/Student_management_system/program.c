#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct User
{
    char username[50];
    char password[50];
};

struct Student
{
    char name[50];
    char class_name[20];
    char roll[20];
    char id[20];
    char mobile[20];
    char address[100];
};

// Function declarations
void welcome();
void startMenu();
void registerUser();
int loginUser();
void mainMenu();
void addStudent();
void viewStudent();
void searchStudent();
void updateStudent();
void deleteStudent();
void initializeFiles();

// Main function
int main()
{
    initializeFiles();
    welcome();
    startMenu();
    return 0;
}

// Welcome message
void welcome()
{
    printf("\n\n\n--------------------------------------------\n");
    printf("WELCOME TO STUDENT MANAGEMENT SYSTEM\n");
    printf("--------------------------------------------\n\n\n");
}

// Initialize files and write headers
void initializeFiles()
{
    FILE *fp;

    // For user.txt
    fp = fopen("user.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("user.txt", "w");
        if (fp != NULL)
        {
            fprintf(fp, "%-30s%-30s\n", "Username", "Password");
            fprintf(fp, "------------------------------------------------------------\n");
            fclose(fp);
        }
    }
    else
    {
        fclose(fp);
    }

    // For student.txt
    fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        fp = fopen("student.txt", "w");
        if (fp != NULL)
        {
            fprintf(fp, "%-20s%-10s%-10s%-10s%-15s%-30s\n", "Name", "Class", "Roll", "ID", "Mobile", "Address");
            fprintf(fp, "-----------------------------------------------------------------------------------------\n");
            fclose(fp);
        }
    }
    else
    {
        fclose(fp);
    }
}

// Start menu
void startMenu()
{
    int choice;
    do
    {
        printf("\n--- START MENU ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser())
                mainMenu();
            else
                printf("\nInvalid Credentials! Try again.\n");
            break;
        case 3:
            printf("\nThank you! Exiting...\n");
            exit(0);
        default:
            printf("\nInvalid choice. Try again.\n");
        }
    }
    while (1);
}

// Register user
void registerUser()
{
    struct User u;
    FILE *fp = fopen("user.txt", "a");
    if (!fp)
    {
        printf("Error opening user file!\n");
        return;
    }

    printf("\nEnter Username: ");
    fgets(u.username, sizeof(u.username), stdin);
    u.username[strcspn(u.username, "\n")] = 0;

    printf("Enter Password: ");
    fgets(u.password, sizeof(u.password), stdin);
    u.password[strcspn(u.password, "\n")] = 0;

    fprintf(fp, "%-30s%-30s\n", u.username, u.password);
    fclose(fp);

    printf("\nRegistration Successful!\n");
}

// Login user
int loginUser()
{
    struct User u;
    FILE *fp = fopen("user.txt", "r");
    if (!fp)
    {
        printf("Error opening user file!\n");
        return 0;
    }

    char username[50], password[50];
    printf("\nEnter Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    char line[100];
    fgets(line, sizeof(line), fp); // Skip header
    fgets(line, sizeof(line), fp); // Skip line

    while (fscanf(fp, "%s %s", u.username, u.password) != EOF)
    {
        if (strcmp(u.username, username) == 0 && strcmp(u.password, password) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Main menu after login
void mainMenu()
{
    int choice;
    do
    {
        printf("\n--- MAIN MENU ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Logout\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudent();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            updateStudent();
            break;
        case 5:
            deleteStudent();
            break;
        case 6:
            startMenu();
            return;
        case 7:
            printf("\nThank you! Exiting...\n");
            exit(0);
        default:
            printf("\nInvalid choice. Try again.\n");
        }
    }
    while (1);
}

// Add student
void addStudent()
{
    struct Student s;
    FILE *fp = fopen("student.txt", "a");
    if (!fp)
    {
        printf("Error opening student file!\n");
        return;
    }

    printf("\nEnter Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Class: ");
    fgets(s.class_name, sizeof(s.class_name), stdin);
    s.class_name[strcspn(s.class_name, "\n")] = 0;

    printf("Enter Roll No: ");
    fgets(s.roll, sizeof(s.roll), stdin);
    s.roll[strcspn(s.roll, "\n")] = 0;

    printf("Enter ID: ");
    fgets(s.id, sizeof(s.id), stdin);
    s.id[strcspn(s.id, "\n")] = 0;

    printf("Enter Mobile No: ");
    fgets(s.mobile, sizeof(s.mobile), stdin);
    s.mobile[strcspn(s.mobile, "\n")] = 0;

    printf("Enter Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = 0;

    fprintf(fp, "%-20s%-10s%-10s%-10s%-15s%-30s\n", s.name, s.class_name, s.roll, s.id, s.mobile, s.address);
    fclose(fp);

    printf("\nStudent Added Successfully!\n");
}

// View students
void viewStudent()
{
    FILE *fp = fopen("student.txt", "r");
    if (!fp)
    {
        printf("Error opening student file!\n");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), fp))
    {
        printf("%s", line);
    }

    fclose(fp);
}

// Search student
void searchStudent()
{
    struct Student s;
    FILE *fp = fopen("student.txt", "r");
    if (!fp)
    {
        printf("Error opening student file!\n");
        return;
    }

    char roll[20];
    printf("\nEnter Roll No to Search: ");
    fgets(roll, sizeof(roll), stdin);
    roll[strcspn(roll, "\n")] = 0;

    char line[200];
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    int found = 0;
    printf("\n%-20s%-10s%-10s%-10s%-15s%-30s\n", "Name", "Class", "Roll", "ID", "Mobile", "Address");
    printf("-----------------------------------------------------------------------------------------\n");

    while (fscanf(fp, "%s %s %s %s %s %[^\n]", s.name, s.class_name, s.roll, s.id, s.mobile, s.address) != EOF)
    {
        if (strcmp(s.roll, roll) == 0)
        {
            printf("%-20s%-10s%-10s%-10s%-15s%-30s\n", s.name, s.class_name, s.roll, s.id, s.mobile, s.address);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");

    fclose(fp);
}

// Update student
void updateStudent()
{
    struct Student s;
    FILE *fp = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp)
    {
        printf("Error opening file!\n");
        return;
    }

    char roll[20];
    printf("\nEnter Roll No to Update: ");
    fgets(roll, sizeof(roll), stdin);
    roll[strcspn(roll, "\n")] = 0;

    char line[200];
    fgets(line, sizeof(line), fp);
    fprintf(temp, "%s", line);
    fgets(line, sizeof(line), fp);
    fprintf(temp, "%s", line);

    int found = 0;

    while (fscanf(fp, "%s %s %s %s %s %[^\n]", s.name, s.class_name, s.roll, s.id, s.mobile, s.address) != EOF)
    {
        if (strcmp(s.roll, roll) == 0)
        {
            found = 1;
            printf("\nEnter New Details:\n");

            printf("Enter Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;

            printf("Enter Class: ");
            fgets(s.class_name, sizeof(s.class_name), stdin);
            s.class_name[strcspn(s.class_name, "\n")] = 0;

            printf("Enter Roll No: ");
            fgets(s.roll, sizeof(s.roll), stdin);
            s.roll[strcspn(s.roll, "\n")] = 0;

            printf("Enter ID: ");
            fgets(s.id, sizeof(s.id), stdin);
            s.id[strcspn(s.id, "\n")] = 0;

            printf("Enter Mobile No: ");
            fgets(s.mobile, sizeof(s.mobile), stdin);
            s.mobile[strcspn(s.mobile, "\n")] = 0;

            printf("Enter Address: ");
            fgets(s.address, sizeof(s.address), stdin);
            s.address[strcspn(s.address, "\n")] = 0;
        }
        fprintf(temp, "%-20s%-10s%-10s%-10s%-15s%-30s\n", s.name, s.class_name, s.roll, s.id, s.mobile, s.address);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        printf("\nStudent Updated Successfully!\n");
    else
        printf("\nStudent not found!\n");
}

// Delete student
void deleteStudent()
{
    struct Student s;
    FILE *fp = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp)
    {
        printf("Error opening file!\n");
        return;
    }

    char roll[20];
    printf("\nEnter Roll No to Delete: ");
    fgets(roll, sizeof(roll), stdin);
    roll[strcspn(roll, "\n")] = 0;

    char line[200];
    fgets(line, sizeof(line), fp);
    fprintf(temp, "%s", line);
    fgets(line, sizeof(line), fp);
    fprintf(temp, "%s", line);

    int found = 0;

    while (fscanf(fp, "%s %s %s %s %s %[^\n]", s.name, s.class_name, s.roll, s.id, s.mobile, s.address) != EOF)
    {
        if (strcmp(s.roll, roll) != 0)
        {
            fprintf(temp, "%-20s%-10s%-10s%-10s%-15s%-30s\n", s.name, s.class_name, s.roll, s.id, s.mobile, s.address);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found)
        printf("\nStudent Deleted Successfully!\n");
    else
        printf("\nStudent not found!\n");
}
