/*
*compiler command:
*gcc -I/usr/local/include/ -L/usr/local/lib -ltokyocabinet -ltokyotyrant -o *tt tt.c
*/

#include<tcrdb.h>
#include<stdlib.h>
char *GetValue(char *key)
{
        TCRDB*rdb;
        char *value;
        rdb = tcrdbnew();
        if(!tcrdbopen(rdb,"192.168.0.151",1987))
        {
                printf("cannot open \n");
                exit(-1);
        }
        value = tcrdbget2(rdb,key);
        if(value)
        {
                printf("the value of key %s is:%s\n",key,value);
                return value;
        }
        else
        {
                printf("key %s doesnot exists\n",key);
                return NULL;
        }
        tcrdbclose(rdb);
}

int main(int argc,char *argv[])
{

        char *value = GetValue("foo");
        printf("the value  is %s\n",value);
       /* TCRDB *rdb;
        int ecode;
        char *value;

        rdb = tcrdbnew();

        if(!tcrdbopen(rdb,"192.168.0.151",1987))
        {
                ecode = tcrdbecode(rdb);
                printf("cannot open \n");
        }

        if(!tcrdbput2(rdb,"foo","hop")||!tcrdbput2(rdb,"bar","step"))
        {
                printf("cannot put\n");
        }

        value = tcrdbget2(rdb,"foo");
        if(value)
        {
                printf("%s\n",value);
                free(value);
        }else{
                printf("cannot get\n");
        }

        tcrdbclose(rdb);*/
        return 0;
}
