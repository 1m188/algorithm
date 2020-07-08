/*

线性表——天勤2021数据结构

*/

#include "stdio.h"
#include "memory.h"
#include "stdbool.h"
#include "malloc.h"

#define MAX_SIZE 100
typedef int ElementType;

// 顺序表结构体
typedef struct
{
    ElementType data[MAX_SIZE];
    int length;
} Sqlist;

// 打印顺序表
void printOrderList(Sqlist *sqlist, const char *prefix)
{
    printf("%s", prefix);
    for (int i = 0; i < sqlist->length; i++)
        printf(" %d", sqlist->data[i]);
    printf("\n");
}

// 初始化顺序表
void initList(Sqlist *l)
{
    memset(l->data, (ElementType)0, sizeof(ElementType) * MAX_SIZE);
    l->length = 0;
}

// 在顺序表（有序递增）中找到第一个比x大的元素的位置并返回
int findElem(Sqlist *l, ElementType x)
{
    for (int i = 0; i < l->length; i++)
        if (l->data[i] > x)
            return i;
    return l->length; // 如果没有则返回最后一个元素之后的索引，即数组长度，插入在最后一个部分的下标也没错
}

// 在有序递增的顺序表中插入一个元素
void insertElem(Sqlist *l, ElementType x)
{
    int p = findElem(l, x);
    for (int i = l->length - 1; i >= p; i--)
        l->data[i + 1] = l->data[i]; // 从右往左，逐个移动元素，腾出地方
    l->data[p] = x;
    l->length++; // 注意表长自增1
}

// 找到顺序表中第一个值与e相等的元素并返回索引
int findElemEqu(Sqlist *l, ElementType e)
{
    for (int i = 0; i < l->length; i++)
        if (e == l->data[i])
            return i; // 找到返回下标
    return -1;        // 没找到返回-1
}

// 在顺序表上索引p位置插入新的值e，并返回是否成功
bool insertElemAt(Sqlist *l, int p, ElementType e)
{
    if (p < 0 || p >= l->length || l->length == MAX_SIZE) // 位置超出范围或者数组已满
        return false;

    for (int i = l->length - 1; i >= p; i--)
        l->data[i + 1] = l->data[i];
    l->data[p] = e;
    l->length++;
    return true;
}

// 从顺序表中删除下标为p的元素，返回是否成功，并将被删除元素赋值给e
bool deleteElem(Sqlist *l, int p, ElementType *e)
{
    if (p < 0 || p >= l->length)
        return false;

    *e = l->data[p];
    for (int i = p; i < l->length; i++)
        l->data[i] = l->data[i + 1];
    l->length--;
    return true;
}

// 通过e返回顺序表中p索引位置的元素
bool getElem(Sqlist *l, int p, ElementType *e)
{
    if (p < 0 || p >= l->length)
        return false;

    *e = l->data[p];
    return true;
}

// 单链表节点定义
typedef struct LNode
{
    ElementType data;
    struct LNode *next;
} LNode;

// 打印单链表（带头节点）
void printSingleList(LNode *c, const char *prefix)
{
    printf("%s", prefix);
    c = c->next;
    while (c)
    {
        printf(" %d", c->data);
        c = c->next;
    }
    printf("\n");
}

// 释放单链表空间（带头结点）
void freeSingleList(LNode *c)
{
    if (c->next)
    {
        freeSingleList(c->next);
        free(c);
    }
}

// a和b是两个单链表（带头节点），其中元素递增有序，将ab归并成一个按元素值非递减有序的链表c，c由a和b中的节点构成
void merge(LNode *a, LNode *b, LNode **c)
{
    // p，q用来追踪a和b的最小值节点
    LNode *p = a->next;
    LNode *q = b->next;
    LNode *r = NULL; // r用来追踪c末端节点
    // a的头用作新表c的头，把b的头删掉，后面用不上
    *c = a;
    (*c)->next = NULL;
    free(b);
    r = *c;

    // 尾插法建立新表
    // 当两个链表都还有值的时候，从中选最小的加入到新表后面
    while (p && q)
    {
        if (p->data < q->data)
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }

    // 结束之后，将多余的表的内容直接插入，此时多余内容均大于已经插入新表的内容
    if (p)
        r->next = p;
    else
        r->next = q;
}

// 有n个元素存储在a数组中，用尾插法建立链表
void createlistR(LNode **c, ElementType a[], int n)
{
    LNode *s = NULL, *r = NULL;          // r用来指向新申请的列表节点，r指向c链表的末端
    *c = (LNode *)malloc(sizeof(LNode)); // 申请c表的头节点空间
    (*c)->data = 0;
    (*c)->next = NULL;
    r = *c;

    // 循环申请节点来装入链表
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = NULL;
        r->next = s;
        r = r->next;
    }
}

// 用头插法建立链表
void createlistF(LNode **c, ElementType a[], int n)
{
    LNode *s = NULL;
    *c = (LNode *)malloc(sizeof(LNode));
    (*c)->data = 0;
    (*c)->next = NULL;

    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = NULL;

        // 头插法每次申请了新的节点后，使新节点指向头节点的下一个节点，即链表开头，然后使表头节点指向新的链表开始元素，即刚刚申请的节点
        // 此处顺序不可以反过来，反过来后首先让头节点指向新申请的节点便丢失了之前的链表元素的地址
        s->next = (*c)->next;
        (*c)->next = s;
    }
}

// 将两个递增单链表归并成一个递减的单链表
void mergeDecline(LNode *a, LNode *b, LNode **c)
{
    LNode *p = a->next;
    LNode *q = b->next;
    LNode *s = NULL;
    (*c) = a;
    (*c)->next = NULL;
    free(b);

    while (p && q)
    {
        if (p->data <= q->data)
        {
            s = p;
            p = p->next;
            s->next = (*c)->next;
            (*c)->next = s;
        }
        else
        {
            s = q;
            q = q->next;
            s->next = (*c)->next;
            (*c)->next = s;
        }
    }

    LNode *x = p ? p : q;
    while (x)
    {
        s = x;
        x = x->next;
        s->next = (*c)->next;
        (*c)->next = s;
    }
}

// 查找单链表c（带头结点）中是否存在一个值为x的节点，若存在，删除并返回成功，否则返回失败
bool findAndDelete(LNode *c, ElementType x)
{
    LNode *p = NULL, *q = NULL;
    p = c;

    // 这里要拿p的后继，因为最后删除的时候需要将被删除节点的前驱和其后继连接起来
    while (p->next)
    {
        if (p->next->data == x)
            break;
        p = p->next;
    }

    if (!p->next)
        return false;
    else
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
        return true;
    }
}

// 双链表节点定义
typedef struct DLNode
{
    ElementType data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;

int main(int argc, char *argv[])
{
    Sqlist sqlist;
    initList(&sqlist);

    sqlist.length = 10;
    for (int i = 0; i < 10; i++)
        sqlist.data[i] = i + 1;
    printOrderList(&sqlist, "order list order:");

    insertElem(&sqlist, 12);
    printOrderList(&sqlist, "after insert order:");

    int index = findElemEqu(&sqlist, 8);
    printf("The %d index is: %d\n", 8, index);

    bool isSucc = insertElemAt(&sqlist, 8, 150);
    printf("The insertAt result is: %d\n", isSucc);
    printOrderList(&sqlist, "after insertAt order:");

    ElementType e = 0;
    isSucc = deleteElem(&sqlist, 2, &e);
    printf("The delete result is: %d\n", isSucc);
    printOrderList(&sqlist, "after delete order:");
    printf("The deleted element: %d\n", e);

    isSucc = getElem(&sqlist, 5, &e);
    printf("The get result is: %d\n", isSucc);
    printf("The get element is: %d\n", e);

    printf("\n");

    LNode *a = NULL, *b = NULL;
    ElementType aa[] = {1, 3, 5, 7, 9};
    ElementType bb[] = {10, 8, 6, 4, 2};
    createlistR(&a, aa, 5);
    createlistF(&b, bb, 5);
    printSingleList(a, "Tail-inserting single list:");
    printSingleList(b, "Head-inserting single list:");
    // a!=NULL,b!=NULL

    LNode *c = NULL;
    merge(a, b, &c);
    printSingleList(c, "merge single list:");
    // a=NULL,b=NULL
    // c!=NULL

    createlistR(&a, aa, 5);
    createlistF(&b, bb, 5);
    // a!=NULL,b!=NULL
    freeSingleList(c);
    // c=NULL
    mergeDecline(a, b, &c);
    // a=NULL,b=NULL
    // c!=NULL
    printSingleList(c, "merge decline single list:");

    isSucc = findAndDelete(c, 8);
    printf("The find and delete 8 result in single list is: %d\n", isSucc);
    printSingleList(c, "single list after find and delete:");

    isSucc = findAndDelete(c, 100);
    printf("The find and delete 100 result in single list is: %d\n", isSucc);

    freeSingleList(c);
    // c=NULL

    return 0;
}

// 逆置问题

// 将一长度为n的数组的前端k（k<n）个元素逆序后移动到数组后端，要求原数组中数据不丢失，其他位置的元素无关紧要
// 在整个数组中前后逆序交换前k个元素即可
void reverse(int a[], int left, int right, int k)
{
    int tmp = 0;
    for (int i = left, j = right; i < j && i < left + k; i++, j--)
    {
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
}

// 将一长度为n的数组的前端k（k<n）个元素保持原序移动到数组后端，要求原数组中数据不丢失，其余元素的位置无关紧要
// 将数组前k个元素原地逆序，之后整个数组前后交换k个元素即可
void moveToEnd(int a[], int n, int k)
{
    reverse(a, 0, k - 1, k);
    reverse(a, 0, n - 1, k);
}

// 将数组中的元素（X0,X1,X2,...,Xn-1），经过移动后变为（Xp,Xp+1,Xp+2,...,Xn-1,X0,X1,...,Xp-1），即循环左移p个位置
// 将数组前p个元素逆置，数组后的元素逆置，之后数组整体逆置即可
void moveP(int a[], int n, int p)
{
    reverse(a, 0, p - 1, p);
    reverse(a, p, n - 1, n - p);
    reverse(a, 0, n - 1, n);
}