#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)/*��ʼ��˳���L*/
{
    L->size = 0;/*�����ʼ����Ԫ�ظ���*/
}

int ListLength(SeqList L)/*����˳���L�ĵ�ǰ����Ԫ�ظ���*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*��˳���L��λ��i��0 �� i �� size��ǰ��������Ԫ��ֵx*/
/*����ɹ�����1������ʧ�ܷ���0*/
{
    int j;
    if(L->size >= MaxSize)
    {
        printf("˳��������޷�����! \n");
        return 0;
    }
    else if(i < 0 || i > L->size )
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    {
        //�˶γ�����һ������
        for(j = L->size; j > i; j--) L->list[j] = L->list[j-1];/*Ϊ������׼��*/
        //j+1������size��ʹ�ò������Ϸ������Ը�Ϊj��ͬʱj��Ϊj-1
        L->list[j] = x;/*����*/
        L->size ++;/*Ԫ�ظ�����1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*ɾ��˳���L��λ��i��0 �� i �� size - 1��������Ԫ��ֵ����ŵ�����x��*/
/*ɾ���ɹ�����1��ɾ��ʧ�ܷ���0*/
{
    int j;
    if(L->size <= 0)
    {
        printf("˳����ѿ�������Ԫ�ؿ�ɾ! \n");
        return 0;
    }
    else if(i < 0 || i > L->size-1)
    {
        printf("����i���Ϸ�");
        return 0;
    }
    else
    {
        //�˶γ�����һ������

        *x = L->list[i];/*����ɾ����Ԫ�ص�����x��*/
        for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*����ǰ��*/
        //ʹlist[j-1]==list[j]����ʹ��������ݲ���ʧ
        L->size--;/*����Ԫ�ظ�����1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*ȡ˳���L�е�i������Ԫ�ص�ֵ����x�У��ɹ��򷵻�1��ʧ�ܷ���0*/
{
    if(i < 0 || i > L.size-1)
    {
        printf("����i���Ϸ�! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}
void merge( SeqList *L, SeqList *P)//���ڶ������Ա�ϲ�����һ�����Ա�
{
    int i=-1,j,temp[200],m=0;
     int a=0,b=0;
    do
    {
        i++;
     if(a < L->size&&b < P->size)
      {
        if(L->list[a] > P->list[b])
        {
            temp[i] = P->list[b];
            b++;
            continue;
        }
        else if(L->list[a] < P->list[b])
        {
            temp[i] = L->list[a];
            a++;
            continue;
        }
       else if(L->list[a] == P->list[b])
        {
            temp[i] = L->list[a];
            a++;
            b++;
            continue;
        }
      }
      else if(a==L->size)
      {
          temp[i]= P->list[b];
          b++;
      }
      else if(b==P->size)
      {
          temp[i]= L->list[a];
          a++;
      }

    }while(temp[i]!=0);
   for(j=0;temp[j]!=0;j++)
   {
       L->list[j] = temp[j];
       m++;
   }
   L->size=m;
}
int main(void)
{
    SeqList myList;
    SeqList addList;
    int i, x;
    ListInitiate(&myList);
    ListInitiate(&addList);
    for(i = 0; i < 10; i++)
        ListInsert(&myList, i, i+1);
    for(i = 0; i < 10; i++)
        ListInsert(&addList, i, i+4);

    ListDelete(&myList, 4, &x);
     for(i = 0; i < ListLength(myList); i++)
    {
        ListGet(myList,i,&x); //�˶γ�����һ������
        //��ʧ��ʵ�Σ������βοɵô˴�ΪmyList
        printf(" %d", x);
    }
    printf("\n");
    for(i = 0;i < ListLength(addList);i++)
    {
         ListGet(addList,i,&x);
        printf(" %d", x);
    }
    printf("\n");
   merge(&myList,&addList);
    printf("����Ϊ�ϲ�������Ա�\n");
    for(i=0;i< myList.size-1;i++)    //����ϲ������Ա�
    {
        printf(" %d",myList.list[i]);
    }
    return 0;
}




