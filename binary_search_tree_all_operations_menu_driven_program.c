//Program of Binary tree and its related operations.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct BTNode
{
    int data;
    struct BTNode *left, *right;
};

struct BTNode* createBTNode(int value)
{
    struct BTNode *btn;
    btn = (struct BTNode*)malloc(sizeof(struct BTNode));
    btn->data = value;
    btn->left = NULL;
    btn->right = NULL;
    return(btn);
}

/*
    We need to return the root pointer variable value form thsi function because we are actually assigning new node address to the
    root pointer which is a local variable, and not a pointer to a pointer to a struct, so that it can change the address in the
    actual root pointer variable in the main function itself.

    Thus, any changes made to the local pointer variable root will be lost, if not returned, as after the function execution ends, local
    pinter variable root will be destroyed, and eventually the new created node address that was meant to be inserted in the binary tree
    will actually get lost!
*/

struct BTNode* insertBTNode_recur(struct BTNode *root, int value)
{
    struct BTNode *temp, *t;
    temp = createBTNode(value);
    if(root==NULL)
    {
        root = temp;
        return(root);
    }
    else
    {
        t = root;
        if( value < t->data )
        {
            t->left = insertBTNode_recur( t->left , value );
            return(t);
        }
        else if( value > t->data )
        {
            t->right = insertBTNode_recur( t->right , value );
            return(t);
        }
    }
}

struct BTNode* insertBTNode_loop(struct BTNode *root, int value)
{
    struct BTNode *temp, *t1, *t2;
    temp = createBTNode(value);
    if( root == NULL )
    {
        root = temp;
        return(root);
    }
    else
    {
        t1 = root;
        t2 = NULL;
        while( t1 != NULL)
        {
            t2 = t1;
            if( value < t1->data )
                t1 = t1->left;
            else if( value > t1->data )
                t1 = t1->right;
        }
        if( value < t2->data )
            t2->left = temp;
        else if( value > t2->data )
            t2->right = temp;
        return(root);
    }
}

struct BTNode* searchBTNode_recur(struct BTNode *root, int value)
{
    if(root)
    {
        if(root->data == value)
            return(root);
        else if( value < root->data)
            return( searchBTNode_recur( root->left, value ) );
        else
            return( searchBTNode_recur( root->right , value ) );
    }
    else
        return(NULL);
}

int traverse_preorder(struct BTNode *root)
{
    if(root)
    {
        printf("  %d  ",root->data);
        traverse_preorder(root->left);
        traverse_preorder(root->right);
        return(0);                          //For !NULL binary tree root. Can be used to check whether binary tree is empty.
    }
    else
        return(-1);                         //For NULL binary tree root. Can be used to check whether binary tree is empty.
}

int traverse_inorder(struct BTNode *root)
{
    if(root)
    {
        traverse_inorder(root->left);
        printf("  %d  ",root->data);
        traverse_inorder(root->right);
        return(0);
    }
    else
        return(-1);
}

int traverse_postorder(struct BTNode *root)
{
    if(root)
    {
        traverse_postorder(root->left);
        traverse_postorder(root->right);
        printf("  %d  ",root->data);
        return 0;
    }
    else
        return -1;
}

//Logic: Traverse through left subtree only(no right-node traversal), and in-course, the node with NULL *left pointer is the smallest.
struct BTNode* getMIN( struct BTNode *root )
{
    struct BTNode *t;
    if( root == NULL )
        return(NULL);
    else
    {
        t = root;
        while( t->left )
            t = t->left;
        return(t);
    }
}

//Logic: Traverse through right subtree only(no left-node traversal), and in-course, the node with NULL *right pointer is the largest.
struct BTNode* getMAX( struct BTNode *root )
{
    struct BTNode *t;
    if( root == NULL )
        return(NULL);
    else
    {
        t = root;
        while( t->right )
            t = t->right;
        return(t);
    }
}

struct BTNode* deleteBTNode_recur( struct BTNode *root, int value )
{
    struct BTNode *t, *temp, *t2;
    if( root == NULL )
        return(NULL);
    else
    {
        t = root;
        if( value == t->data )
        {
            if( t->left == NULL && t->right == NULL )                 //Node to be deleted is a leaf node.
            {
                free(t);
                t = NULL;
                return(t);
            }
            else if( t->left != NULL && t->right == NULL )           //Node to be deleted has Left subtree only
            {
                temp = t;
                t = t->left;
                free(temp);
                return(t);
            }
            else if( t->left == NULL && t->right != NULL )           //Node to be deleted has right subtree only
            {
                temp = t;
                t = t->right;
                free(temp);
                return(t);
            }
            else if( t->left != NULL && t->right != NULL )           //Node to be deleted has both left and right subtree.
            {
                temp = t->left;
                t2 = NULL;
                while( temp->right )
                {
                    t2 = temp;
                    temp = temp->right;
                }
                t->data = temp->data;
                if( t2 )
                {
                    t2->right = deleteBTNode_recur( t2->right, temp->data );
                }
                else
                {
                    t->left = deleteBTNode_recur( t->left, (t->left)->data );
                }
                return(t);
            }
        }
        else if( value < t->data )
        {
            t->left = deleteBTNode_recur( t->left, value );
            return(t);
        }
        else if( value > t->data )
        {
            t->right = deleteBTNode_recur( t->right, value );
            return(t);
        }
    }
}

int main(void)
{
    struct BTNode *root = NULL, *temp = NULL;
    int i, *arr, arrSize, choice, node_count=0, value, check;
    printf("This is a program which implements Binary Tree and all its operations in C language.\n\n");
    printf("You can enter a number of integers initially, that will form the binary tree initially, and then to it, perform various operations.\n\n");
    printf("Enter how many integers you want to input to the binary tree initially:  ");
    scanf("%d",&arrSize);
    arr = (int*)calloc( arrSize , sizeof(int) );
    fflush(stdin);
    printf("\nEnter %d integers:\n",arrSize);
    for(i=0;i<arrSize;i++)
    {
        scanf("%d", (arr + i) );
    }
    fflush(stdin);
    for(i=0;i<arrSize;i++)
    {
        root = insertBTNode_recur( root , arr[i] );
    }
    node_count = arrSize;
    printf("\n\nInitial Binary Tree creation successfull with %d nodes insertion.\n\n",arrSize);

    while(1)
    {
        printf("Which operation do you want to perform on the Binary Tree:-\n");
        printf("1. Insert a new node (value) to the Binary Tree(using recursion).\n");
        printf("2. Insert a new node (value) to the Binary Tree(using loop).\n");
        printf("3. Check no. of nodes present in the Binary Tree Currently.\n");
        printf("4. View the Binary Tree contents in Inorder way.\n");
        printf("5. View the Binary Tree contents in Preorder way.\n");
        printf("6. View the Binary Tree contents in Postorder way.\n");
        printf("7. Get the SMALLEST value present in the binary tree currently.\n");
        printf("8. Get the LARGEST value present in the binary tree currently.\n");
        printf("9. Delete a value/node from the binary tree.\n");
        printf("10. Clear the screen.\n");
        printf("11. Exit.\n");
        printf("\nEnter your choice:  ");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                printf("\nEnter the integer value that you want to insert :  ");
                scanf("%d",&value);
                if( searchBTNode_recur( root, value ) )
                    printf("\nThe specific value already exists in the Binary Tree.\n");
                else
                {
                    root = insertBTNode_recur( root , value );
                    node_count += 1;
                    printf("\nThe value is inserted into the binary tree successfully.");
                }
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;
            
            case 2:
                printf("\nEnter the integer value that you want to insert :  ");
                scanf("%d",&value);
                if( searchBTNode_recur( root, value ) )
                    printf("\nThe specific value already exixts in the Binary Tree.\n");
                else
                {
                    root = insertBTNode_loop( root , value );
                    node_count += 1;
                    printf("\nThe value is inserted into the binary tree successfully.");
                }
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;

            case 3:
                printf("\nThe Binary Tree contains  %d  nodes currently.\n",node_count);
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;

            case 4:
                printf("\nInorder Traversal of the binary tree:\n");
                check = traverse_inorder( root );
                if(check == -1)
                    printf("\nThe tree is empty...\n");
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;

            case 5:
                printf("\nPreorder Traversal of the binary tree:\n");
                check = traverse_preorder( root );
                if(check == -1)
                    printf("\nThe tree is empty...\n");
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;

            case 6:
                printf("\nPostorder Traversal of the binary tree:\n");
                check = traverse_postorder( root );
                if(check == -1)
                    printf("\nThe tree is empty...\n");
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;
            
            case 7:
                temp = getMIN( root );
                if( temp )
                    printf("\nSMALLEST value in the binary tree currently is :  %d",temp->data);
                else
                    printf("\nThe tree is empty...\n");
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;

            case 8:
                temp = getMAX( root );
                if( temp )
                    printf("\nLARGEST value in the binary tree currently is :  %d",temp->data);
                else
                    printf("\nThe tree is empty...\n");
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;
            
            case 9:
                printf("\nEnter the integer value that you want to delete :  ");
                scanf("%d",&value);
                if( !searchBTNode_recur( root, value ) )
                    printf("\nThe specific value does not exist in the Binary Tree.\n");
                else
                {
                    root = deleteBTNode_recur( root, value );
                    node_count -= 1;
                    printf("\nThe specified value/node has been deleted from the Binary Tree Successfully.\n");
                }
                printf("\nPress Any Key to continue...\n\n");
                getch();
                break;

            case 10:
                system("cls");
                getch();
                break;

            case 11:
                printf("\nPress Any Key to exit...");
                getch();
                exit(0);

            default:
                printf("\nInvalid Choice Entry. \nPress Any key to get the main menu and try again...\n\n");
                getch();
        }
    }
    return 0;
}