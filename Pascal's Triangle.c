#include<stdio.h>
int ft(int);
int mCr(int,int);
void main()
{
    int n,m,r,i,j;
    printf("Enter the number of rows of star pattern you want:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1,r=0,m=i-1;j<=2*n-1;j++)
            if(j>n-i&&j<n+i)
                if(n%2==1)
                    if(i%2==1&&j%2==1)
                        printf("%d ",mCr(m,r)),r++;
                    else if(i%2==0&&j%2==0)
                        printf("%d ",mCr(m,r)),r++;
                    else
                        printf("  ");
                else
                    if(i%2==1&&j%2==0)
                        printf("%d ",mCr(m,r)),r++;
                    else if(i%2==0&&j%2==1)
                        printf("%d ",mCr(m,r)),r++;
                    else
                        printf("  ");
            else
                printf("  ");
        printf("\n");
    }
}

int mCr(int n,int r)
{
    int comb;
    comb=ft(n)/(ft(r)*ft(n-r));
    return(comb);
}

int ft(int r)
{
    int fact;
    for(fact=1;r;r--)
        fact*=r;
    return(fact);
}
