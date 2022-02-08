#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap2string(char *a,char *b)
{
    char temp[20];
    strcpy(temp,a);
    strcpy(a,b);
    strcpy(b,temp);
}

int main()
{
    char **str_tla;
    int nos,i,j;
    printf("This is a program to sort strings in Dictionary order.\nEnter how many strings you want to input to get them sorted:\n");
    scanf("%d",&nos);
    str_tla=(char**)calloc(nos,sizeof(char*));
    for(i=0;i<=nos;i++)
        str_tla[i]=(char*)calloc(20,sizeof(char));
    printf("Enter the list of string(one string per line), that you want to get sorted:\n");
    for(i=0;i<=nos;i++)
        gets(str_tla[i]);
    for(i=0;i<nos;i++)
        for(j=i+1;j<=nos;j++)
            if(strcmp(str_tla[i],str_tla[j])==1)
                swap2string(str_tla[i],str_tla[j]);
    printf("\n\nThe above input strings in sorted order are as follows:\n");
    for(i=0;i<=nos;i++)
        puts(str_tla[i]);
    return 0;
}
