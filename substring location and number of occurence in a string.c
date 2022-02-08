#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* input_var_string(void)
{
    char *p,*q,ch;
    int i=0,l=1;
    ch=getche();
    p=malloc(l);
    p[i]='\0';
    while(ch!=13)
    {
        if(p[i]=='\0')
            p[i]=ch;
        q=malloc(l+1);
        for(i=0;i<l;i++)
            q[i]=p[i];
        q[i]='\0';
        free(p);
        ch=getche();
        l++;
        p=malloc(l);
        for(i=0;i<l;i++)
            p[i]=q[i];
        free(q);
        i--;
    }
    q=malloc(l+1);
    for(i=0;i<l;i++)
        q[i]=p[i];
    puts(q);
    return(q);

}

int* locate(char *word,char *str)
{
    char *temp;
    int low,i,j,k,too=0,*ioo,i2=1;                                //low stands for length of word, too stands for times of occurrence, ioo stands for index of occurence.
    low=strlen(word);
    temp=(char*)malloc(low+1);
    for(i=0;str[i+low-1]!='\0';i++)
    {
        for(j=0,k=i;j<low;j++,k++)
        {
            temp[j]=str[k];
        }
        temp[j]='\0';
        if(strcmp(temp,word)==0)
                too++;
    }
    if(too==0)
        return(-1);
    else
    {
        ioo=(int*)calloc(too+1,sizeof(int));                      //Here, the array which stores indexes of occurence is given one extra block, as in the first block we will store the time of occurence only.This is done because we can return only one value from a function once called, thus by returning the index of occurence base address we can get the values of bothe the indexes of occurence and the times of occurence.
        ioo[0]=too;
        for(i=0;str[i+low-1]!='\0';i++)
        {
            for(j=0,k=i;j<low;j++,k++)
            {
                temp[j]=str[k];
            }
            temp[j]='\0';
            if(strcmp(temp,word)==0)
                ioo[i2]=i,i2++;
        }

    }
    return(ioo);
}


int main()
{
    char *str,*word;
    int *location,i;
    printf("This is a program to locate a given word in a string, and get the index number of the location.\nEnter the string:\n");
    str=input_var_string();
    printf("Enter the word you want to locate:\n");
    word=input_var_string();
    location=locate(word,str);                 //first argument is the word to be located, and the second argument is in which string it is to be located.
    if(location==-1)
        printf("\"%s\" does not exist in the input string.",word);
    else
    {
        printf("\"%s\" occurs %d times in the above input string.\nIndex of occurences are as follows:\n",word,location[0]);
        for(i=1;i<=location[0];i++)
            printf("Occurrence no. %d   in the   index  no  %d\n",i,location[i]);
    }
    return 0;
}
