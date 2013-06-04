/*
*compiler command:
*gcc -I/usr/local/include/ -L/usr/local/lib -ltokyocabinet -ltokyotyrant -o ttnet ttnet.c
*/
#include<tcrdb.h>
#include<stdlib.h>
#include"global.h"
#include"md_type.h"
bool PutValue(void *key,void *value)
{
    TCRDB*rdb;
    rdb = tcrdbnew();

    int ksz = strlen((char*)key);
    int vsz = sizeof(Meta_Data);
    if (!tcrdbopen(rdb,"192.168.0.151",1987))
    {
        printf("cannot open \n");
        exit(-1);
    }
    if (!tcrdbput(rdb,key,ksz,value,vsz))
    {
        printf("cannot put\n");
        return false;
    }
    else
    {
        printf("succeed put\n");
        return true;
    }
}

int GetValue(void *key,void *value)
{
    TCRDB*rdb;
    void *v;
    int ksz = strlen((char*)key);
    int vsz = sizeof(Meta_Data);
    rdb = tcrdbnew();
    if (!tcrdbopen(rdb,"192.168.0.151",1987))
    {
        printf("cannot open \n");
        exit(-1);
    }
    v = tcrdbget(rdb,key,ksz,&vsz);
    if (!v)
    {
        printf("key %s doesnot exists\n",(char *)key);
        return -1;
    }
    printf("value: %s\n",(char *)v);
    memcpy(value,v,vsz);
    tcrdbclose(rdb);
    return 0;

}
int md_get(char *path,Meta_Data * md)
{
    return GetValue((void*)path,(void*)md);
}


int md_put(char * path,Meta_Data * meta_data)
{
    return PutValue((void*)path,(void*)meta_data);
}

void main()
{
    Meta_Data *metaData = (Meta_Data *)malloc(sizeof(Meta_Data));
    Meta_Data *meta1 = (Meta_Data *)malloc(sizeof(Meta_Data));
    strcpy(metaData->replica[0].rep_ip,"192.168.0.18");
    char *key = "123456";
    //char *value1="just for test";
    md_put(key,metaData);
    md_get(key,meta1);

    printf("the value  is %s\n",meta1->replica[0].rep_ip);
}
