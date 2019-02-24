// 6-1 单链表逆转 （20 分）
// 本题要求实现一个函数，将给定的单链表逆转。

// 函数接口定义：

// List Reverse( List L );
// 其中List结构定义如下：

// typedef struct Node *PtrToNode;
// struct Node {
//     ElementType Data; /* 存储结点数据 */
//     PtrToNode   Next; /* 指向下一个结点的指针 */
// };
// typedef PtrToNode List; /* 定义单链表类型 */
// L是给定单链表，函数Reverse要返回被逆转后的链表。

// 裁判测试程序样例：

// #include <stdio.h>
// #include <stdlib.h>

// typedef int ElementType;
// typedef struct Node *PtrToNode;
// struct Node {
//     ElementType Data;
//     PtrToNode   Next;
// };
// typedef PtrToNode List;

// List Read(); /* 细节在此不表 */
// void Print( List L ); /* 细节在此不表 */

// List Reverse( List L );

// int main()
// {
//     List L1, L2;
//     L1 = Read();
//     L2 = Reverse(L1);
//     Print(L1);
//     Print(L2);
//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// 输入样例：

// 5
// 1 3 4 5 2
// 输出样例：

// 1
// 2 5 4 3 1

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

List Reverse(List L)
{
    if (!L)
    {
        return NULL;
    }
    else
    {
        struct Node *head = L;
        L = L->Next;
        head->Next = NULL;
        while (L)
        {
            List t = L;
            L = L->Next;
            t->Next = head;
            head = t;
        }
        return head;
    }
}