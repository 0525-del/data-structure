#include <stdio.h>/*该文件包含printf()等函数*/
#include <stdlib.h>/*该文件包含exit()等函数*/
#include <malloc.h>/*该文件包含malloc()等函数*/

typedef int DataType;/*定义DataType为int*/


typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)/*初始化*/
{
    /*如果有内存空间，申请头结点空间并使头指针head指向头结点*/
    if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
    (*head)->next = NULL;/*置链尾标记NULL */
}

int ListLength(SLNode *head)               /* 单链表的长度*/
{
    SLNode *p = head;/*p指向首元结点*/
    int size = 0;/*size初始为0*/

    while(p->next != NULL)/*循环计数*/
    {
        p = p->next;
        size ++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*在带头结点的单链表head的数据元素ai（0 ≤ i ≤ size）结点前*/
/*插入一个存放数据元素x的结点*/
{
    SLNode *p, *q;
    int j;

    p = head; /*p指向首元结点*/
    j = -1;/*j初始为-1*/
    while(p->next != NULL && j < i - 1)
        /*最终让指针p指向数据元素ai-1结点*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("插入位置参数错！");
        return 0;
    }

    /*生成新结点由指针q指示*/
    if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
    q->data = x;

//此段程序有一处错误
    q->next = p->next;/*给指针q->next赋值*/
    //先使q连上p的下一个节点，再连上上一个节点，否则会使插入失败
    p->next = q;/*给指针p->next重新赋值*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*删除带头结点的单链表head的数据元素ai（0 ≤ i ≤ size - 1）结点*/
/*删除结点的数据元素域值由x带回。删除成功时返回1；失败返回0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*p指向首元结点*/
    j = -1;/*j初始为-1*/
    while(p->next != NULL && p->next->next!= NULL && j < i - 1)
        /*最终让指针p指向数据元素ai-1结点*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("删除位置参数错！");
        return 0;
    }

//此段程序有一处错误
//将p改为p->next，使s指向p的下一个节点，因为p指向的是第四个节点，而要删去的是第五个
    s = p->next; /*指针s指向数据元素ai结点*/
    *x = s->data;/*把指针s所指结点的数据元素域值赋予x*/
    p->next = s->next;/*把数据元素ai结点从单链表中删除*/
    free(s);/*释放指针s所指结点的内存空间*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*取数据元素ai和删除函数类同，只是不删除数据元素ai结点*/
{
    SLNode *p;
    int j;

    p = head;
    j = -1;
    while(p->next != NULL && j < i)
    {
        p = p->next;
        j++;
    }

    if(j != i)
    {
        printf("取元素位置参数错！");
        return 0;
    }

//此段程序有一处错误
    *x = p->data;
    //使x的值指向数据域的数而不是next
    return 1;
}

void Destroy(SLNode **head)
{
    SLNode *p, *p1;

    p = *head;
    while(p != NULL)
    {
        p1 = p;
        p = p->next;
        free(p1);
    }
    *head = NULL;
}
void merge(SLNode **Two,SLNode **Three,SLNode **Four)//合并函数，将Two和Three合并到Four单链表；

{
    SLNode *p1,*p2,*p3;
    p1 = (*Two)->next;
    p2 = (*Three)->next;
    p3 = (*Four);
     int i;
     for(i=0;i<100;i++)
    {if( p1!=NULL && p2!=NULL)//前两个单链表都未结束时
    {
        if(p1->data < p2->data)
        {
            p3->next = p1;
            p3 = p3->next;
            p1 = p1->next;
        }
        else if(p1->data > p2->data)
        {
            p3->next = p2;
            p3 = p3->next;
            p2 = p2->next;
        }
        else if(p1->data == p2->data)
        {
            p3->next = p2;
            p3 = p3->next;
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    else if(p1==NULL )//第一个单链表结束
    {
        while(p2 != NULL)
        {
            p3->next = p2;
            p3 = p3->next;
            p2 = p2->next;
        }

    }
    else if(p2==NULL)//第二个单链表结束
    {
        while(p1 !=NULL)
        {
            p3->next = p1;
            p3 = p3->next;
            p1 = p1->next;
        }
    }
    else
    {
        exit(0);
    }
    }
}

int main(void)
{
    SLNode *head;
    int i, x;
    ListInitiate(&head);/*初始化*/
    for(i = 0; i < 10; i++)
    {
        if(ListInsert(head, i, i+1) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return 0;
        }
    }
    if(ListDelete(head, 4, &x) == 0) /*删除数据元素5*/
    {
        printf("错误! \n");
        return 0;
    }
    printf("输出第一个单链表\n");
    for(i = 0; i < ListLength(head); i++)
    {
        if(ListGet(head, i, &x) == 0) /*取元素*/
        {
            printf("错误! \n");
            return 0;
        }
        else printf(" %d    ", x);/*显示数据元素*/
    }
    printf("\n");
    Destroy(&head);
    SLNode *Two,*Three,*Four;
    ListInitiate(&Two);/*初始化*/
    ListInitiate(&Three);/*初始化*/
    ListInitiate(&Four);/*初始化*/
    int n;
    int m;
    printf("输入有序的第二个单链表的长度 ");
    scanf(" %d",&n);
    for(i=0; i<n; i++)
    {
        printf("输入有序的第二个表的第%d个数据  ",i+1);
        scanf(" %d",&m);
        if(ListInsert(Two, i, m) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return 0;
        }
    }
    printf("输出有序的第二个单链表\n");
    for(i = 0; i < ListLength(Two); i++)
    {
        if(ListGet(Two, i, &x) == 0) /*取元素*/
        {
            printf("错误! \n");
            return 0;
        }
        else printf(" %d    ", x);/*显示数据元素*/
    }
    printf("\n");
    getchar();
    printf("输入有序的第三个单链表的长度  ");
    scanf(" %d",&n);
    for(i=0; i<n; i++)
    {
        printf("输入有序的第三个表的第%d个数据 ",i+1);
        scanf(" %d",&m);
        if(ListInsert(Three, i, m) == 0) /*插入10个数据元素*/
        {
            printf("错误! \n");
            return 0;
        }
    }
    printf("输出有序的第三个单链表\n");
    for(i = 0; i < ListLength(Three); i++)//输出第三个单链表
    {
        if(ListGet(Three, i, &x) == 0) /*取元素*/
        {
            printf("错误! \n");
            return 0;
        }
        else printf(" %d    ", x);/*显示数据元素*/
    }
    printf("\n");
    merge(&Two,&Three,&Four);//运行合并函数
    printf("输出合并的单链表\n");
    for(i = 0; i < ListLength(Four); i++)//输出合并单链表
    {
        if(ListGet(Four, i, &x) == 0) /*取元素*/
        {
            printf("错误! \n");
            return 0;
        }
        else printf(" %d   ", x);/*显示数据元素*/
    }
    return 0;
}

