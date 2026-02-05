#include "stdio.h"
#include "stdlib.h"

//示例元素类型
typedef int ElementType;
//链式存储的单个节点
struct SNode
{
    //节点上的数据
    ElementType Data;
    //下一个节点
    struct SNode *Next;
};
//链式存储的头节点
struct Head
{
    //下一个（即top）元素
    struct SNode *Next;
    //最多存储数据个数
    int MaxSize;
    //当前元素个数
    int ElementNum;
};
typedef struct Head *Stack;

//生成空栈
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
    Stack s = (Stack)malloc(sizeof(struct Head));
    s->Next = NULL;
    s->MaxSize = MaxSize;
    s->ElementNum = 0;
    return s;
}

int IsFull(Stack S)
{
    return S->ElementNum == S->MaxSize;
}

void Push(Stack S, ElementType item)
{
    if (IsFull(S))
    {
        printf("Stack Full!\n");
    }
    else
    {
        struct SNode *n = (struct SNode *)malloc(sizeof(struct SNode));
        n->Data = item;
        n->Next = NULL;
        struct SNode *t = S->Next;
        S->Next = n;
        n->Next = t;
        S->ElementNum++;
    }
}

int IsEmpty(Stack S)
{
    return S->ElementNum == 0;
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
        ElementType e = S->Next->Data;
        struct SNode *t = S->Next;
        S->Next = S->Next->Next;
        free(t);
        S->ElementNum--;
        return e;
    }
}

//测试
int main()
{
    Stack s = CreateStack(10);
    printf("%d\n", IsFull(s));
    printf("%d\n", IsEmpty(s));

    for (int i = 0; i < 11; i++)
    {
        Push(s, i);
    }
    printf("%d\n", IsFull(s));
    printf("%d\n", IsEmpty(s));

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