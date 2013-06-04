#include<libxml/parser.h>
#include<stdio.h>
int parserXmlFile(char *rootName);
int listBucket(char *clientName);
int listObjectInBucket(char *rootName,char *BucketName);
int main()
{
    char *str = "client1.xml";
    char *bucketName = "buc2";
    listObjectInBucket(str,bucketName);
    //listBucket(str);
    //parserXmlFile(str);
    return 0;
}
//list object in bucket
int listObjectInBucket(char *rootName,char *BucketName)
{
    xmlDocPtr doc; // djf定义解析文档指针
    xmlNodePtr curNode;//定义节点指针（在各个节点之间移动）
    xmlChar *szKey;//定义临时字符串变量

    char *szDocName;
    szDocName = (char *)rootName;
    doc = xmlReadFile(szDocName,"GB2312",XML_PARSE_RECOVER);
    if (doc == NULL)
    {
        printf("document not parsed successfully");
        return -1;
    }

    //确定文档根元素
    curNode = xmlDocGetRootElement(doc);
    if (curNode == NULL)
    {
        printf("empty document");
        xmlFreeDoc(doc);
        return -1;
    }

    //curNode=curNode->xmlChildrenNode;
    curNode = curNode->children;
    xmlNodePtr propNodePtr = curNode;

    printf("--------------------------------\n");
    while (curNode != NULL) //打印第一层节点
    {
        if ((xmlStrcmp(curNode->name,(xmlChar *)BucketName))==0)
        {
            printf("object in %s:%s\n",BucketName,curNode->name);
            xmlNodePtr obj = curNode->children;
            while (obj!=NULL)//打印第二层节点
            {
                printf("%s\n",obj->name);
                obj=obj->next;
            }
        }
        curNode = curNode->next;
    }
    xmlFreeDoc(doc);

}

//list bucket
int listBucket(char *clientName)
{
    xmlDocPtr doc; // djf定义解析文档指针
    xmlNodePtr curNode;//定义节点指针（在各个节点之间移动）
    xmlChar *szKey;//定义临时字符串变量

    char *szDocName;
    szDocName = (char *)clientName;
    doc = xmlReadFile(szDocName,"GB2312",XML_PARSE_RECOVER);
    if (doc == NULL)
    {
        printf("document not parsed successfully");
        return -1;
    }

    //确定文档根元素
    curNode = xmlDocGetRootElement(doc);
    if (curNode == NULL)
    {
        printf("empty document");
        xmlFreeDoc(doc);
        return -1;
    }

    //curNode=curNode->xmlChildrenNode;
    curNode = curNode->children;
    xmlNodePtr propNodePtr = curNode;

    printf("--------------------------------\n");
    printf("buckets in %s:\n",clientName);
    while (curNode != NULL) //打印第一层节点
    {

        printf("%s\n",curNode->name);
        curNode = curNode->next;
    }
    xmlFreeDoc(doc);
}

int parserXmlFile(char *rootName)
{
    xmlDocPtr doc; // djf定义解析文档指针
    xmlNodePtr curNode;//定义节点指针（在各个节点之间移动）
    xmlChar *szKey;//定义临时字符串变量

    char *szDocName;
    szDocName = (char *)rootName;
    doc = xmlReadFile(szDocName,"GB2312",XML_PARSE_RECOVER);
    if (doc == NULL)
    {
        printf("document not parsed successfully");
        return -1;
    }

    //确定文档根元素
    curNode = xmlDocGetRootElement(doc);
    if (curNode == NULL)
    {
        printf("empty document");
        xmlFreeDoc(doc);
        return -1;
    }

    //curNode=curNode->xmlChildrenNode;
    curNode = curNode->children;
    xmlNodePtr propNodePtr = curNode;

    while (curNode != NULL) //打印第一层节点
    {
        printf("--------------------------------\n");
        printf("bucket:%s\t\n",curNode->name);
        xmlNodePtr obj = curNode->children;
        while (obj!=NULL)//打印第二层节点
        {
            printf("object in bucket %s :\n%s/%s\n",curNode->name,curNode->name,obj->name);
            obj=obj->next;
        }


        curNode = curNode->next;
    }
    xmlFreeDoc(doc);
}

