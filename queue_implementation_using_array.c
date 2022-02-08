// Queue (single-ended) implementation using array (queue is of fixed size).
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct ArrayQueue
{
    int front, rear;
    int capacity;
    int *arr;
};

struct ArrayQueue* createQueue( int cap )
{
    struct ArrayQueue *q;
    q = (struct ArrayQueue*)malloc(sizeof(struct ArrayQueue));
    if(q == NULL)
        return(NULL);
    q->capacity = cap;
    q->front = q->rear = -1;
    q->arr = (int*)calloc(cap, sizeof(int));
    if( q->arr == NULL )
        return(NULL);
    return(q);
}

int isEmptyQueue(struct ArrayQueue *q)
{
    return( q->front == -1 );
}

int isFullQueue(struct ArrayQueue *q)
{
    return( (q->rear + 1) % q->capacity == q->front );
}

int QueueSize(struct ArrayQueue *q)
{
    if(isFullQueue(q))
        return(q->capacity);
    else if(isEmptyQueue(q))
        return(0);
    else
        return( (q->capacity - q->front + q->rear +1) % q->capacity );
}

void enQueue( struct ArrayQueue *q, int data )
{
    if(isFullQueue(q))
        printf("\nThe Queue is full. No more place to insert data.\n");
    else
    {
        q->rear = (q->rear + 1)%q->capacity;
        q->arr[q->rear] = data;
        if(q->front == -1)
            q->front++;
    }
}

int peekQueue( struct ArrayQueue *q )
{
    if(!isEmptyQueue(q))
        return( q->arr[q->front] );
}

int deQueue( struct ArrayQueue *q )
{
    if( q->front != -1 )
    {
        int data;
        data = q->arr[q->front];
        if( q->front == q->rear )
            q->front = q->rear = -1;
        else
            q->front = (q->front+1)%q->capacity;
        return(data);
    }
}

void removeQueue(struct ArrayQueue *q)
{
    if(q!=NULL)
    {
        if(q->arr != NULL)
            free(q->arr);
        free(q);
    }
}

void clearQueue(struct ArrayQueue *q)
{
    if( q!=NULL )
        if(isEmptyQueue(q))
            printf("\nThe Queue is already empty...\n\n");
        else
            q->front = q->rear = -1;
}

int main(void)
{
    int choice, data, capacity;
    struct ArrayQueue *q;
    printf("\nThis program implements Queue using fixed length array.\nEnter the size of queue that you want(that much data it can hold):-  ");
    scanf("%d",&capacity);
    fflush(stdin);
    q = createQueue(capacity);
    if( q == NULL)
    {
        printf("\nThere is a problem allocating memory to the queue.\n");
        getch();
        exit(1);
    }
    while(1)
    {
        printf("\n\nThe folowing operation you can perform on the Queue:\n");
        printf("1. Enter data into the queue (enqueue). \n2. Peek the front data of the queue. \n3. DeQueue the front data(remove and return) \n4. Current Size of the queue. \n5. Remove the Whole Queue(Release the memory allocated to the queue, and thus the stack wil exist no more to be operated) \n6. Clear whole queue(empties the queue) \n7. Exit\n\nEnter your choice:  ");
        scanf("%d",&choice);
        fflush(stdin);
        printf("\n");
        switch(choice)
        {
            case 1:
                printf("\nEnter the data that you want to insert into the queue: ");
                scanf("%d",&data);
                enQueue(q,data);
                getch();
                break;

            case 2:
                if(isEmptyQueue(q))
                    printf("\nThe Queue is empty.\n\n");
                else
                {
                    data = peekQueue(q);
                    printf("\nData at front currently: %d\n\n",data);
                }
                getch();
                break;

            case 3:
                if(isEmptyQueue(q))
                    printf("\nThe Queue is empty.\n\n");
                else
                {
                data = deQueue(q);
                printf("\nData at front currently:  %d\n\n",data);
                }
                getch();
                break;

            case 4:
                printf("\nCurrent size(no. of data present) of the queue is:  %d\n\n",QueueSize(q));
                getch();
                break;

            case 5:
                removeQueue(q);
                getch();
                break;

            case 6:
                clearQueue(q);
                getch();
                break;

            case 7:
                printf("\n\n\nExiting...\n");
                getch();
                exit(0);
            
            default:
                printf("\n\nInvalid Choice Entry.\n\n");
                getch();
        }
    }
}