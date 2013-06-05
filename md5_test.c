#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "md5.h"

int main()
{
    unsigned char str[]="/client1/buc1/obj1";
    int len=strlen(str);
    unsigned char md5sum[16]={0};
    unsigned char md5_str[33]={0};
    md5(str,len,md5sum);
    md5_2_str(md5sum,md5_str);
    printf("%s : %s\n",str,md5_str);
    return 0;
}
