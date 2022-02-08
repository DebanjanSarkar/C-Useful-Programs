#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Here in this code, the getche() function stands for get character and echo it to the string using direct video output. Thus the input character can be
    viewed on the screen. Thus, if we directly try to print any screen after direct input of the characters, the string will be printed on the same line
    in which the characters are being viewed, as the characters are not actually printed on the screen, but we are just getting video image output of the
    characters. Thus, if we do not use the printf("\n"); function in input_var_string() function, the printing of the string after that will be just replaced
    int the place of the input string, and at a glance we will think that nothing has been printed as the string and the program is faulty. But this is not
    so, which is depicted by the line change in our target function.
*/

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
    printf("\n");                                       //This printf() is used here for a purpose.
    return(q);

}

int main()
{
    char *str;
    printf("This is a program to input variable length string from the user:\nInput any string(hit enter when you reach the end)\n");
    str=input_var_string();
    puts(str);
    return 0;
}
