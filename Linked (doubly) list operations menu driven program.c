//Program of Doubly linked list operations.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *START=NULL;

struct node* createNode(void)
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data in the node: ");
    scanf("%d",&np->data);
    np->prev = NULL;
    np->next = NULL;
    return(np);
}

void insertNode_first(void)
{
    struct node *np;
    np = createNode();
    if(START==NULL)
        START = np;
    else
    {
        np->next = START;
        START->prev = np;
        START = np;
    }
}

void insertNode_last(void)
{
    struct node *np;
    np = createNode();
    if(START==NULL)
        START = np;
    else
    {
        struct node *t=START;
        while( t->next !=NULL )
            t = t->next;
        t->next = np;
        np->prev = t;
    }
}

void deleteNode_first(void)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else
    {
        struct node *temp=START;
        START = START->next;
        free(temp);
        if(START!=NULL)
            START->prev = NULL;
    }
}

void deleteNode_last(void)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else if( START->next==NULL )
        deleteNode_first;
    else
    {
        struct node *t=START;
        while( (t->next)->next != NULL )
            t = t->next;
        free(t->next);
        t->next = NULL;
    }
}

void showList_all(void)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else
    {
        struct node *t=START;
        while(t!=NULL)
        {
            printf(" %d ",t->data);
            t = t->next;
        }
        printf("\n");
    }
}

int main(void)
{
    int choice;
    while(1)
    {
        printf("\nEnter your choice:-\n");
        printf("1. Show whole list.\n");
        printf("2. Insert node at last.\n");
        printf("3. Insert node as the first node.\n");
        printf("4. Delete the first node.\n");
        printf("5. Delete the last node.\n");
        printf("6. Exit.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                showList_all();
                getch();
                break;
            
            case 2:
                insertNode_last();
                getch();
                break;

            case 3:
                insertNode_first();
                getch();
                break;

            case 4:
                deleteNode_first();
                getch();
                break;
            
            case 5:
                deleteNode_last();
                getch();
                break;
            
            case 6:
                exit(0);
            
            default:
                printf("Invalid choice...\n");
                getch();
        }
    }
}