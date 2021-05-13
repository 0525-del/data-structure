#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Max 100
typedef struct
{
    char data[Max];
    int top;
} Stack;
int getIndex(char theta)   //获取theta所对应的索引
{
    int index = 0;
    switch (theta)
    {
    case '+':
        index = 0;
        break;
    case '-':
        index = 1;
        break;
    case '*':
        index = 2;
        break;
    case '/':
        index = 3;
        break;
    case '(':
        index = 4;
        break;
    case ')':
        index = 5;
        break;
    case '#':
        index = 6;
    default:
        break;
    }
    return index;
}

char getPriority(char theta1, char theta2)   //获取theta1与theta2之间的优先级
{
    const char priority[][7] =     //算符间的优先级关系
    {
        { '>','>','<','<','<','>','>' },
        { '>','>','<','<','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '>','>','>','>','<','>','>' },
        { '<','<','<','<','<','=','0' },
        { '>','>','>','>','0','>','>' },
        { '<','<','<','<','<','0','=' },
    };

    int index1 = getIndex(theta1);
    int index2 = getIndex(theta2);
    return priority[index1][index2];
}
char InitStack(Stack **S)
{
    (*s)=(Stack*)malloc(sizeof(Stack));
    (*S)->top = 0;
}
void Push(Stack *S,*e)
{
    if(S->top ==Max-1)
    {
        return 0;
    }
    else
    {
        S->top ++;
        S->data[S->top] = e;
        return 1;
    }
}
char Pop(Stack *S,*e)
{
    if(S->top == -1)
    {
        return 0;
    }
    else
    {
        e = S->data[S->top];
        S->top--;
        return e;
    }
}
char GetPop(Stack *S,*e)
{

    if(S->top ==-1)
    {
        return 0;
    }
    else
    {
        e = S->data[S->top];
        return e;
    }
}
int Jisuan(char *shizi)
{
    Stack *opter;//操作符
    Stack *opnd;//数据
    while(*shizi != '#')
    {
        if(isdight(*shizi))
        {
            Push(&opnd,&shizi);
        }
    }
}
