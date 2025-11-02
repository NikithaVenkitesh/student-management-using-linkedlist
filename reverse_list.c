#include "student.h"

// ✅ Function to reverse the linked list of student records
void reverse_list(struct student **head)
{
    struct student *prev = NULL, *current = *head, *next = NULL;

    if (*head == NULL)
    {
        printf("No records to reverse.\n");
        return;
    }

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    printf("✅ List reversed successfully.\n");
}
