#include "student.h"

// ✅ Function to delete all student records
void delete_all(struct student **head)
{
    struct student *temp;

    if (*head == NULL)
    {
        printf("No records to delete.\n");
        return;
    }

    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    printf("✅ All records deleted successfully.\n");
}
