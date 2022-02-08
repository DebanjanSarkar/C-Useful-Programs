//Stack implementation using linked list.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(void)
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    return(np);
}

void push(struct node **s, int item)
{
    struct node *np;
    np = createNode();
    np->data = item;
    np->next = *s;
    *s = np;
}

int peek(struct node **s)
{
    if((*s)!=NULL)
    {
        int item;
        item = (*s)->data;
        return(item);
    }
}

int pop(struct node **s)
{
    if(*s!=NULL)
    {
        struct node *temp = *s;
        int item = (*s)->data;
        *s = (*s)->next;
        free(temp);
        return(item);
    }
}

void removeStack(struct node **s)
{
    while(*s!=NULL)
        pop(s);
}

int countNode(struct node *t)
{
    int count=0;
    while( t != NULL )
    {
        t = t->next;
        count++;
    }
    return count;
}

int main(void)
{
    struct node *start=NULL;
    int data, choice;
    printf("This program implements stack using singly linked list.\n");
    while(1)
    {
        printf("\nWhat operation you want to perform on the linked list:\n1. PUSH data(integer)\n2. POP data\n3. PEEK top data\n4. Remove whole stack.\n5. Count the number of data in stack. \n6. Exit\n\nEnter your choice :   ");
        scanf("%d",&choice);
        fflush(stdin);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("\nEnter the data(integer) that you want to push into the stack: ");
                scanf("%d",&data);
                fflush(stdin);
                push(&start, data);
                printf("\nData has been pushed into the stack successfully.\n\n");
                getch();
                break;

            case 2:
                if(start == NULL)
                    printf("\nThe STACK is empty...\n\n");
                else
                {
                    data = pop(&start);
                    printf("\nData at top = %d\n\n",data);
                }
                getch();
                break;

            case 3:
                if(start == NULL)
                    printf("\nThe STACK is empty...\n\n");
                else
                {
                    data = peek(&start);
                    printf("\nData at top = %d\n\n",data);
                }
                getch();
                break;

            case 4:
                if(start == NULL)
                    printf("\nThe STACK is empty...\n\n");
                else
                {
                    removeStack(&start);
                    printf("\nThe STACK has been emptied successfully.\n\n");
                }
                getch();
                break;

            case 5:
                printf("\nNumber of data/nodes in the STACK currently :  %d\n\n",countNode(start));
                getch();
                break;

            case 6:
                printf("\n\nExiting...\n");
                getch();
                exit(0);

            default:
                printf("\nInvalid Choice entry. Press any key to get menu...\n\n");
                getch();
        }
    }
}