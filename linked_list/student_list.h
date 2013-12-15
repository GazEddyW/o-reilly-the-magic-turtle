
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

