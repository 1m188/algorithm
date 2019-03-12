#include "stdio.h"
#include "stdlib.h"
#include "memory.h"

//抽象存储的数据类型，以int为例
typedef int ElementType;
//栈结构体
struct SNode
{
    //用以实现顺序存储的数组
    ElementType *Data;
    //栈顶元素下标
    int Top;
    //栈的最多存储元素数目
    int MaxSize;
};
typedef struct SNode *Stack;

//生成空栈，其最大长度为MaxSize
Stack CreateStack(int MaxSize);
//判断栈S是否已经满了
int IsFull(Stack S);
//将元素item压入栈
void Push(Stack S, ElementType item);
//判断栈S是否为空
int IsEmpty(Stack S);
//删除并返回栈顶元素
ElementType Pop(Stack S);

Stack CreateStack(int MaxSize)
{
    Stack s = (Stack)malloc(sizeof(struct SNode));
    s->Data = (ElementType *)malloc(sizeof(ElementType) * MaxSize);
    memset(s->Data, 0, sizeof(ElementType) * MaxSize);
    s->Top = -1;
    s->MaxSize = MaxSize;
    return s;
}

int IsFull(Stack S)
{
    return S->Top == S->MaxSize - 1;
}

void Push(Stack S, ElementType item)
{
    if (IsFull(S))
    {
        printf("Stack Full!\n");
    }
    else
    {
        S->Data[++S->Top] = item;
    }
}

int IsEmpty(Stack S)
{
    return S->Top == -1;
}

ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Stack Empty!\n");
        return -1;
    }
    else
    {
        return S->Data[S->Top--];
    }
}

//测试
int main()
{
    Stack s = CreateStack(10);
    printf("%d\n", IsFull(s));
    printf("%d\n", IsEmpty(s));

    for (int i = 0; i < 10; i++)
    {
        Push(s, i);
    }
    printf("%d\n", IsFull(s));
    printf("%d\n", IsEmpty(s));
    Push(s, 12);

    printf("%d\n", Pop(s));
    printf("%d\n", IsFull(s));
    printf("%d\n", IsEmpty(s));

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", Pop(s));
    }
    printf("%d\n", IsFull(s));
    printf("%d\n", IsEmpty(s));

    return 0;
}