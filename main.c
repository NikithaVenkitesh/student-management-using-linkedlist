#include "student.h"



int main()

{

    struct student *head = NULL;

    char choice;



    // Load previous records if the file exists

    stud_load(&head);



    while (1)

    {

        printf("\n--------------------------------------\n");

        printf("        STUDENT RECORD MENU\n");

        printf("--------------------------------------\n");

        printf("A/a : Add new record\n");

        printf("D/d : Delete a record\n");

        printf("S/s : Show the list\n");

        printf("M/m : Modify a record\n");

        printf("V/v : Save records\n");

        printf("E/e : Exit\n");

        printf("T/t : Sort the list\n");

        printf("L/l : Delete all records\n");

        printf("R/r : Reverse the list\n");

        printf("--------------------------------------\n");

        printf("Enter your choice: ");

        scanf(" %c", &choice);



        switch (choice)

        {

            case 'A':

            case 'a':

                stud_add(&head);

                break;



            case 'D':

            case 'd':

                stud_del(&head);

                break;



            case 'S':

            case 's':

                stud_show(head);

                break;



            case 'M':

            case 'm':

                stud_mod(head);

                break;



            case 'V':

            case 'v':

                stud_save(head);

                break;



            case 'E':

            case 'e':

                exit_menu(&head);

                break;



            case 'T':

            case 't':

                stud_sort(&head);

                break;



            case 'L':

            case 'l':

                delete_all(&head);

                break;



            case 'R':

            case 'r':

                reverse_list(&head);

                break;



            default:

                printf("Invalid choice! Please try again.\n");

        }

    }



    return 0;

}
