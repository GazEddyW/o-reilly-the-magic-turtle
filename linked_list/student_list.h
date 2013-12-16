
#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct
{
    int id;
    char* name;
    char* house;
} student;

typedef struct node
{
    student* student;
    struct node* next;
} node;


#endif /* STUDENT_LIST_H */
