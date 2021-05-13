#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Max 100
typedef struct
{
    char data[Max];
    int top;
} Stack;
int getIndex(char theta)   //��ȡtheta����Ӧ������
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

char getPriority(char theta1, char theta2)   //��ȡtheta1��theta2֮������ȼ�
{
    const char priority[][7] =     //���������ȼ���ϵ
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
    Stack *opter;//������
    Stack *opnd;//����
    while(*shizi != '#')
    {
        if(isdight(*shizi))
        {
            Push(&opnd,&shizi);
        }
    }
}
