#include "student.h"

void stud_mod(struct student *head)
{
    if (head == NULL)
    {
        printf("\nNo records to modify.\n");
        return;
    }

    char choice;
    printf("\n--------------------------------------\n");
    printf("       Modify Record Sub-Menu          \n");
    printf("--------------------------------------\n");
    printf("R/r : Search and modify by Roll Number\n");
    printf("N/n : Search and modify by Name\n");
    printf("P/p : Search and modify by Percentage\n");
    printf("--------------------------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    struct student *temp = head;
    int roll, found = 0;
    char name[30];
    float perc;

    // 🔹 Modify by Roll Number
    if (choice == 'R' || choice == 'r')
    {
        printf("Enter Roll Number to modify: ");
        scanf("%d", &roll);

        while (temp)
        {
            if (temp->rollno == roll)
            {
                printf("Record found:\n");
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);

                printf("Enter New Name: ");
                scanf("%s", temp->name);
                printf("Enter New Percentage: ");
                scanf("%f", &temp->percentage);

                printf(" Record updated successfully!\n");
                return;
            }
            temp = temp->next;
        }
        printf(" Record not found!\n");
    }

    // 🔹 Modify by Name (may be multiple)
    else if (choice == 'N' || choice == 'n')
    {
        printf("Enter Name to search: ");
        scanf("%s", name);

        printf("\nMatching records:\n");
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
            printf(" No record found with the given name.\n");
            return;
        }

        printf("\nEnter Roll No to modify: ");
        scanf("%d", &roll);
        temp = head;

        while (temp)
        {
            if (temp->rollno == roll)
            {
                printf("Enter New Name: ");
                scanf("%s", temp->name);
                printf("Enter New Percentage: ");
                scanf("%f", &temp->percentage);
                printf("✅ Record updated successfully!\n");
                return;
            }
            temp = temp->next;
        }
        printf(" Invalid Roll No entered!\n");
    }

    // 🔹 Modify by Percentage (may be multiple)
    else if (choice == 'P' || choice == 'p')
    {
        printf("Enter Percentage to search: ");
        scanf("%f", &perc);

        printf("\nMatching records:\n");
        while (temp)
        {
            if (temp->percentage == perc)
            {
                printf("Roll No: %d | Name: %s | Percentage: %.2f\n",
                       temp->rollno, temp->name, temp->percentage);
                found = 1;
            }
            temp = temp->next;
        }

        if (!found)
        {
            printf("No record found with the given percentage.\n");
            return;
        }

        printf("\nEnter Roll No to modify: ");
        scanf("%d", &roll);
        temp = head;

        while (temp)
        {
            if (temp->rollno == roll)
            {
                printf("Enter New Name: ");
                scanf("%s", temp->name);
                printf("Enter New Percentage: ");
                scanf("%f", &temp->percentage);
                printf(" Record updated successfully!\n");
                return;
            }
            temp = temp->next;
        }
        printf(" Invalid Roll No entered!\n");
    }

    else
    {
        printf(" Invalid choice!\n");
    }
}
