/*
This program contains functions to sort integers in ascending order, using the following algorithms.
1. BUBBLE SORT
2. SELECTION SORT
3. INSERTION SORT
4. QUICK SORT
5. HEAP SORT
6. MERGE SORT

Also, there is a driver code, with which this program can be executed and one can see the functions actually working on the provided array by the user.
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Bubble Sort
//--------------------------------------------------------------------------
void bubble_sort(int *arr, int arrSize)
{
    int temp, i, pass, swaps;
    for( pass=1 ; pass<=arrSize-1 ; pass++ )
    {
        swaps = 0;
        for( i=0 ; i<arrSize-pass ; i++ )
        {
            if(arr[i]>arr[i+1])
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swaps++;
            }
        }
        if(swaps==0)
            break;
    }
}

//Selection Sort
//--------------------------------------------------------------------------
int min_location(int *arr, int beg, int end)
{
    int i, min = arr[beg], loc = beg;
    for( i = beg+1 ; i<=end ; i++ )
    {
        if( arr[i]<min )
        {
            min = arr[i];
            loc = i;
        }
    }
    return(loc);
}

void selection_sort(int *arr, int arrSize)
{
    int temp, i, loc;
    for( i=0 ; i<=arrSize-2 ; i++ )
    {
        loc = min_location(arr,i,arrSize-1);
        temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
    }
}

//Insertion Sort
//-----------------------------------------------------------------------------
void insertion_sort(int *arr, int arrSize)
{
    int i, j, temp;
    for( i=1 ; i<arrSize ; i++ )
    {
        temp = arr[i];
        for( j=i-1 ; j>=0 && temp<arr[j] ; j-- )
            arr[j+1] = arr[j];
        arr[j+1] = temp;
    }
}

//Quick Sort
//-----------------------------------------------------------------------------

    //Stack-----------------------------
    //----------------------------------
    
    struct node
    {
        int data;
        struct node *next;
    };

    struct node* createNode(void)
    {
        struct node *np;
        np = (struct node*)malloc(sizeof(struct node));
        np->next = NULL;
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
    //------------------------------------

int quick(int *arr, int beg, int end)
{
    int loc=beg, left=beg, right=end, i, j, temp;
    while(1)
    {
        //Scanning from right to left
        for( i=right ; arr[loc]<=arr[right] && loc!=right ; i--)
            right -= 1;
        if( loc==right )
            return(loc);
        else if( arr[loc]>arr[right] )
        {
            temp = arr[loc];
            arr[loc] = arr[right];
            arr[right] = temp;
            loc = right;
        }
        //Scanning from left to right
        for( i=left ; arr[i]<=arr[loc] && left!=loc ; i++)
            left += 1;
        if( left == loc )
            return(loc);
        else if( arr[left]>arr[loc] )
        {
            temp = arr[loc];
            arr[loc] = arr[left];
            arr[left] = temp;
            loc = left;
        }
    }
}

void quick_sort(int *arr, int arrSize)
{
    struct node *LOW=NULL, *UP=NULL;
    int beg, end, loc;
    if(arrSize>1)
    {
        push(&LOW,0);
        push(&UP,arrSize-1);
    }
    while( LOW!=NULL )
    {
        beg = pop(&LOW);
        end = pop(&UP);
        loc = quick(arr, beg, end);
        if( beg < loc-1 )
        {
            push(&LOW,beg);
            push(&UP,loc-1);
        }
        if( end > loc+1 )
        {
            push(&LOW,loc+1);
            push(&UP,end);
        }
    }
}

//HEAP Sort
//-----------------------------------------------------------------------------
    //HEAP ADT and Functions
    //--------------------------------------------------
    struct heap
    {
        int *arr;
        int capacity, count;
    };

    struct heap* createHeap(int capacity)
    {
        if(capacity>0)
        {
            struct heap *hp;
            hp = (struct heap*)malloc(sizeof(struct heap));
            hp->count = 0;
            hp->capacity = capacity;
            hp->arr = (int*)calloc(capacity,sizeof(int));
            return(hp);
        }
        else
            return NULL;
    }

    void insertIntoHeap_max(struct heap *hp, int data)              //operation applicable on MAX HEAP
    {
        int parent_index, child_index, temp;
        //hp->count can be used here as the index which is empty, and is to be filled next.
        if( hp->count < hp->capacity )
        {
            hp->arr[hp->count] = data;        //inserting data at the end of heap, initially.
            
            //  Heapification:
            //------------------
            child_index = hp->count;
            if(child_index>0)
                parent_index = (child_index-1)/2;
            while( child_index>0 && hp->arr[parent_index]<hp->arr[child_index] )
            {
                temp = hp->arr[parent_index];
                hp->arr[parent_index] = hp->arr[child_index];
                hp->arr[child_index] = temp;
                child_index = parent_index;
                parent_index = (child_index-1)/2;
            }
            hp->count += 1;
        }
    }

    struct heap* buildHeap_max(int *arr, int arrSize)           //operation applicable on MAX HEAP
    {
        if(arrSize>0)
        {
            struct heap *hp;
            int i;
            hp = createHeap(arrSize);
            for( i=0 ; i<arrSize ; i++)
            {
                insertIntoHeap_max(hp,arr[i]);
            }
            return(hp);
        }
        else
            return NULL;
    }

    int deleteFromHeap_max(struct heap *hp)                         //operation applicable on MAX HEAP
    {
        int data, parent_index, child_index1, child_index2, temp, greater_index;
        if( hp->count>0 )
        {
            data = hp->arr[0];
            hp->count--;
            hp->arr[0] = hp->arr[hp->count];
            parent_index = 0;
            child_index1 = 1;
            child_index2 = 2;
            while( child_index1<=hp->count )
            {
                if( child_index2<=hp->count )
                    greater_index = hp->arr[child_index1] > hp->arr[child_index2] ? child_index1 : child_index2;
                else
                    greater_index = child_index1;
                if( hp->arr[parent_index] < hp->arr[greater_index] )
                {
                    temp = hp->arr[parent_index];
                    hp->arr[parent_index] = hp->arr[greater_index];
                    hp->arr[greater_index] = temp;
                    parent_index = greater_index;
                    child_index1 = 2 * parent_index + 1;
                    child_index2 = 2 * parent_index + 2;
                }
                else
                    break;
            }
            return(data); 
        }
        else
            return(-1);
    }

    struct heap* removeHeap(struct heap *hp)
    {
        free(hp->arr);
        free(hp);
        return(NULL);
    }

void heap_sort(int *arr, int arrSize)
{
    struct heap *hp;
    int i;
    if( arrSize>1 )
    {
        hp = buildHeap_max(arr,arrSize);
        for( i = arrSize-1 ; i>=0 ; i-- )
            arr[i] = deleteFromHeap_max(hp);
        removeHeap(hp);
    }
}

//-----------------------------------------------------------------------------

//Merge Sort
//-----------------------------------------------------------------------------

void merge_ascending(int *arr, int beg, int mid, int end)
{
    if( beg<=mid && mid<end )
    {
        int *aux_arr, size, i, j, k;
        size = end - beg + 1;
        aux_arr = (int*)calloc(size,sizeof(int));
        i = beg;                    //tracks the index of left subarray
        j = mid + 1;                //tracks the index of right subarray
        k = 0;                      //tracks the index of auxilliary array

        //loop that assigns smaller values accordingly into aux_arr, when both sub arrays have values left in them
        while( i<=mid && j<=end )
        {
            if( arr[i] < arr[j] )
            {
                aux_arr[k] = arr[i];
                k++;
                i++;
            }
            else
            {
                aux_arr[k] = arr[j];
                k++;
                j++;
            }
        }

        //loop that assigns residual values of left subarray into aux_arr when right subarray gets exhausted
        while( i<=mid )
        {
            aux_arr[k] = arr[i];
            i++;
            k++;
        }

        //loop that assigns residual values of right subarray into aux_arr when left subarray gets exhausted
        while( j<=end )
        {
            aux_arr[k] = arr[j];
            j++;
            k++;
        }

        //loop that reassigns all the values from the auxilliary array into the main sub-array in sorted order
        for( i=0 ; i<size ; i++ )
            arr[beg+i] = aux_arr[i];
        
        //freeing up the space occupied by the auxilliary array.
        free(aux_arr);
    }
}

void merge_sort_recursive(int *arr, int beg, int end)
{
    int mid;
    if( beg<end )
    {
        mid = (beg+end)/2;
        merge_sort_recursive( arr , beg , mid );
        merge_sort_recursive( arr , mid+1 , end );
        merge_ascending(arr,beg,mid,end);
    }
}


//Driver Code
//-----------------------------------------------------------------------------
int main(void)
{
    int *arr, n, i, choice;
    printf("This program takes an array of integers, and sorts them according to the algorithm you select from the menu.\n");
    printf("Thus, for the same set of integers, you can apply sorting in ascending order, to compare the time taken by them.\n");
    printf("This program does not apply any time functions to get time taken accurately, so you need to compare the time for larger datasets, for which time taken to sort them gets considerably more, so that can be compared.\n");
    printf("\n\nEnter how many integers you want to input to get them sorted in ASCENDING ORDER: ");
    scanf("%d",&n);
    fflush(stdin);
    arr = (int*)calloc(n,sizeof(int));
    printf("\nEnter %d integers:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",(arr+i));
    fflush(stdin);
    /*
    Samples for testing during coding:-
    n=10, 4 14 12 87 91 44 56 2 -18 47

    n=10, 1 4 8 19 21 29 36 57 65 71

    n=10, 97 81 71 66 50 45 34 28 12 8
    */
    printf("\n\nWhich algorithm do you want to apply to sort the integers:-\n");
    printf("1. BUBBLE SORT\n");
    printf("2. SELECTION SORT\n");
    printf("3. INSERTION SORT\n");
    printf("4. QUICK SORT\n");
    printf("5. HEAP SORT\n");
    printf("6. MERGE SORT\n");
    printf("\nEnter your choice:  ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                bubble_sort(arr,n);
                printf("\nThe integers have been sorted using BUBBLE SORT algorithm successfully.\n");
                break;

        case 2:
                selection_sort(arr,n);
                printf("\nThe integers have been sorted using SELECTION SORT algorithm successfully.\n");
                break;

        case 3:
                insertion_sort(arr,n);
                printf("\nThe integers have been sorted using INSERTION SORT algorithm successfully.\n");
                break;

        case 4:
                quick_sort(arr,n);
                printf("\nThe integers have been sorted using QUICK SORT algorithm successfully.\n");
                break;

        case 5:
                heap_sort(arr,n);
                printf("\nThe integers have been sorted using HEAP SORT algorithm successfully.\n");
                break;

        case 6:
                merge_sort_recursive(arr, 0, n-1);
                printf("\nThe integers have been sorted using MERGE SORT algorithm successfully.\n");
                break;

        default:
                printf("\nInvalid choice entered. Try again restarting the program. \nPress Any Key to exit...");
                getch();
                exit(1);
    }

    printf("\n\nThe integers in sorted order are:\n");
    for(i=0;i<n;i++)
        printf(" %d ",arr[i]);
    return 0;
}