#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *link;
};

struct node *START=NULL;

struct node* createNode(void)
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data(integer) in the node: ");
    //fflush(stdin);
    scanf("%d",&np->data);
    np->link = NULL;
    return(np);
}

void printNode(struct node *node_ptr)
{
    printf(" %d ",node_ptr->data);
}

int countNode(void)
{
    int count=0;
    if(START==NULL)
        return(count);
    else
    {
        struct node *np=START;
        while(np!=NULL)
        {
            count++;
            np = np->link;
        }
        return(count);
    }
}

void insertNode_first(void)
{
    struct node *np;
    np = createNode();
    if(START==NULL)
        printf("\nLinked List was empty... ");
    np->link = START;
    START = np;
    printf("\nNew node has been inserted as the first node successfully.\n");
}

void insertNode_last(void)
{
    if(START==NULL)
    {
        printf("\nThe list is empty.\n");
        insertNode_first();
    }
    else
    {
        struct node *np, *temp = START;
        np = createNode();
        while(temp->link != NULL)
            temp = temp->link;
        temp->link = np;
        printf("\nNew node has been inserted at the end of Linked list successfully.\n");
    }
}

void insertNode_custom(int req_node)        //supports insertion of node using negative integers too. for negative integers, counting of the node is done from the right, with the end node at -1 number/index(just like python.)
{
    if(req_node==0 || req_node==1)
        insertNode_first();
    else
    {
        if(req_node<0)                                          //req_node is negative
        {
            if(abs(req_node)>=countNode())
                insertNode_first();
            else
            {
                req_node = countNode() + req_node +1;
                int c = req_node;
                struct node *np, *t=START;                      // pointer t is used for traversal uptill specific node.
                np = createNode();
                while(req_node>2)
                {
                    t = t->link;
                    req_node--;
                }
                np->link = t->link;
                t->link = np;
                printf("\nNew node has been inserted as node number number %d in the linked list.\n",c);
            }
        }
        else
        {
            if( req_node > countNode() )
                insertNode_last();
            else
            {
                int c = req_node;
                struct node *np, *t=START;
                np = createNode();
                while(req_node>2)
                {
                    t = t->link;
                    req_node--;
                }
                np->link = t->link;
                t->link = np;
                printf("New node has been inserted as node number %d in the linked list.\n",c);
            }
        }
    }
}

void insertNode_multiple(int num)           //inserts num nodes at the end of linked list at single call of this function.
{
    int c = num;
    struct node *np, *t=START;
    while(num--)
    {
        np = createNode();
        if(START==NULL)
        {
            START = np;
            t = START;
        }
        else
        {
            while( t->link != NULL)
                t = t->link;
            t->link = np;
        }
    }
    printf("\n%d nodes has been inserted at the end of the linked list successfully.\n",c);
}

void deleteNode_first(void)
{
    if(START==NULL)
        printf("\nThe Linked list is empty.\n");
    else
    {
        struct node *np;
        np = START;
        START = START->link;
        free(np);
        printf("\nThe first node has been deleted successfully.\n");
    }

}

void deleteNode_last(void)
{
    if(START==NULL)
        printf("\nThe list is empty...\n");
    else
    {
        if(countNode()==1)
        {
            free(START);
            START=NULL;
            printf("\nThe last node has been deleted successfully.\n");
        }
        else
        {
            struct node *t=START;
            while( (t->link)->link!=NULL )
                t = t->link;
            free(t->link);
            t->link = NULL;
            printf("\nThe last node has been deleted successfully.\n");
        }
    }


}

void deleteNode_custom(int req_node)
{
    if(START==NULL)
        printf("\nThe list is empty...\n");
    else
    {
        int node_count = countNode();
        if( req_node == 0 || req_node == 1 )
            deleteNode_first();
        else if( req_node == -1 )
            deleteNode_last();
        else
        {
            if( req_node < 0 )                            //condition of negative required node.
            {
                if( abs(req_node) >= node_count )
                    deleteNode_first();
                else
                {
                    req_node = node_count + req_node + 1;
                    int c = req_node;
                    struct node *t2=START, *t1=START->link;
                    while( req_node>2 )
                    {
                        t1 = t1->link;
                        t2 = t2->link;
                        req_node--;
                    }
                    t1 = t1->link;
                    free(t2->link);
                    t2->link = t1;
                    printf("Node number %d has been deleted from the linked list successfully.\n",c);
                }
            }
            else                                          //condition of positive required node.
            {
                if( req_node >= node_count )
                    deleteNode_last();
                else
                {
                    int c = req_node;
                    struct node *t1 = START->link, *t2 = START;
                    while( req_node>2 )
                    {
                        t1 = t1->link;
                        t2 = t2->link;
                        req_node--;
                    }
                    t1 = t1->link;
                    free(t2->link);
                    t2->link = t1;
                    printf("Node number %d has been deleted from the linked list successfully.\n",c);
                }
            }
        }
    }
}

void deleteNode_range(int beg, int end)         // both beg and end node is inclusive, i.e, the beg and end will be deleted too.
{
    if(START==NULL)
    {
        printf("\nList is empty...\n");
    }
    else
    {
        if( abs(beg)>countNode() || abs(end)>countNode() )
            printf("\nThe index range of node exceeds the number of nodes currently present in the list.\nThus, no deletion possible in the provided range.\n");
        else
        {
            if(beg<0)
                beg = countNode() + beg + 1;
            if(end<0)
                end = countNode() + end + 1;
            int diff = end - beg, i;
            for(i=0 ; i<=diff ; i++)
                deleteNode_custom(beg);
            printf("\n%d nodes, serialised from number %d to %d has been deleted successfully.\n",diff+1,beg,end);
        }
    }
}

void reverseList(void)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else
    {
        struct node *t1=NULL, *t2=NULL;
        while(START!=NULL)
        {
            t2 = START->link;
            START->link = t1;
            t1 = START;
            START = t2;
        }
        START = t1;
        printf("\nThe linked list is reversed successfully.\n");
    }
}

void showList_all(void)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else
    {
        struct node *t=START;
        printf("\n");
        while(t!=NULL)
        {
            printNode(t);
            t = t->link;
        }
        printf("\n");
    }
}

void showNode(int req_node)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else if( abs(req_node) > countNode() )
    {
        if( req_node < 0 )                      //if the required node is negative.
            req_node = countNode() + req_node + 1;
        printf("\nNode number %d does not exist, as it exceeds the number of nodes currently present in the list.\n",req_node);
    }
    else
    {
        if( req_node < 0 )                      //if the required node is negative.
            req_node = countNode() + req_node + 1;
        // now the required node has the correst corresponding positive value of node.
        int cur_node=0;
        struct node *t=START;
        while(req_node>1)
        {
            t = t->link;
            req_node--;
        }
        printNode(t);
    }
}

void showList_custom(int beg, int end)
{
    if(START==NULL)
        printf("\nList is empty...\n");
    else if( abs(beg)>countNode() || abs(end)>countNode() )
        printf("\nProvided range exceeds the total number of nodes in the Linked List.\n");
    else
    {
        if( beg < 0 )
            beg = countNode() + beg + 1;
        if( end < 0 )
            end = countNode() + end + 1;
        int node_no = 1;
        struct node *t=START;
        while( node_no <= end )
        {
            if( node_no >= beg )
                printNode(t);
            t = t->link;
            node_no++;
        }
        printf("\n");
    }
}

int main(void)
{
    int choice, node_no, beg, end;
    printf("In this menu driven program, you can perform many kind of operations relatedto linked lists.\nEnter your choice of operation by entering integer corresponding to the operation in the listt below:\n");
    while(1)
    {
        printf("\n\n01. Insert a node at the beginning of list.\n");
        printf("02. Insert a node at the end of the list.\n");
        printf("03. Insert a single node at any index/serial no. in the list (you can use negative index input, by considering negative indexing count from the right/end, starting from -1).\n");
        printf("04. Insert multiple ( n number number of) nodes at the end of the list.\n");
        printf("05. Delete the first node.\n");
        printf("06. Delete the last node.\n");
        printf("07. Delete any (single) node of the list(may be in the middle). Supports negative indexing count of nodes, starting from the end/right as -1(just as in python).\n");
        printf("08. Delete a set of nodes(multiple) consecutively, at one go, by providng starting and ending index of the nodes set you want to delete. Supports negative indexing count of nodes, starting from the end/right as -1(just as in python).\n");
        printf("09. Count the number of nodes currently present in the list.\n");
        printf("10. Reverse the linked list.\n");
        printf("11. Show the data in a specific node in the list. Supports negative indexing of nodes starting from the end as -1.\n");
        printf("12. Show the data in a consecutive set of nodes in the list. Supports negative indexing of nodes starting from the end as -1.\n");
        printf("13. Show whole list.\n");
        printf("14. Exit.\n\n");
        scanf("%d",&choice);
        fflush(stdin);
        printf("\n");
        switch(choice)
        {
            case 1:
                insertNode_first();
                getch();
                break;

            case 2:
                insertNode_last();
                getch();
                break;

            case 3:
                printf("Enter the index/serial no. at which you want to enter a new node: ");
                scanf("%d",&node_no);
                fflush(stdin);
                insertNode_custom(node_no);
                getch();
                break;

            case 4:
                printf("How many nodes you want to add in the end of the list, one-by-one: ");
                scanf("%d",&node_no);
                fflush(stdin);
                insertNode_multiple(node_no);
                getch();
                break;

            case 5:
                deleteNode_first();
                getch();
                break;

            case 6:
                deleteNode_last();
                getch();
                break;

            case 7:
                printf("Enter the serial/index of the node that you want to delete: \n");
                scanf("%d",&node_no);
                fflush(stdin);
                deleteNode_custom(node_no);
                getch();
                break;

            case 8:
                printf("Enter the starting node index from which you want to delete: ");
                scanf("%d",&beg);
                fflush(stdin);
                printf("Enter the index of the node uptill which you want to delete: ");
                scanf("%d",&end);
                fflush(stdin);
                deleteNode_range( ( beg < end ? beg : end ) , ( beg > end ? beg : end ) );
                getch();
                break;

            case 9:
                printf("No. of nodes currently present in the linked list :  %d\n",countNode());
                getch();
                break;
            
            case 10:
                reverseList();
                getch();
                break;

            case 11:
                printf("Enter the index/serial of the node whose data you want to view: ");
                scanf("%d",&node_no);
                fflush(stdin);
                showNode(node_no);
                printf("\n");
                getch();
                break;

            case 12:
                printf("Enter the serial of the node from which you want to get displayed: ");
                scanf("%d",&beg);
                fflush(stdin);
                printf("Enter the serial number of the node uptill which you want to get displayed: ");
                scanf("%d",&end);
                showList_custom( (beg<end?beg:end) , (end>beg?end:beg) );
                getch();
                break;

            case 13:
                showList_all();
                getch();
                break;

            case 14:
                printf("\n\nExiting...\n");
                getch();
                exit(0);

            default:
                printf("Selected choice is invalid. Press any key to get the main menu...\n");
                getch();
        }
    }
}