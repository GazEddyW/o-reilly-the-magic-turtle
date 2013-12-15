
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
}

