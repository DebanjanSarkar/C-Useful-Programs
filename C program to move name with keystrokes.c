#include<stdio.h>
#include<windows.h>
void gotoxy(int,int);
int main()
{
    int x,y;
    char ch;
    scanf("%d%d",&x,&y);
    system("cls");
    gotoxy(x,y);
    printf("Debanjan Sarkar.");
    while(1)
    {
        ch=getch();
        if(ch==72)
            y--;
        else if(ch==80)
            y++;
        else if(ch==75)
            x--;
        else if(ch==77)
            x++;
        else if(ch==27)
            break;
        system("cls");
        gotoxy(x,y);
        printf("Debanjan Sarkar.");
    }
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
