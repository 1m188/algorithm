#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//定义数据存储空间的最大空间
#define MAXSIZE 100
//给出一个泛用的数据类型，以int为例
typedef int ElementType;

//线性表的结构体，其中用数组来实现线性存储
struct LNode
{
    //数据存储数组
    ElementType Data[MAXSIZE];
    //最后一个数据的下标索引
    int Last;
};
typedef struct LNode *List;

//初始化一个空线性表L
List MakeEmpty();
//根据位序K，返回相应元素
ElementType FindKth(int K, List L);
//在线性表L中查找X的第一次出现位置
int Find(ElementType X, List L);
//在位序i前插入一个新元素X
void Insert(ElementType X, int i, List L);
//删除指定位序i的元素
void Delete(int i, List L);
//返回线性表L的长度n
int Length(List L);

List MakeEmpty()
{
    List l = (List)malloc(sizeof(struct LNode));
    memset(l->Data, 0, sizeof(ElementType) * MAXSIZE);
    l->Last = -1;
    return l;
}

ElementType FindKth(int K, List L)
{
    if (K < 0 || K > L->Last)
    {
        printf("K Error!\n");
        return -1;
    }
    else
    {
        return L->Data[K];
    }
}

int Find(ElementType X, List L)
{
    for (int i = 0; i <= L->Last; i++)
    {
        if (L->Data[i] == X)
        {
            return i;
        }
    }
    printf("Not Found!\n");
    return -1;
}

void Insert(ElementType X, int i, List L)
{
    if (L->Last == MAXSIZE - 1)
    {
        printf("Full Element!\n");
    }
    else if (i < 0 || i > L->Last + 1)
    {
        printf("i Error!\n");
    }
    else
    {
        for (int j = L->Last + 1; j > i; j--)
        {
            L->Data[j] = L->Data[j - 1];
        }
        L->Data[i] = X;
        L->Last++;
    }
}

void Delete(int i, List L)
{
    if (i < 0 || i > L->Last)
    {
        printf("i Error!\n");
    }
    else
    {
        for (int j = i; j < L->Last; j++)
        {
            L->Data[j] = L->Data[j + 1];
        }
        L->Last--;
    }
}

int Length(List L)
{
    return L->Last + 1;
}

//输出线性表
void Print(List L)
{
    for (int i = 0; i <= L->Last; i++)
    {
        printf("%d ", L->Data[i]);
    }
    printf("\n");
}

//测试
int main()
{
    List l = MakeEmpty();
    Print(l);

    for (int i = 0; i < 10; i++)
    {
        Insert(i, i, l);
    }
    Print(l);
    printf("%d\n", Length(l));

    printf("%d %d\n", FindKth(8, l), FindKth(11, l));

    printf("%d %d\n", Find(90, l), Find(2, l));

    Delete(0, l);
    Print(l);
    Delete(11, l);
    Print(l);

    printf("%d\n", Length(l));

    return 0;
}