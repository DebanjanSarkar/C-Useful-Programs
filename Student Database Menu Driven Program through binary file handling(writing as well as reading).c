/*
    Student Database Menu Driven Program through binary file management(reading and writing records).
    By DEBANJAN SARKAR
    DATED:- 04 JULY, 2021

*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

struct Student
{
    long long int roll_no;
    char name[25];
    float CGPA;
    char stream[20];
};

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

struct Student input_student_data(int i)
{
    struct Student sr;
        if(i%10==1)
            printf("Enter the details of the %dst student:\n",i);
        else if(i%10==2)
            printf("Enter the details of the %dnd student:\n",i);
        else if(i%10==3)
            printf("Enter the details of the %drd student:\n",i);
        else
            printf("Enter the details of the %dth student:\n",i);
        printf("Enter roll no:\n");
        scanf("%lli",&sr.roll_no);
        printf("Enter name:\n");
        fflush(stdin);
        gets(sr.name);
        printf("Enter CGPA\n");
        scanf("%f",&sr.CGPA);
        printf("Enter stream:\n");
        fflush(stdin);
        gets(sr.stream);
        printf("\n");
        return(sr);
}

void display_student_data(struct Student sr,int y)
{
    int x=0;
    gotoxy(x,y);
    printf("%lli",sr.roll_no);
    x+=30,gotoxy(x,y);
    printf("%s",sr.name);
    x+=30,gotoxy(x,y);
    printf("%0.2f",sr.CGPA);
    x+=30,gotoxy(x,y);
    printf("%s",sr.stream);

}

int main()
{
    int choice,n,i,j,x,y;
    struct Student sr;
    FILE *fp;
    printf("This is a program to get record of student, and store it into a file:\n");
    while(1)
    {
        system("cls");
        printf("Enter your choice:\n1. Enter records of student in the file.\n2. Read records of students from the file.\n3. Exit\n\n");
        scanf("%d",&choice);
        system("cls");
        switch(choice)
        {
            case 1:
                printf("How many student records you want to add to the file:\n");
                scanf("%d",&n);
                if(n<0)
                    n=-n;
                fp=fopen("./student_data.bin","ab");
                for(i=1;i<=n;i++)
                {
                    sr=input_student_data(i);
                    fwrite(&sr,sizeof(sr),1,fp);
                }
                fclose(fp);
                printf("\n%d students record were successfully written into the file. Press any key to continue:\n",n);
                getch();
                break;

            case 2:
                printf("\nEnter your choice:\n1. Show all the records available in the file.\n2. Show specific set of records.\n\n");
                scanf("%d",&n);
                fp=fopen("./student_data.bin","rb");
                if(fp==NULL)
                {
                    printf("File not found.\n");
                    exit(1);
                }
                system("cls");
                switch(n)
                {
                    case 1:
                        x=0,y=0;
                        gotoxy(x,y);
                        printf("Roll No.");
                        x+=30,gotoxy(x,y);
                        printf("NAME");
                        x+=30,gotoxy(x,y);
                        printf("CGPA");
                        x+=30,gotoxy(x,y);
                        printf("Stream");
                        y+=2;
                        while(fread(&sr,sizeof(sr),1,fp))
                            display_student_data(sr,y),y++;
                        printf("\n\nPress any key to continue:");
                        getch();
                        break;

                    case 2:
                        x=0,y=6;
                        printf("From which record you want your custom list to start(Enter the record number)\n");
                        scanf("%d",&n);
                        if(n<0)
                            n=-n;
                        printf("How many records you want to get displayed:\n");
                        scanf("%d",&i);
                        if(i<0)
                            i=-i;
                        gotoxy(x,y);
                        printf("Roll No.");
                        x+=30,gotoxy(x,y);
                        printf("NAME");
                        x+=30,gotoxy(x,y);
                        printf("CGPA");
                        x+=30,gotoxy(x,y);
                        printf("Stream");
                        y+=2;
                        n=(n-1)*sizeof(struct Student);
                        fseek(fp,n,SEEK_SET);
                        while(i>0)
                        {
                            if(fread(&sr,sizeof(sr),1,fp))
                            {
                                display_student_data(sr,y);
                                i--,y++;
                            }
                            else
                                break;
                        }
                        printf("\n\nPress any key to continue:");
                        getch();
                        break;

                    default:
                        x=0,y=0;
                        gotoxy(x,y);
                        printf("Roll No.");
                        x+=30,gotoxy(x,y);
                        printf("NAME");
                        x+=30,gotoxy(x,y);
                        printf("CGPA");
                        x+=30,gotoxy(x,y);
                        printf("Stream");
                        y+=2;
                        while(fread(&sr,sizeof(sr),1,fp))
                            display_student_data(sr,y),y++;
                        printf("\n\nPress any key to continue:");
                        getch();
                        break;
                }
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice. Press any key to try again.\n");
                getch();
        }
    }
}
