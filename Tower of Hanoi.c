#include<stdio.h>
#include<windows.h>

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main()
{
    int n,i;
    for(i=2;i<=12;i++)
    {
        gotoxy(25,i);
        if(i<=10)
            printf("    |_|                                      |_|                                      |_|\n");
        else if(i==11)
            printf("---------------------------------------------------------------------------------------------\n");
        else
            printf("     A                                        B                                        C\n\n\n\n");
    }
    printf("This is a problem of Tower Of Hanoi. Above you can see 3 rods named A, B, C.How many disks you want to be there in A, that you want to get moved to C:\n");
    scanf("%d",&n);
    printf("Abiding the rules of Tower of Hanoi, the steps to move %d disks from A to B is:\n\n\n",n);
    TOH(n,'A','B','C');
    return 0;
}

void TOH(int n,char beg,char aux,char end)
{
    if(n>1)
        TOH(n-1,beg,end,aux);
    if(n>=1)
        printf("%c      to      %c\n",beg,end);
    if(n>1)
        TOH(n-1,aux,beg,end);
}
