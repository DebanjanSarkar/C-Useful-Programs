#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

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

int main(void)
{
    struct heap *hp=NULL;
    int *arr, arrSize, i, choice, value;
    printf("This is a program to perform various operations on/using MAX Heap ADT...\n");
    printf("Enter the number of integers you want to enter into the array, to simulate a fixed-capacity MAX Heap from it: ");
    scanf("%d",&arrSize);
    fflush(stdin);
    if( arrSize<1 )
    {
        printf("Number of integers in array cannot be %d \nPress Any key to terminate.\n",arrSize);
        getch();
        exit(1);
    }
    arr = (int*)calloc(arrSize,sizeof(int));
    printf("\nEnter %d integers:-\n",arrSize);
    for(i=0;i<arrSize;i++)
        scanf("%d", (arr+i) );
    while(1)
    {
        printf("\n\nFollowing are the operations that can be performed:-\n");
        printf("1. Build a MAX Heap using the provided array of integers.\n");
        printf("2. Insert data into the MAX Heap.\n");
        printf("3. Extract and Delete data from the MAX Heap.\n");
        printf("4. Show the current state of heap.\n");
        printf("5. Remove the heap and exit.\n\n");
        printf("Enter your choice:   ");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1:
                    hp = buildHeap_max(arr,arrSize);
                    printf("MAX Heap has been created successfully with the provided array of integers.\n");
                    printf("\nPress Any key to get the main menu.\n\n");
                    getch();
                    break;

            case 2:
                    if( hp == NULL )
                        printf("\nNo heap has been created till now. \nRun Operation 1 once, prior to this step.\n");
                    else if( hp->count == hp->capacity )
                        printf("\nThe Heap is currently full. \nInsertion is possible after deletion of at least one value.\n");
                    else
                    {
                        printf("\nEnter the value which you want to get inserted into the heap:  ");
                        scanf("%d",&value);
                        fflush(stdin);
                        insertIntoHeap_max(hp,value);
                        printf("\n%d has been successfully inserted into the MAX Heap.\n");
                    }
                    printf("\nPress Any key to get the main menu.\n\n");
                    getch();
                    break;

            case 3:
                    if( hp == NULL )
                        printf("\nNo heap has been created till now. \nRun Operation 1 once, prior to this step.\n");
                    else if( hp->count == 0 )
                        printf("\nThe Heap is currently empty. \nDeletion is possible only if at least one value is present in it.\n");
                    else
                    {
                        value = deleteFromHeap_max(hp);
                        printf("The data deleted from the Max heap is:  %d",value);
                    }
                    printf("\nPress Any key to get the main menu.\n\n");
                    getch();
                    break;

            case 4:
                    if( hp == NULL )
                        printf("\nNo heap has been created till now. \nRun Operation 1 once, prior to this step.\n");
                    else if( hp->count == 0 )
                        printf("\nThe Heap is currently empty. \nNo values to print.\n");
                    else
                    {
                        printf("\n");
                        for( i=0 ; i<hp->count ; i++ )
                            printf(" %d ",hp->arr[i]);
                        printf("\n");
                    }
                    printf("\nPress Any key to get the main menu.\n\n");
                    getch();
                    break;

            case 5:
                    removeHeap(hp);
                    printf("\nPress any key to exit...\n");
                    getch();
                    exit(0);

            default:
                    printf("\nInvalid choice entry.\nPress Any key to get the main menu and try again.\n\n");
                    getch();
        }
    }
}