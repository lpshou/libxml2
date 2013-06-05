#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#define BUFES PIPE_BUF
char * ExtractIP(char *path)
{
        FILE *fp;
        char cmd[100]="cat ";
        strcat(cmd,"/usr/local/project/cacheFile.txt |");
        strcat(cmd," grep ");
        strcat(cmd,path);
        strcat(cmd," |cut -f3");
        char buf[BUFES];

        fp = popen(cmd,"r");
        while((fgets(buf,BUFES,fp))!=NULL)
                printf("%s",buf);
        pclose(fp);
}
void main()
{
        char path[50]="client1/buc1/obj2";
        ExtractIP(path);
}
