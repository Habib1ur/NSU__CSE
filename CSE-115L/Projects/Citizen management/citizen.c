#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
int user_count = 0;

const char FILE_NAME[] = "citiZen.dat";
const char FIlE_USER[] = "use.dat";

typedef struct
{
    int id;
    char name[50];
    char email[50];
    char phone[15];
    char address[200];
    char category[100];
    char complaint[200];
    char status[100];
} Complaint;
typedef struct
{
    char username[20];
    char password[20];
} User;

User users[MAX];
Complaint complaints[MAX];

void save_data(int *count)
{
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL)
        return;
    fwrite(complaints, sizeof(Complaint), *count, file);
    fclose(file);
}

void add_complaint(int *count)
{
    if (*count >= MAX)
    {
        printf("Complaints limit reached..\n");
        return;
    }
    printf("\nEnter complaint ID: ");
    scanf("%d", &complaints[*count].id);
    getchar();
    printf("Enter name:");
    fgets(complaints[*count].name, sizeof(complaints[*count].name), stdin);
    int idx = strcspn(complaints[*count].name, "\n");
    complaints[*count].name[idx] = '\0';
    printf("Enter Email: ");
    fgets(complaints[*count].email, sizeof(complaints[*count].email), stdin);
    int x = strcspn(complaints[*count].email, "\n");
    complaints[*count].email[x] = '\0';
    printf("Enter your phone: ");
    fgets(complaints[*count].phone, sizeof(complaints[*count].phone), stdin);
    int p = strcspn(complaints[*count].phone, "\n");
    complaints[*count].phone[p] = '\0';
    printf("Enter Address: ");
    fgets(complaints[*count].address, sizeof(complaints[*count].address), stdin);
    int y = strcspn(complaints[*count].address, "\n");
    complaints[*count].address[y] = '\0';
    printf("Enter Category (e.g., Road, Water, Electricity): ");
    fgets(complaints[*count].category, sizeof(complaints[*count].category), stdin);
    int z = strcspn(complaints[*count].category, "\n");
    complaints[*count].category[z] = '\0';
    printf("Enter Complaint Details: ");
    fgets(complaints[*count].complaint, sizeof(complaints[*count].complaint), stdin);
    int xyz = strcspn(complaints[*count].complaint, "\n");
    complaints[*count].complaint[xyz] = '\0';
    strcpy(complaints[*count].status, "Pending");
    (*count)++;
    save_data(count);
    clear_screen();
    printf("\nComplaint added successfully!\n");
}

void view_complaints(int *count)
{
    if (*count == 0)
    {
        printf("\nNo complaints found!\n");
        return;
    }

    printf("\n%-5s %-20s %-25s %-15s %-20s %-50s %-15s\n",
           "ID", "Name", "Email", "Phone", "Category", "Complaint", "Status");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < *count; i++)
    {
        printf("%-5d %-20s %-25s %-15s %-20s %-50s %-15s\n",
               complaints[i].id,
               complaints[i].name,
               complaints[i].email,
               complaints[i].phone,
               complaints[i].category,
               complaints[i].complaint,
               complaints[i].status);
    }
}

void search_complaint(int *count)
{
    if (*count == 0)
    {
        printf("No complaints to search!\n");
        return;
    }

    int searchId;
    printf("\nEnter complaint ID to search: ");
    scanf("%d", &searchId);

    printf("Search Results:\n");
    int found = 0;

    for (int i = 0; i < *count; i++)
    {
        if (complaints[i].id == searchId)
        {
            printf("\nID: %d\nName: %s\nEmail: %s\nPhone: %s\nAddress: %s\nCategory: %s\nComplaint: %s\nStatus: %s\n",
                   complaints[i].id, complaints[i].name,
                   complaints[i].email, complaints[i].phone,
                   complaints[i].address, complaints[i].category,
                   complaints[i].complaint, complaints[i].status);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No complaint found with ID %d.\n", searchId);
    }
}

void edit_complaint(int *count)
{
    if (*count == 0)
    {
        printf("No complaints to edit!\n");
        return;
    }

    int id;
    printf("\nEnter complaint ID to edit: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if (complaints[i].id == id)
        {
            printf("\nCurrent Complaint--->\n");
            printf("ID: %d\nName: %s\nEmail: %s\nPhone: %s\nAddress: %s\nCategory: %s\nComplaint: %s\nStatus: %s\n",
                   complaints[i].id, complaints[i].name,
                   complaints[i].email, complaints[i].phone,
                   complaints[i].address, complaints[i].category,
                   complaints[i].complaint, complaints[i].status);

            printf("\nEnter new details (leave blank to keep current value):\n");
            char input[200];
            getchar(); // Clear buffer

            printf("\nName [%s]: ", complaints[i].name);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].name, input);
            }
            printf("Email [%s]: ", complaints[i].email);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].email, input);
            }

            printf("Phone [%s]: ", complaints[i].phone);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].phone, input);
            }

            printf("Address [%s]: ", complaints[i].address);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].address, input);
            }
            printf("Category [%s]: ", complaints[i].category);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].category, input);
            }

            printf("Complaint Details [%s]: ", complaints[i].complaint);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].complaint, input);
            }

            printf("Status [%s]: ", complaints[i].status);
            fgets(input, sizeof(input), stdin);
            if (input[0] != '\n')
            {
                int idx = strcspn(input, "\n");
                input[idx] = '\0';
                strcpy(complaints[i].status, input);
            }
            save_data(count);
            clear_screen();
            printf("\nComplaint updated successfully!\n");
            return;
        }
    }
    clear_screen();
    printf("Complaint not found!\n");
}

void load_data(int *count)
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL)
        return;
    *count = fread(complaints, sizeof(Complaint), MAX, file);
    fclose(file);
}

void delete_complaint(int *count)
{
    if (*count == 0)
    {
        printf("No complaints to delete!\n");
        return;
    }

    int id;
    printf("\nEnter complaint ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if (complaints[i].id == id)
        {
            // Shift remaining complaints
            for (int j = i; j < *count - 1; j++)
            {
                complaints[j] = complaints[j + 1];
            }
            (*count)--;
            save_data(count);
            clear_screen();
            printf("\nComplaint deleted successfully!\n");
            return;
        }
    }
    clear_screen();
    printf("\nComplaint not found!\n");
}

void loadUsers()
{
    FILE *file = fopen(FIlE_USER, "rb");
    if (file == NULL)
        return;
    user_count = fread(users, sizeof(User), MAX, file);
    fclose(file);
}

void saveUsers()
{
    FILE *file = fopen(FIlE_USER, "wb");
    if (file == NULL)
        return 0;
    fwrite(users, sizeof(User), user_count, file);
    fclose(file);
}

int login()
{
    char username[20], password[20];
    printf("\nUsername: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);
    for (int i = 0; i < user_count; i++)
    {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            clear_screen();
            return 1;
        }
    }
    clear_screen();
    return 0;
}

void clear_screen()
{
    system("cls");
}

void addUser()
{
    if (user_count >= 100)
    {
        printf("Maximum user limit reached.\n");
        return;
    }
    printf("\nEnter new username: ");
    fgets(users[user_count].username, sizeof(users[user_count].username), stdin);
    int idx = strcspn(users[user_count].username, "\n");
    users[user_count].username[idx] = '\0';
    printf("Enter new password: ");
    fgets(users[user_count].password, sizeof(users[user_count].password), stdin);
    int pas = strcspn(users[user_count].password, "\n");
    users[user_count].password[pas] = '\0';
    user_count++;
    saveUsers(users, user_count);
    clear_screen();
    printf("\nUser added successfully.\n");
}

void clear_buffer()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    int count = 0;
    load_data(&count);
    loadUsers();
    int choice;

    if (user_count == 0)
    {
        printf("\nNo users found. Please create an admin user.\n");
        addUser();
    }
    if (!login())
    {
        printf("Login failed.\n");
        return 1;
    }

    while (1)
    {

        printf("\nCitizen Complaint Management System\n\n");
        printf("1. Add Complaint\n");
        printf("2. View Complaints\n");
        printf("3. Search Complaint\n");
        printf("4. Edit Complaint\n");
        printf("5. Delete Complaint\n");
        printf("6. Add user\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        clear_buffer();
        switch (choice)
        {
        case 1:
            add_complaint(&count);
            break;
        case 2:
            view_complaints(&count);
            break;
        case 3:
            search_complaint(&count);
            break;
        case 4:
            edit_complaint(&count);
            break;
        case 5:
            delete_complaint(&count);
            break;
        case 6:
            addUser();
            break;
        case 7:
            printf("\nExiting system...\n");
            return 0;
            break;
        default:
            printf("\nInvalid choice! Please try again....\n");
        }
    }

    return 0;
}
