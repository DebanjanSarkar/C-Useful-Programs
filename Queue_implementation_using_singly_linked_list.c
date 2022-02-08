// Stack implementation using singly linked list.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};

struct llqueue                          //llqueue stands for Linked List Queue
{
    int size;
    struct node *front;
};

struct node* createNode(int item)
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->next = NULL;
    np->data = item;
    return(np);
}

struct llqueue* createQueue(void)
{
    struct llqueue *q;
    q = (struct llqueue*)malloc(sizeof(struct llqueue));
    q->size = 0;
    q->front = NULL;
    return(q);
}

void enQueue(struct llqueue *q, int item)
{
    struct node *np, *t=(q->front);
    np = createNode(item);
    if(t==NULL)
        q->front = np;
    else
    {
        while(t->next!=NULL)
            t = t->next;
        t->next = np;
    }
    q->size++;
}

int deQueue(struct llqueue *q)
{
    if(q->front!=NULL)
    {
        int item = (q->front)->data;
        struct node *temp;
        temp = q->front;
        q->front = (q->front)->next;
        free(temp);
        q->size--;
        return(item);
    }
}

int peekQueue(struct llqueue *q)
{
    if(q->front!=NULL)
    {
        return( (q->front)->data );
    }
}

void clearQueue(struct llqueue *q)
{
    if(q->front==NULL)
        printf("\nThe queue is already empty...\n\n");
    else
    {
        while(q->front!=NULL)
            deQueue(q);
    }
}

int main(void)
{
    int choice, data;
    struct llqueue *q;
    q = createQueue();
    printf("This program implements Queue using singly linked list.\n");
    while(1)
    {
        printf("\nYou can perform following operations on the queue:\n");
        printf("1. EnQueue \n2. Peek \n3. DeQueue \n4. Get the current size of Queue \n5. Clear the whole queue \n6. Exit \n\nEnter your choice:  ");
        scanf("%d",&choice);
        fflush(stdin);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("Enter the data you want to insert:  ");
                scanf("%d",&data);
                fflush(stdin);
                enQueue(q,data);
                getch();
                break;

            case 2:
                if(q->size==0)
                    printf("\nThe queue is empty.\n\n");
                else
                    printf("\nData at front:  %d\n\n",peekQueue(q));
                getch();
                break;
                
            case 3:
                if(q->size==0)
                    printf("\nThe queue is empty.\n\n");
                else
                    printf("\nData at front:  %d\n\n",deQueue(q));
                getch();
                break;
                
            case 4:
                printf("\nThe current size of the queue is:  %d\n\n",q->size);
                getch();
                break;
                
            case 5:
                clearQueue(q);
                getch();
                break;
                
            case 6:
                printf("\n\nExiting...\n");
                getch();
                exit(0);
                break;
                
            default:
                printf("\n\nInvalid choice entry.\n\n");
                getch();
        }
    }
}