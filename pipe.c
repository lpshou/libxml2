#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<limits.h>
#include<string.h>
#define BUFES PIPE_BUF
int main()
{
        FILE *fp;
        char cmd[100]="cat ";
        strcat(cmd,"/usr/local/project/cacheFile.txt |");
        strcat(cmd," grep  -o 192.168.0.18");
        char buf[BUFES];

        fp = popen(cmd,"r");
        while((fgets(buf,BUFES,fp))!=NULL)
                printf("%s",buf);
        pclose(fp);
        exit(0);
}
