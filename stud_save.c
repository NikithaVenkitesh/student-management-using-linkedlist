#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

// 🔹 Function to save all records to "student.dat" in table format
void stud_save(struct student *head)
{
    FILE *fp = fopen("student.dat", "w"); // text mode
    if (!fp)
    {
        printf("Error opening file for saving!\n");
        return;
    }

    // Table header
    fprintf(fp, "---------------------------------------------------\n");
    fprintf(fp, "| %-10s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage");
    fprintf(fp, "---------------------------------------------------\n");

    // Data rows
    struct student *temp = head;
    while (temp)
    {
        fprintf(fp, "| %-10d | %-20s | %-10.2f |\n",
                temp->rollno, temp->name, temp->percentage);
        temp = temp->next;
    }

    // Footer line
    fprintf(fp, "---------------------------------------------------\n");

    fclose(fp);
    printf(" All records saved successfully in table format to 'student.dat'.\n");
}

// 🔹 Function to load existing records from "student.dat"
void stud_load(struct student **head)
{
    FILE *fp = fopen("student.dat", "r");
    if (!fp)
    {
        printf(" No existing database found. Starting fresh.\n");
        return;
    }

    struct student temp;
    int skipHeader = 0;
    char line[200];

    // Skip table header lines if file is in table format
    while (fgets(line, sizeof(line), fp))
    {
        if (line[0] == '|' && strchr(line, '|')) // data row
        {
            // Extract fields from line
            if (sscanf(line, "| %d | %19s | %f |",
                       &temp.rollno, temp.name, &temp.percentage) == 3)
            {
                struct student *newnode = malloc(sizeof(struct student));
                if (!newnode)
                {
                    printf(" Memory allocation failed!\n");
                    fclose(fp);
                    return;
                }

                newnode->rollno = temp.rollno;
                strcpy(newnode->name, temp.name);
                newnode->percentage = temp.percentage;
                newnode->next = *head;
                *head = newnode;
            }
        }
    }

    fclose(fp);
    printf(" Database loaded successfully from 'student.dat'.\n");
}

// 🔹 Exit Menu — (FIG-4)
void exit_menu(struct student **head)
{
    char choice;
    printf("\n--------------------------------------\n");
    printf("             Exit Menu\n");
    printf("--------------------------------------\n");
    printf("S/s : Save and Exit\n");
    printf("E/e : Exit without Saving\n");
    printf("--------------------------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'S' || choice == 's')
    {
        stud_save(*head);
        printf("💾 Exiting after saving...\n");
        exit(0);
    }
    else if (choice == 'E' || choice == 'e')
    {
        printf(" Exiting without saving...\n");
        exit(0);
    }
    else
    {
        printf(" Invalid choice! Returning to main menu.\n");
    }
}

// 🔹 Sort Menu — (FIG-5)
void stud_sort(struct student **head)
{
    if (*head == NULL)
    {
        printf("⚠ No records to sort.\n");
        return;
    }

    char choice;
    printf("\n--------------------------------------\n");
    printf("             Sort Menu\n");
    printf("--------------------------------------\n");
    printf("N/n : Sort by Name\n");
    printf("P/p : Sort by Percentage\n");
    printf("--------------------------------------\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    struct student *i, *j;
    int tempRoll;
    char tempName[20];
    float tempPer;

    if (choice == 'N' || choice == 'n')
    {
        for (i = *head; i; i = i->next)
        {
            for (j = i->next; j; j = j->next)
            {
                if (strcmp(i->name, j->name) > 0)
                {
                    tempRoll = i->rollno;
                    strcpy(tempName, i->name);
                    tempPer = i->percentage;

                    i->rollno = j->rollno;
                    strcpy(i->name, j->name);
                    i->percentage = j->percentage;

                    j->rollno = tempRoll;
                    strcpy(j->name, tempName);
                    j->percentage = tempPer;
                }
            }
        }
        printf(" List sorted alphabetically by Name.\n");
    }
    else if (choice == 'P' || choice == 'p')
    {
        for (i = *head; i; i = i->next)
        {
            for (j = i->next; j; j = j->next)
            {
                if (i->percentage > j->percentage)
                {
                    tempRoll = i->rollno;
                    strcpy(tempName, i->name);
                    tempPer = i->percentage;

                    i->rollno = j->rollno;
                    strcpy(i->name, j->name);
                    i->percentage = j->percentage;

                    j->rollno = tempRoll;
                    strcpy(j->name, tempName);
                    j->percentage = tempPer;
                }
            }
        }
        printf(" List sorted by Percentage.\n");
    }
    else
    {
        printf(" Invalid choice! Returning to main menu.\n");
    }
}
