#include "stdio.h"
#include "stdlib.h"

//给出一个泛用的数据类型，以int为例
typedef int ElementType;

typedef struct LNode *List;
//线性表节点结构体
struct LNode
{
    //存储数据
    ElementType Data;
    //指向下一个节点的指针
    List Next;
};

//根据位序K，返回相应元素
List FindKth(int K, List L);
//在线性表L中查找X的第一次出现位置
List Find(ElementType X, List L);
//在位序i前插入一个新元素X
List Insert(ElementType X, int i, List L);
//删除指定位序i的元素
List Delete(int i, List L);
//返回线性表L的长度n
int Length(List L);

List FindKth(int K, List L)
{
    int index = 0;
    while (L && index < K)
    {
        index++;
        L = L->Next;
    }
    return L;
}

List Find(ElementType X, List L)
{
    while (L && L->Data != X)
    {
        L = L->Next;
    }
    return L;
}

List Insert(ElementType X, int i, List L)
{
    int length = Length(L);
    if (i < 0 || i > length)
    {
        printf("index Error!\n");
        return L;
    }
    else
    {
        List n = (List)malloc(sizeof(struct LNode));
        n->Data = X;
        n->Next = NULL;

        if (i == 0)
        {
            n->Next = L;
            return n;
        }
        else if (i == length)
        {
            List c = L;
            while (c->Next)
            {
                c = c->Next;
            }
            c->Next = n;
            return L;
        }
        else
        {
            int index = 0;
            List c = L;
            while (index < i - 1)
            {
                index++;
                c = c->Next;
            }
            List t = c->Next;
            c->Next = n;
            n->Next = t;
            return L;
        }
    }
}

List Delete(int i, List L)
{
    int length = Length(L);
    if (!L)
    {
        printf("List Empty!\n");
        return L;
    }
    else if (i < 0 || i >= length)
    {
        printf("index Error!\n");
        return L;
    }
    else
    {
        if (i == 0)
        {
            List n = L->Next;
            free(L);
            return n;
        }
        else if (i == length - 1)
        {
            List c = L;
            while (c->Next->Next)
            {
                c = c->Next;
            }
            free(c);
            c->Next = NULL;
            return L;
        }
        else
        {
            int index = 0;
            List c = L;
            while (index < i - 1)
            {
                index++;
                c = c->Next;
            }
            List t = c->Next, n = t->Next;
            free(t);
            c->Next = n;
            return L;
        }
    }
}

int Length(List L)
{
    int num = 0;
    while (L)
    {
        num++;
        L = L->Next;
    }
    return num;
}

//输出线性表
void Print(List L)
{
    while (L)
    {
        printf("%d ", L->Data);
        L = L->Next;
    }
    printf("\n");
}

//测试
int main()
{
    List l = NULL;
    Print(l);
    printf("%d\n", Length(l));

    for (int i = 0; i < 12; i++)
    {
        l = Insert(i, i, l);
    }
    Print(l);
    printf("%d\n", Length(l));

    List t = FindKth(9, l);
    if (t)
    {
        printf("%d\n", t->Data);
    }
    else
    {
        printf("Not Found!\n");
    }
    t = FindKth(12, l);
    if (t)
    {
        printf("%d\n", t->Data);
    }
    else
    {
        printf("Not Found!\n");
    }

    t = Find(12, l);
    if (t)
    {
        printf("%d\n", t->Data);
    }
    else
    {
        printf("Not Found!\n");
    }
    t = Find(7, l);
    if (t)
    {
        printf("%d\n", t->Data);
    }
    else
    {
        printf("Not Found!\n");
    }

    l = Insert(12, 8, l);
    Print(l);
    printf("%d\n", Length(l));
    l = Insert(666, 6, l);
    Print(l);
    printf("%d\n", Length(l));

    l = Delete(0, l);
    Print(l);
    printf("%d\n", Length(l));
    l = Delete(15, l);
    Print(l);
    printf("%d\n", Length(l));

    return 0;
}