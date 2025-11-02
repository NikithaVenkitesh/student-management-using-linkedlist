#include "student.h"

void stud_show(struct student *head)
{
    if (head == NULL)
    {
        printf("\nNo student records available to display.\n");
        return;
    }

    printf("\n-----------------------------------------------------------\n");
    printf("                   STUDENT RECORD LIST                     \n");
    printf("-----------------------------------------------------------\n");
    printf("| %-10s | %-25s | %-12s |\n", "Roll No", "Name", "Percentage");
    printf("-----------------------------------------------------------\n");

    struct student *temp = head;
    while (temp)
    {
        printf("| %-10d | %-25s | %-12.2f |\n",
               temp->rollno, temp->name, temp->percentage);
        temp = temp->next;
    }

    printf("-----------------------------------------------------------\n");
}
