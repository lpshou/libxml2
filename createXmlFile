#include<stdio.h>
#include<string.h>
#include<libxml/parser.h>
#include<libxml/tree.h>
void createXmlFile(xmlChar* rootName);
/*void main()
{
        xmlChar * str =BAD_CAST"root4";
        createXmlFile(str);
}*/
void createXmlFile(xmlChar* rootName)
{

        xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");
        xmlNodePtr root_node = xmlNewNode(NULL,(xmlChar*)rootName);

        //设置根节点
        xmlDocSetRootElement(doc,root_node);

        //直接在根节点中创建节点
        xmlNewTextChild(root_node,NULL,BAD_CAST"newNode1",BAD_CAST"new node1 content");
        xmlNewTextChild(root_node,NULL,BAD_CAST"newNode2",BAD_CAST"new node2 content");
        xmlNewTextChild(root_node,NULL,BAD_CAST"newNode3",BAD_CAST"new node3 content");

        //创建一个节点，设置其内容和属性，然后加入根节点
        xmlNodePtr node = xmlNewNode(NULL,BAD_CAST"client1");
        xmlNodePtr content = xmlNewText(BAD_CAST"client content");

        xmlAddChild(root_node,node);
        xmlAddChild(node,content);
        xmlNewProp(node,BAD_CAST"attribute",BAD_CAST"yes");

        xmlNodePtr node1 = xmlNewNode(NULL,BAD_CAST"bucket1");
        xmlAddChild(node,node1);
        xmlNodePtr node2 = xmlNewNode(NULL,BAD_CAST"bucket2");
        xmlAddChild(node,node2);

        xmlNodePtr node12 = xmlNewNode(NULL,BAD_CAST"obj1");
        xmlAddChild(node1,node12);
        xmlNodePtr node13 = xmlNewNode(NULL,BAD_CAST"obj2");
        xmlAddChild(node1,node13);


        //创建 一个儿子和孙子节点
        node = xmlNewNode(NULL,BAD_CAST"son");
        xmlAddChild(root_node,node);

        xmlNodePtr grandson = xmlNewNode(NULL,BAD_CAST"grandson");
        xmlAddChild(node,grandson);
        xmlAddChild(grandson,xmlNewText(BAD_CAST"this is a grandson node"));

        //存储xml文档
        xmlChar str[50];
        strcpy(str,rootName);
        strcat(str,".xml");
        int nRel = xmlSaveFile(str,doc);
        if(nRel!=-1)
        {
                printf("%s is create size is:%d\n",(char *)str,nRel);
        }
        xmlFreeDoc(doc);
}
