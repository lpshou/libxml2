
/*
*compiler command:
*gcc -I/usr/local/include/ -L/usr/local/lib -ltokyocabinet -ltokyotyrant -o *tt tt.c
*/

#include<tcrdb.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
int main(int argc,char *argv[])
{
        TCRDB *rdb;
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

        tcrdbclose(rdb);
        return 0;
}
