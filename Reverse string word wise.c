#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_words(char *s)
{
    int i,now;
    for(i=0,now=0;s[i]!='\0';i++)
        if(s[i]==' '||s[i]==9)
            if(s[i+1]!=' '&&s[i+1]!=9)
                now++;
    return(now+1);
}

void left_swap(char *s,int i)                                   //once called, left_swap() shifts all the characters in the passed array by one block to the left.
{
    do
    {
        s[i]=s[i+1];
        i++;
    }while(s[i+1]!='\0');
    s[i]='\0';
}

void right_swap(char *s,int start)                               //once called, lright_swap() shifts all the characters in the passed array by one block to the right.
{
    int end, i;
    for(i=start;s[i]!='\0';i++);
    end=i;
    s[end+1]='\0';
    for(i=end;i>start;i--)
        s[i]=s[i-1];
    s[start]=' ';
}

void fix_string(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++)
    {
        if((s[i]==' '||s[i]==9)&&(s[i+1]==' '||s[i+1]==9))          //remove adjacent multiple spaces and tabs.
            left_swap(s,i+1),i--;
        else if((s[i]==','&&s[i+1]!=' ')||(s[i]=='?'&&s[i+1]!=' ')||(s[i]=='!'&&s[i+1]!=' '))
            right_swap(s,i+1);
    }
}

void Reverse_String(char *s,char **tlp)
{
    int i,j,wn;                                                     //wn stands for word number.
    char temp[20];
    for(i=0,wn=0;s[i]!='\0';wn++,i++)
    {
        for(j=0;s[i]!=' '&&s[i]!='\0';j++,i++)
            temp[j]=s[i];
        temp[j]='\0';
        strcpy(tlp[wn],temp);
    }
    wn--;
    s[0]='\0';
    for(wn=wn;wn>=0;wn--)
    {
        strcat(s,tlp[wn]);
        strcat(s," ");
    }
}

int main(void)
{
    int i,now;
    char str[500],**tlp;
    printf("Enter a string to get it reversed word wise:\n");
    gets(str);
    fix_string(str);                                          //  fix_string() function removes extra spaces and tabs between words, and puts space after comma,exclaimation and question mark, if not present.
    now=count_words(str);
    tlp=(char**)calloc(now,sizeof(char*));
    for(i=0;i<=now;i++)
        tlp[i]=(char*)calloc(20,sizeof(char));
    Reverse_String(str,tlp);
    puts(str);
    return 0;
}
