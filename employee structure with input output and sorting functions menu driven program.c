// structure usage and dynamic memory allocation.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct employee
{
    int empid;
    char name[35];
    float salary;       //    CTC in LPA, thus float
};

enum order
{
    ascending=0 , ASCENDING=0, a=0 , A=0, FORWARD=0, forward=0, descending=1, DESCENDING=1, backward=1 , BACKWARD=1, d=1 , D=1 , b=1 , B=1
};

void input_data( struct employee *ep )
{
    printf("Enter his/her employee id: ");
    fflush(stdin);
    scanf("%d",&ep->empid);
    printf("\nEnter the name of the employee: ");
    fflush(stdin);
    gets(ep->name);
    printf("Enter salary/CTC (in LPA): ");
    fflush(stdin);
    scanf("%f",&ep->salary);
    printf("\n\n");
}

void show_data( struct employee e )
{
    printf("Name: %s\nEmployee Id: %d\nSalary: %f lacs per annum.\n\n",e.name,e.empid,e.salary);
}

void swap_data( struct employee *p1 , struct employee *p2 )
{
    struct employee temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort_emp_empid( struct employee *p , int size, enum order ord )
{
    int i, j;
    if( ord==1 )
    {
        for(i=0;i<=size-2;i++)
            for(j=i+1;j<=size-1;j++)
                if( p[i].empid<p[j].empid )
                    swap_data( p+i , p+j );
    }
    else
    {
        for( i=0 ; i<=size-2 ; i++ )
            for( j=i+1 ; j<=size-1 ; j++ )
                if( p[i].empid > (p+j)->empid )
                    swap_data( p+i , p+j );
    }
}

void sort_emp_name( struct employee *p , int size , enum order ord )
{
    int i,j;
    char f[35], l[35];
    if(ord==1)
    {
        for(i=0;i<=size-2;i++)
            for(j=i+1;j<=size-1;j++)
            {
                strcpy(f,p[i].name);
                strcpy(l,p[j].name);
                strlwr(f);
                strlwr(l);
                if( strcmp( f , l ) == -1 )
                    swap_data( p+i , p+j );
            }
    }
    else
    {
        for(i=0;i<=size-2;i++)
            for(j=i+1;j<=size-1;j++)
            {
                strcpy(f,p[i].name);
                strcpy(l,p[j].name);
                strlwr(f);
                strlwr(l);
                if( strcmp( f , l ) == 1 )
                    swap_data( p+i , p+j );
            }
    }
}

void sort_emp_salary( struct employee *p , int size , enum order ord )
{
    int i,j;
    if(ord==1)
    {
        for( i=0 ; i<=size-2 ; i++ )
            for( j=i+1 ; j<=size-1 ; j++ )
                if( p[i].salary < p[j].salary )
                    swap_data( p+i , p+j );
    }
    else
    {
        for( i=0 ; i<=size-2 ; i++ )
            for( j=i+1 ; j<=size-1 ; j++ )
                if( p[i].salary > p[j].salary )
                    swap_data( p+i , p+j );
    }
}

int main(void)
{
    int n, i, choice;
    struct employee *ep;
    printf("Enter how many employees details you want to enter: ");
    scanf("%d",&n);
    ep = (struct employee*)calloc(n,sizeof(struct employee));
    for(i=0;i<n;i++)
    {
        printf("Enter details of employee number %d:-\n",i+1);
        input_data( ep+i );
    }
    while(1)
    {
        printf("\nEnter the operation you want to perform with the employee's data:\n1. Sort the employees data according to their employee id in ascending order.\n2. Sort the employees data according to their employee id in descending order.\n3. Sort the employees data according to their name in ascending order.\n4. Sort the employees data according to their name in descending order.\n5. Sort the employees data according to their salary in ascending order. \n6. Sort the employees data according to their salary in descending order.\n7. Show the employees data as it has been arranged. \n8. Exit.\n\n");
        fflush(stdin);
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                    sort_emp_empid(ep,n,a);
                    printf("\nRecords sorted successfully. Press any key to get main menu...\n");
                    getch();
                    break;
            case 2:
                    sort_emp_empid(ep,n,d);
                    printf("\nRecords sorted successfully. Press any key to get main menu...\n");
                    getch();
                    break;
            case 3:
                    sort_emp_name(ep,n,a);
                    printf("\nRecords sorted successfully. Press any key to get main menu...\n");
                    getch();
                    break;
            case 4:
                    sort_emp_name(ep,n,d);
                    printf("\nRecords sorted successfully. Press any key to get main menu...\n");
                    getch();
                    break;
            case 5:
                    sort_emp_salary(ep,n,a);
                    printf("\nRecords sorted successfully. Press any key to get main menu...\n");
                    getch();
                    break;
            case 6:
                    sort_emp_salary(ep,n,d);
                    printf("\nRecords sorted successfully. Press any key to get main menu...\n");
                    getch();
                    break;
            case 7:
                    for(i=0;i<n;i++)
                    {
                        printf("Employee #%d\n",i+1);
                        show_data( *(ep+i) );
                    }
                    getch();
                    break;
            case 8:
                    exit(0);
            default:
                    printf("Invalid choice has been selected. Try again...\n\n");
                    getch();
        }
    }
}
