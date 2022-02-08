#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/types.h>

void listobjects(char *,int,FILE*);

int main()
{
    char basepath[500],opfile[150];
    FILE *fp;
    int level=0;
    printf("This is a program that prints all the files and subfolders inside a folder recursively:\nEnter the base path of the directory:\n");
    fflush(stdin);
    gets(basepath);
    printf("Enter the path of the file in which you want to store the folder hierarchy:\n");
    fflush(stdin);
    gets(opfile);
    fp=fopen(opfile,"w");
    fprintf(fp,"%s\n",basepath);
    listobjects(basepath,level,fp);
    fclose(fp);
    return 0;
}

void listobjects(char *basepath,int level,FILE *fp)
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
        {
            fprintf(fp,"               ");
            printf("               ");
        }
        fprintf(fp,"%s\n",entry->d_name);
        printf("%s\n",entry->d_name);
        if(strcmp(entry->d_name,".")!=0&&strcmp(entry->d_name,"..")!=0)
        {
            strcpy(path,basepath);
            strcat(path,"/");
            strcat(path,entry->d_name);
        }
        listobjects(path,level,fp);
    }
    closedir(dirp);
}
