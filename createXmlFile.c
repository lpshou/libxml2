#include<stdio.h>
#include<string.h>
#include<libxml/parser.h>
#include<libxml/tree.h>
#define NumOfBucket 3
#define NumOfObj 4
void createXmlFile(xmlChar* rootName);
void main()
{
    xmlChar * str =BAD_CAST"client1";
    createXmlFile(str);
}
void createXmlFile(xmlChar* rootName)
{

    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
    xmlNodePtr root_node = xmlNewNode(NULL,(xmlChar*)rootName);

    //设置根节点
    xmlDocSetRootElement(doc,root_node);

    //直接在根节点中创建节点
    int i =0;
    int j=0;
    xmlNodePtr node,nodeObj;
    for (i=0;i<NumOfBucket;++i)
    {
        char temp[2];
        char tmp[50];
        sprintf(temp,"%d",i+1);
        strcpy(tmp,"buc");
        strcat(tmp,temp);
        node = xmlNewTextChild(root_node,NULL,BAD_CAST(tmp),NULL);
        for (j=0;j<NumOfObj;++j)
        {
            char objtmp[50];
            char objtemp[2];
            sprintf(objtemp,"%d",j+1);
            strcpy(objtmp,"obj");
            strcat(objtmp,objtemp);
            xmlNewTextChild(node,NULL,BAD_CAST(objtmp),NULL);
        }

    }

    //创建一个节点，设置其内容和属性，然后加入根节点
    /* xmlNodePtr node = xmlNewNode(NULL,BAD_CAST"buc4");
     xmlAddChild(root_node,node);

     xmlNodePtr node1 = xmlNewNode(NULL,BAD_CAST"obj1");
     xmlAddChild(node,node1);
     xmlNodePtr node2 = xmlNewNode(NULL,BAD_CAST"obj2");
     xmlAddChild(node,node2);
     xmlNodePtr node3 = xmlNewNode(NULL,BAD_CAST"obj3");
     xmlAddChild(node,node3);*/

    //存储xml文档
    xmlChar str[50];
    strcpy(str,rootName);
    strcat(str,".xml");
    int nRel = xmlSaveFile(str,doc);
    if (nRel!=-1)
    {
        printf("%s is create size is:%d\n",(char *)str,nRel);
    }
    xmlFreeDoc(doc);
}
