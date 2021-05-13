#include <stdio.h>/*���ļ�����printf()�Ⱥ���*/
#include <stdlib.h>/*���ļ�����exit()�Ⱥ���*/
#include <malloc.h>/*���ļ�����malloc()�Ⱥ���*/

typedef int DataType;/*����DataTypeΪint*/


typedef struct Node
{
    DataType data;
    struct Node *next;
} SLNode;

void ListInitiate(SLNode **head)/*��ʼ��*/
{
    /*������ڴ�ռ䣬����ͷ���ռ䲢ʹͷָ��headָ��ͷ���*/
    if((*head = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
    (*head)->next = NULL;/*����β���NULL */
}

int ListLength(SLNode *head)               /* ������ĳ���*/
{
    SLNode *p = head;/*pָ����Ԫ���*/
    int size = 0;/*size��ʼΪ0*/

    while(p->next != NULL)/*ѭ������*/
    {
        p = p->next;
        size ++;
    }
    return size;
}

int ListInsert(SLNode *head, int i, DataType x)
/*�ڴ�ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size�����ǰ*/
/*����һ���������Ԫ��x�Ľ��*/
{
    SLNode *p, *q;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;/*j��ʼΪ-1*/
    while(p->next != NULL && j < i - 1)
        /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("����λ�ò�����");
        return 0;
    }

    /*�����½����ָ��qָʾ*/
    if((q = (SLNode *)malloc(sizeof(SLNode))) == NULL) exit(1);
    q->data = x;

//�˶γ�����һ������
    q->next = p->next;/*��ָ��q->next��ֵ*/
    //��ʹq����p����һ���ڵ㣬��������һ���ڵ㣬�����ʹ����ʧ��
    p->next = q;/*��ָ��p->next���¸�ֵ*/
    return 1;
}

int ListDelete(SLNode *head, int i, DataType *x)
/*ɾ����ͷ���ĵ�����head������Ԫ��ai��0 �� i �� size - 1�����*/
/*ɾ����������Ԫ����ֵ��x���ء�ɾ���ɹ�ʱ����1��ʧ�ܷ���0*/
{
    SLNode *p, *s;
    int j;

    p = head; /*pָ����Ԫ���*/
    j = -1;/*j��ʼΪ-1*/
    while(p->next != NULL && p->next->next!= NULL && j < i - 1)
        /*������ָ��pָ������Ԫ��ai-1���*/
    {
        p = p->next;
        j++;
    }

    if(j != i - 1)
    {
        printf("ɾ��λ�ò�����");
        return 0;
    }

//�˶γ�����һ������
//��p��Ϊp->next��ʹsָ��p����һ���ڵ㣬��Ϊpָ����ǵ��ĸ��ڵ㣬��Ҫɾȥ���ǵ����
    s = p->next; /*ָ��sָ������Ԫ��ai���*/
    *x = s->data;/*��ָ��s��ָ��������Ԫ����ֵ����x*/
    p->next = s->next;/*������Ԫ��ai���ӵ�������ɾ��*/
    free(s);/*�ͷ�ָ��s��ָ�����ڴ�ռ�*/
    return 1;
}

int ListGet(SLNode *head, int i, DataType *x)
/*ȡ����Ԫ��ai��ɾ��������ͬ��ֻ�ǲ�ɾ������Ԫ��ai���*/
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
        printf("ȡԪ��λ�ò�����");
        return 0;
    }

//�˶γ�����һ������
    *x = p->data;
    //ʹx��ֵָ�����������������next
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
void merge(SLNode **Two,SLNode **Three,SLNode **Four)//�ϲ���������Two��Three�ϲ���Four������

{
    SLNode *p1,*p2,*p3;
    p1 = (*Two)->next;
    p2 = (*Three)->next;
    p3 = (*Four);
     int i;
     for(i=0;i<100;i++)
    {if( p1!=NULL && p2!=NULL)//ǰ����������δ����ʱ
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
    else if(p1==NULL )//��һ�����������
    {
        while(p2 != NULL)
        {
            p3->next = p2;
            p3 = p3->next;
            p2 = p2->next;
        }

    }
    else if(p2==NULL)//�ڶ������������
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
    ListInitiate(&head);/*��ʼ��*/
    for(i = 0; i < 10; i++)
    {
        if(ListInsert(head, i, i+1) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return 0;
        }
    }
    if(ListDelete(head, 4, &x) == 0) /*ɾ������Ԫ��5*/
    {
        printf("����! \n");
        return 0;
    }
    printf("�����һ��������\n");
    for(i = 0; i < ListLength(head); i++)
    {
        if(ListGet(head, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return 0;
        }
        else printf(" %d    ", x);/*��ʾ����Ԫ��*/
    }
    printf("\n");
    Destroy(&head);
    SLNode *Two,*Three,*Four;
    ListInitiate(&Two);/*��ʼ��*/
    ListInitiate(&Three);/*��ʼ��*/
    ListInitiate(&Four);/*��ʼ��*/
    int n;
    int m;
    printf("��������ĵڶ���������ĳ��� ");
    scanf(" %d",&n);
    for(i=0; i<n; i++)
    {
        printf("��������ĵڶ�����ĵ�%d������  ",i+1);
        scanf(" %d",&m);
        if(ListInsert(Two, i, m) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return 0;
        }
    }
    printf("�������ĵڶ���������\n");
    for(i = 0; i < ListLength(Two); i++)
    {
        if(ListGet(Two, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return 0;
        }
        else printf(" %d    ", x);/*��ʾ����Ԫ��*/
    }
    printf("\n");
    getchar();
    printf("��������ĵ�����������ĳ���  ");
    scanf(" %d",&n);
    for(i=0; i<n; i++)
    {
        printf("��������ĵ�������ĵ�%d������ ",i+1);
        scanf(" %d",&m);
        if(ListInsert(Three, i, m) == 0) /*����10������Ԫ��*/
        {
            printf("����! \n");
            return 0;
        }
    }
    printf("�������ĵ�����������\n");
    for(i = 0; i < ListLength(Three); i++)//���������������
    {
        if(ListGet(Three, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return 0;
        }
        else printf(" %d    ", x);/*��ʾ����Ԫ��*/
    }
    printf("\n");
    merge(&Two,&Three,&Four);//���кϲ�����
    printf("����ϲ��ĵ�����\n");
    for(i = 0; i < ListLength(Four); i++)//����ϲ�������
    {
        if(ListGet(Four, i, &x) == 0) /*ȡԪ��*/
        {
            printf("����! \n");
            return 0;
        }
        else printf(" %d   ", x);/*��ʾ����Ԫ��*/
    }
    return 0;
}

