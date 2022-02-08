#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>

int main()
{
    struct stat fileinfo;
    time_t today;
    char fpath[100],ajker_din[30];
    int fd;
    FILE *fp;
    printf("This is a program to print status of any file specified. Enter the path of the file:\n");
    scanf("%s",fpath);
    time(&today);
    strcpy(ajker_din,ctime(&today));
    fp=fopen(fpath,"r");
    fd=fileno(fp);
    fstat(fd,&fileinfo);
    printf("\n\n\nToday is %s\n\n\n",ajker_din);
    printf("Size of the file is %ld bytes\n",fileinfo.st_size);
    printf("Mode of the file: %o\n",fileinfo.st_mode);
    printf("File was created on %s\n",ctime(&fileinfo.st_ctime));
    printf("File was last accessed on %s\n",ctime(&fileinfo.st_atime));
    printf("File was last modified on %s.\n",ctime(&fileinfo.st_mtime));
    fclose(fp);
    return 0;
}
