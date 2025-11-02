#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int rollno;
    char name[30];
    float percentage;
    struct student *next;
};

// ===== STUDENT RECORD MENU (Display Format) =====
/*
    ***** STUDENT RECORD MENU *****

    a/A : add new record
    d/D : delete a record
    s/S : show the list
    m/M : modify a record
    v/V : save
    e/E : exit
    t/T : sort the list
    l/L : delete all the records
    r/R : reverse the list

    Enter your choice:
*/

// ===== Function Declarations =====
void stud_add(struct student **);
void stud_del(struct student **);
void stud_show(struct student *);
void stud_mod(struct student *);
void stud_save(struct student *);
void stud_load(struct student **);
void stud_sort(struct student **);
void exit_menu(struct student **);
void delete_all(struct student **);
void reverse_list(struct student **);

#endif
