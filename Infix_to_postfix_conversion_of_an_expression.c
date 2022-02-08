// Program to Convert an Infix notation expression to Postfix notation expression.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct node
{
    char term;
    struct node *next;
};

struct llstack
{
    int count;
    struct node *top;
};

struct node* createNode(char ch)
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->next = NULL;
    np->term = ch;
    return(np);
}

struct llstack* createEmptyStack(void)
{
    struct llstack *stack;
    stack = (struct llstack*)malloc(sizeof(struct llstack));
    stack->top = NULL;
    stack->count = 0;
    return stack;
}

void push(struct llstack *stack, char ch)
{
    struct node *np;
    np = createNode(ch);
    np->next = stack->top;
    stack->top = np;
    stack->count++;
}

char peek(struct llstack *stack)
{
    if( stack->top != NULL )
    {
        char ch;
        ch = (stack->top)->term;
        return ch;
    }
}

char pop(struct llstack *stack)
{
    if( stack->top != NULL )
    {
        char ch;
        struct node *np;
        ch = (stack->top)->term;
        np = stack->top;
        stack->top = (stack->top)->next;
        free(np);
        stack->count--;
        return ch;
    }
}

int priority(char operator)
{
    if( operator=='+' || operator=='-' )
        return(1);
    else if( operator=='*' || operator=='/' || operator=='%' )
        return(2);
    else if( operator=='^' )
        return(3);
    else
        return(-1);
}

int belong( char *list, char ch )
{
    int i=0;
    while( list[i] != '\0' )
    {
        if( list[i] == ch )
            return(1);
        i++;
    }
    return(0);
}

void StringConcat( char *str, char ch )
{
    int i=0;
    while( str[i] != '\0' )
        i++;
    str[i] = ch;
    str[i+1] = '\0';
}

//char operands[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
//char operators[] = {'+','-','/','*','%','^','\0'};

int main(void)
{
    int exp_len, i=0;
    char *infix_exp, *postfix_exp;
    struct llstack *stack;
    char operands[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char operators[] = {'+','-','/','*','%','^','\0'};
    //---------------------------------------------------------------------------------------------
    stack = createEmptyStack();
    //---------------------------------------------------------------------------------------------
    printf("Enter the length(no of char) of the infix expression that you want to input: ");
    scanf("%d",&exp_len);
    infix_exp = (char*)calloc( exp_len+5 , sizeof(char) );
    printf("Type your Infix Expression, to get it converted to Postfix Expression(for brackets, use only parenthesis in input):\n");
    fflush(stdin);
    gets(infix_exp);
    //---------------------------------------------------------------------------------------------
    push(stack, '(');
    StringConcat(infix_exp, ')');
    exp_len = strlen( infix_exp );
    postfix_exp = (char*)calloc( exp_len , sizeof(infix_exp) );
    postfix_exp[0] = '\0';
    //---------------------------------------------------------------------------------------------
    while( stack->top != NULL )
    {
        if( infix_exp[i] == '(' )
        {
            push(stack,'(');
        }
        else if( belong( operands , infix_exp[i]) )
        {
            StringConcat( postfix_exp , infix_exp[i] );
        }
        else if( belong(operators, infix_exp[i]) )
        {
            while( belong( operators , peek(stack) ) )
            {
                if( priority( peek(stack) ) >= priority( infix_exp[i] ) )
                {
                    StringConcat( postfix_exp , pop(stack) );
                }
                else
                {
                    break;
                }
            }
            push( stack , infix_exp[i] );
        }
        else if( infix_exp[i] == ')' )
        {
            while( peek(stack) != '(' )
            {
                StringConcat( postfix_exp , pop(stack) );
            }
            pop(stack);
        }
        i++;
    }
    printf("\n\nPostfix Conversion of the above expression is : \n\n");
    puts(postfix_exp);
    printf("\n");
    getch();
    return(0);
}