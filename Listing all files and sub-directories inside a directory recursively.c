#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>

void listobjects(char *,int);

int main()
{
    char basepath[500];
    int level=0;
    printf("This is a program that prints all the files and subfolders inside a folder recursively:\nEnter the base path of the directory:\n");
    fflush(stdin);
    gets(basepath);
    listobjects(basepath,level);
	getch();
    return 0;
}

void listobjects(char *basepath,int level)
{
    DIR *dirp;
    struct dirent *entry;
    char path[1000];
    int i;
    dirp=opendir(basepath);
    if(dirp==NULL)
        return;
    else
        level++;
    while((entry=readdir(dirp))!=NULL)
    {
        for(i=1;i<=level;i++)
            printf("               ");
        printf("%s\n",entry->d_name);
        if(strcmp(entry->d_name,".")!=0&&strcmp(entry->d_name,"..")!=0)
        {
            strcpy(path,basepath);
            strcat(path,"/");
            strcat(path,entry->d_name);
        }
        listobjects(path,level);
    }
    closedir(dirp);
}
