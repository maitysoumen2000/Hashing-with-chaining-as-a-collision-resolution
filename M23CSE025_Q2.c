#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

void insert(int val);
void lookup(int val);
void delete(int val);
struct node
{
    int data;
    struct node *link;
};

int main()
{
    insert(5);
    insert(12);
    insert(21);
    insert(19);
    lookup(12);
    insert(2);
    insert(15);
    lookup(2);
    delete (12);
    lookup(12);
    delete (1);
}

struct node *start[MAX] = {NULL};
struct node *ptr;

void delete(int val)
{
    struct node *temp, *prev = NULL;
    int hkey, set = 0;
    hkey = val % MAX;
    temp = start[hkey];
    while (temp != NULL && temp->data != val)
    {
        prev = temp;
        temp = temp->link;
    }
    if (temp == NULL)
    {
        printf("element %d is not present\n", val);
        return;
    }
    if (prev == NULL)
    {
        start[hkey] = temp->link;
        free(temp);
        printf("element %d is deleted\n", val);
        return;
    }
    prev->link = temp->link;
    free(temp);
    printf("element %d is deleted\n", val);
}
void insert(int val)
{
    int hkey;
    hkey = val % MAX;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    new->link = NULL;
    if (start[hkey] == NULL)
        start[hkey] = new;
    else
    {
        ptr = start[hkey];
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = new;
    }
}

void lookup(int val)
{
    int hkey;
    hkey = val % MAX;
    if (start[hkey] == NULL)
        printf("element not found\n");

    else
    {
        for (ptr = start[hkey]; ptr != NULL; ptr = ptr->link)
        {
            if (ptr->data == val)
            {
                printf("element %d found\n", val);
                break;
            }
        }
        if (ptr == NULL)
            printf("element %d not found\n", val);
    }
}