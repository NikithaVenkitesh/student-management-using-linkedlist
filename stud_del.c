#include "student.h"

// Function to delete by roll number
void delete_by_roll(struct student **head)
{
    if (*head == NULL)
    {
        printf("No records to delete.\n");
        return;
    }

    int roll;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    struct student *temp = *head, *prev = NULL;

    while (temp)
    {
        if (temp->rollno == roll)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            printf("Record with Roll Number %d deleted successfully.\n", roll);
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Roll Number %d not found.\n", roll);
}

// Function to delete by name
void delete_by_name(struct student **head)
{
    if (*head == NULL)
    {
        printf("No records to delete.\n");
        return;
    }

    char name[30];
    printf("Enter Name to delete: ");
    scanf("%s", name);

    struct student *temp = *head;
    int found = 0;

    // First, show all matches
    printf("\nMatching records with name '%s':\n", name);
    printf("--------------------------------------\n");
    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                   temp->rollno, temp->name, temp->percentage);
            found = 1;
        }
        temp = temp->next;
    }

    if (!found)
    {
        printf("No records found with the name '%s'.\n", name);
        return;
    }

    int roll;
    printf("\nEnter Roll Number from above list to delete: ");
    scanf("%d", &roll);

    // Reuse delete by roll function
    delete_by_roll(head);
}

// Main delete function – submenu
void stud_del(struct student **head)
{
    char choice;

    printf("\n--------------------------------------\n");
    printf("           DELETE RECORD MENU          \n");
    printf("--------------------------------------\n");
    printf("R/r: Delete based on Roll Number\n");
    printf("N/n: Delete based on Name\n");
    printf("--------------------------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'R' || choice == 'r')
        delete_by_roll(head);
    else if (choice == 'N' || choice == 'n')
        delete_by_name(head);
    else
        printf("Invalid choice! Returning to main menu.\n");
}
