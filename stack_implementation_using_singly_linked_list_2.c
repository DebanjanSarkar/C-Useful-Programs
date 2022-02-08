// stack implementation using singly linked list : 2nd Method.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};

struct Linked_List_Stack
{
    int count;
    struct node *top;
};

struct node* createNode(int item)
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->data = item;
    np->next = NULL;
    return(np);
}

void push(struct Linked_List_Stack *stack, int item)
{
    struct node *np;
    np = createNode(item);
    (*np).next = (*stack).top;      // (*stack).top is equivalent to stack->top
    stack->top = np;
    (stack->count)++;
}

int peek(struct Linked_List_Stack *stack)
{
    if( stack->top != NULL )
    {
        int item;
        item = (stack->top)->data;
        return item;
    }
}

int pop(struct Linked_List_Stack *stack)
{
    if( stack->top != NULL )
    {
        int item;
        struct node *temp;
        item = (stack->top)->data;
        temp = stack->top;
        stack->top = (stack->top)->next;
        free(temp);
        (stack->count)--;
        return(item);
    }
}

void removeStack(struct Linked_List_Stack *stack)
{
    while( stack->top != NULL )
        pop(stack);
}

int main(void)
{
    int choice, data;
    struct Linked_List_Stack *stack;
    stack = (struct Linked_List_Stack*)malloc(sizeof(struct Linked_List_Stack));
    stack->count = 0;
    stack->top = NULL;
    while(1)
    {
        printf("\nEnter your choice: \n1. PUSH \n2. PEEK \n3. POP \n4. Count number of data/nodes \n5. Remove/Clear whole stack \n6. Exit\n");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data that you want to push to the stack: ");
                scanf("%d",&data);
                push(stack, data);
                printf("\nData is successfully pushed into the stack.\n\n");
                getch();
                break;

            case 2:
                if(stack->top==NULL)
                    printf("\nSTACK is empty...\n\n");
                else
                {
                    data = peek(stack);
                    printf("\nData at the top of the STACK currently :  %d\n\n",data);
                }
                getch();
                break;
                
            case 3:
                if(stack->top==NULL)
                    printf("\nSTACK is empty...\n\n");
                else
                {
                    data = pop(stack);
                    printf("\nData that is popped :  %d\n\n",data);
                }
                getch();
                break;

            case 4:
                printf("\nNumber of nodes/data present in the STACK currently :  %d\n\n",stack->count);
                getch();
                break;

            case 5:
                if(stack->top==NULL)
                    printf("\nSTACK is empty...\n\n");
                else
                {
                    removeStack(stack);
                    printf("\nThe whole stack is cleared successfully.\n\n");
                }
                getch();
                break;

            case 6:
                printf("\n\nExiting...\n");
                getch();
                exit(0);
            
            default:
                printf("\nInvalid choice entry...\n\n");
                getch();

        }
    }
}