
#include "student_list.h"
#include "helper_functions.h"


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
        c = getInt();

        // execute command
        switch (c)
        {
            case 0: printf("\n\nBYE!\n\n"); break;
            case 1: delete(); break;
            case 2: find(); break;
            case 3: insert(); break;
            case 4: traverse(); break;
            default: printf("\nInvalid choice...\n");
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
    printf("ID to delete: ");
    int n = getInt();

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


/*
 * Attempts to insert a student into the list
 */
void insert(void)
{
    // try to instantiate node for student
    node *newptr = malloc(sizeof(node));
    if (newptr == NULL)
        return;

    // initialise node
    newptr->next = NULL;

    // try to instantiate student
    newptr->student = malloc(sizeof(student));
    if (newptr->student == NULL)
    {
        free(newptr);
        return;
    }

    fflush(stdin);
    // try to initialise student
    printf("Student's ID: ");
    newptr->student->id = getInt();
    fflush(stdin);
    printf("Student's name: ");
    newptr->student->name = getString();
    fflush(stdin);
    printf("Student's house: ");
    newptr->student->house = getString();

    if (newptr->student->name == NULL || newptr->student->house== NULL)
    {
        if (newptr->student->name != NULL)
            free(newptr->student->name);
        if (newptr->student->house != NULL)
            free(newptr->student->house);
        free(newptr->student);
        free(newptr);
        return;
    }

    // check for empty list
    if (first == NULL)
        first = newptr;
    // else check if student belongs at list's head
    else if (newptr->student->id < first->student->id)
    {
        newptr->next = first;
        first = newptr;
    }
    // else try to insert student in middle or tail
    else
    {
        node *predptr = first;
        while (1)
        {
            // avoid duplicates
            if (predptr->student->id == newptr->student->id)
            {
                free(newptr->student->name);
                free(newptr->student->house);
                free(newptr->student);
                free(newptr);
                break;
            }
            // check for insertion at tail
            else if (predptr->next == NULL)
            {
                predptr->next = newptr;
                break;
            }
            // check for insertion in middle
            else if (predptr->next->student->id > newptr->student->id)
            {
                newptr->next = predptr->next;
                predptr->next = newptr;
                break;
            }

            // update pointer
            predptr = predptr->next;
        }
    }

    // traverse list
    traverse();
}


/*
 * Tries to find a number in a list
 */
void find(void)
{
    // prompt user for ID
    printf("ID to find: ");
    int id = getInt();

    // get list's firstnode
    node *ptr = first;

    // try to find student
    while (ptr != NULL)
    {
        if (ptr->student->id == id)
        {
            printf("\nFound %s of %s (%d)!\n",
                    ptr->student->name, ptr->student->house, id);
            sleep(1);
            break;
        }
        ptr = ptr->next;
    }
}


/*
 * Traverses list, printing its numbers
 */
void traverse(void)
{
    // traverse list
    printf("\nLIST IS NOW: ");
    node *ptr = first;
    while (ptr != NULL)
    {
        printf("%s of %s (%d) ",
                ptr->student->name, ptr->student->house, ptr->student->id);
        ptr = ptr->next;
    }

    // flush stdout since we haven't outputted any newlines yet
    fflush(stdout);

    // pause before continuing
    sleep(1);
    printf("\n\n");
}

