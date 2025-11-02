#include "student.h"

// Function to find the smallest available roll number
int find_next_rollno(struct student *head)
{
    int roll = 1;
    struct student *temp;

    while (1)
    {
        int found = 0;
        temp = head;
        while (temp)
        {
            if (temp->rollno == roll)
            {
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if (!found)
            return roll;  // Found available roll number
        roll++;
    }
}

void stud_add(struct student **head)
{
    struct student *newnode = malloc(sizeof(struct student));
    if (!newnode)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Auto-generate least positive roll number
    newnode->rollno = find_next_rollno(*head);

    // Take user input
    printf("Enter Name: ");
    scanf("%s", newnode->name);
    printf("Enter Percentage: ");
    scanf("%f", &newnode->percentage);

    newnode->next = NULL;

    // Insert node at end of the list
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct student *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("\nRecord added successfully!\n");
    printf("Generated Roll Number: %d\n", newnode->rollno);
}
