#include <stdio.h>
#define MaxSize  100
typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)/*初始化顺序表L*/
{
    L->size = 0;/*定义初始数据元素个数*/
}

int ListLength(SeqList L)/*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(SeqList *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if(L->size >= MaxSize)
    {
        printf("顺序表已满无法插入! \n");
        return 0;
    }
    else if(i < 0 || i > L->size )
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        //此段程序有一处错误
        for(j = L->size; j > i; j--) L->list[j] = L->list[j-1];/*为插入做准备*/
        //j+1大于了size，使得参数不合法，所以改为j，同时j改为j-1
        L->list[j] = x;/*插入*/
        L->size ++;/*元素个数加1*/
        return 1;
    }
}

int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置i（0 ≤ i ≤ size - 1）的数据元素值并存放到参数x中*/
/*删除成功返回1，删除失败返回0*/
{
    int j;
    if(L->size <= 0)
    {
        printf("顺序表已空无数据元素可删! \n");
        return 0;
    }
    else if(i < 0 || i > L->size-1)
    {
        printf("参数i不合法");
        return 0;
    }
    else
    {
        //此段程序有一处错误

        *x = L->list[i];/*保存删除的元素到参数x中*/
        for(j = i +1; j <= L->size-1; j++) L->list[j-1] = L->list[j];/*依次前移*/
        //使list[j-1]==list[j]才能使后面的数据不丢失
        L->size--;/*数据元素个数减1*/
        return 1;
    }
}

int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if(i < 0 || i > L.size-1)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}
void merge( SeqList *L, SeqList *P)//将第二个线性表合并到第一个线性表
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
        ListGet(myList,i,&x); //此段程序有一处错误
        //丢失了实参，根据形参可得此处为myList
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
    printf("下面为合并后的线性表\n");
    for(i=0;i< myList.size-1;i++)    //输出合并的线性表
    {
        printf(" %d",myList.list[i]);
    }
    return 0;
}




