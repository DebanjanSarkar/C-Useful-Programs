// Stack implementation using fixed-size array.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct ArrayStack
{
    int top, *array;
    unsigned int capacity;
};

struct ArrayStack* createStack(unsigned int cap)
{
    struct ArrayStack *stack;
    stack = (struct ArrayStack*)malloc(sizeof(struct ArrayStack));
    stack->capacity = cap;
    stack->top = -1;
    stack->array = (int*)calloc(cap,sizeof(int));
    return(stack);
}

int isFull(struct ArrayStack *stack)
{
    if( stack->top == stack->capacity-1 )
        return 1;
    else
        return 0;
}

int isEmpty(struct ArrayStack *stack)
{
    if(stack->top == -1)
        return(1);
    else
        return(0);
}

void push(struct ArrayStack *stack, int data)
{
    if(!isFull(stack))
    {
        stack->top++;
        stack->array[stack->top] = data;
    }
}

int pop(struct ArrayStack *stack)
{
    if(!isEmpty(stack))
    {
        int data;
        data = stack->array[stack->top];
        stack->top--;
        return(data);
    }
}

int main(void)
{
    unsigned int maxstk;
    int data, choice;
    struct ArrayStack *stack;
    printf("This program is an implementation of STACK Abstract Data Type, using fixed size array.\n");
    printf("Enter the maximum number of data that the stack may contain: ");
    scanf("%u",&maxstk);
    fflush(stdin);
    stack = createStack(maxstk);
    while(1)
    {
        printf("\nEnter the operation that you want to perform:\n1. PUSH\n2. POP\n3. Exit\n");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                if(isFull(stack))
                    printf("\n\nOVERFLOW. The stack is already full.\n");
                else
                {
                    printf("\n\nEnter the data that you want to push: ");
                    scanf("%d",&data);
                    push(stack,data);
                }
                getch();
                break;

            case 2:
                if(isEmpty(stack))
                    printf("\n\nUNDERFLOW. The stack is empty.\n");
                else
                {
                    data = pop(stack);
                    printf("\n\n%d\n",data);
                }
                getch();
                break;

            case 3:
                printf("\n\nExiting...\n");
                getch();
                exit(0);

            default:
                printf("\n\nInvalid Choice Entry...\n");
                getch();
        }
    }
}