
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "student_list.h"


// Linked List
node* first = NULL;


// Prototypes
void delete(void);
void find(void);
void insert(void);
void traverse(void);


int main(void)
{
    int c;
    do
    {
        // print instructions
        printf("\nMENU\n\n"
               "1 - Delete\n"
               "2 - Find\n"
               "3 - Insert\n"
               "4 - Traverse\n"
               "0 - Quit\n\n");

        // get command
        printf("Command: ");
        scanf(" %d ", &c);

        // execute command
        switch (c)
        {
            case 1: delete(); break;
            case 2: find(); break;
            case 3: insert(); break;
            case 4: traverse(); break;
            default: printf("Invalid choice...\n");
        }
    }
    while (c != 0);

    // free list before quitting
    node *ptr = first;
    while (ptr != NULL)
    {
        node *predptr = ptr;
        ptr = ptr->next;
        free(predptr);
    }
    return 0;
}


/*
 * Tries to delete a student
 */
void delete(void)
{
    // promt user for ID
    int n;
    printf("ID to delete: ");
    scanf(" %d ", &n);

    // get list's first node
    node *ptr = first;

    // try to delete student from list
    node *predptr = NULL;
    while (ptr != NULL)
    {
        // check for ID
        if (ptr->student->id == n)
        {
            // delete from head
            if (ptr == first)
            {
                first = ptr->next;
                free(ptr->student->name);
                free(ptr->student->house);
                free(ptr->student);
                free(ptr);
            }
            // delete from middle or tail
            else
            {
                predptr->next = ptr->next;
                if (ptr->student->name != NULL)
                    free(ptr->student->name);
                if (ptr->student->house != NULL)
                    free(ptr->student->house);
                free(ptr->student);
                free(ptr);
            }
            // all done
            break;
        }
        else
        {
            predptr = ptr;
            ptr = ptr->next;
        }
    }
    // traverse list
    traverse();
}

