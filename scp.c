

#include<stdio.h>
void put()
{
         system(" scp  /usr/local/project/client1.xml root@192.168.0.243:/home/client1.xml");
}
void get()
{
         system(" scp root@192.168.0.243:/home/client1.xml /usr/local/project/ ");
}
void main()
{
        //put();
        get();
        //system(" scp root@192.168.0.243:/home/createXml.xml /usr/local/project/createXml.xml");
}
