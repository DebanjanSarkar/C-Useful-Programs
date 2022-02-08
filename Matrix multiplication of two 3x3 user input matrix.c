#include<stdio.h>

int main(void)
{
    int a[3][3], b[3][3], c[3][3], i, j, k, term;
    printf("Enter values in the first matrix:\n");
    for( i=0 ; i<=2; i++)
        for( j=0 ; j<=2 ; j++)
            scanf("%d",&a[i][j]);
    printf("Enter values in the second matrix:\n");
    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
            scanf("%d",&b[i][j]);
    
    printf("Matrix multiplication result of the above two matrix:\n\n");

    for( i=0 ; i<=2 ; i++)
    {
        for( j=0 ; j<=2 ; j++)
        {
            term = 0;
            for( k=0 ; k<=2 ; k++)
            {
                term += a[i][k] * b[k][j];
            }
            printf("%d  ",term);
        }
        printf("\n");
    }

    return 0;
}
