// 6-5 链式表操作集 （20 分）
// 本题要求实现链式表的操作集。

// 函数接口定义：

// Position Find( List L, ElementType X );
// List Insert( List L, ElementType X, Position P );
// List Delete( List L, Position P );
// 其中List结构定义如下：

// typedef struct LNode *PtrToLNode;
// struct LNode {
//     ElementType Data;
//     PtrToLNode Next;
// };
// typedef PtrToLNode Position;
// typedef PtrToLNode List;
// 各个操作函数的定义为：

// Position Find( List L, ElementType X )：返回线性表中首次出现X的位置。若找不到则返回ERROR；

// List Insert( List L, ElementType X, Position P )：将X插入在位置P指向的结点之前，返回链表的表头。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR；

// List Delete( List L, Position P )：将位置P的元素删除并返回链表的表头。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR。

// 裁判测试程序样例：

// #include <stdio.h>
// #include <stdlib.h>

// #define ERROR NULL
// typedef int ElementType;
// typedef struct LNode *PtrToLNode;
// struct LNode {
//     ElementType Data;
//     PtrToLNode Next;
// };
// typedef PtrToLNode Position;
// typedef PtrToLNode List;

// Position Find( List L, ElementType X );
// List Insert( List L, ElementType X, Position P );
// List Delete( List L, Position P );

// int main()
// {
//     List L;
//     ElementType X;
//     Position P, tmp;
//     int N;

//     L = NULL;
//     scanf("%d", &N);
//     while ( N-- ) {
//         scanf("%d", &X);
//         L = Insert(L, X, L);
//         if ( L==ERROR ) printf("Wrong Answer\n");
//     }
//     scanf("%d", &N);
//     while ( N-- ) {
//         scanf("%d", &X);
//         P = Find(L, X);
//         if ( P == ERROR )
//             printf("Finding Error: %d is not in.\n", X);
//         else {
//             L = Delete(L, P);
//             printf("%d is found and deleted.\n", X);
//             if ( L==ERROR )
//                 printf("Wrong Answer or Empty List.\n");
//         }
//     }
//     L = Insert(L, X, NULL);
//     if ( L==ERROR ) printf("Wrong Answer\n");
//     else
//         printf("%d is inserted as the last element.\n", X);
//     P = (Position)malloc(sizeof(struct LNode));
//     tmp = Insert(L, X, P);
//     if ( tmp!=ERROR ) printf("Wrong Answer\n");
//     tmp = Delete(L, P);
//     if ( tmp!=ERROR ) printf("Wrong Answer\n");
//     for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
//     return 0;
// }

// /* 你的代码将被嵌在这里 */
// 输入样例：

// 6
// 12 2 4 87 10 2
// 4
// 2 12 87 5
// 输出样例：

// 2 is found and deleted.
// 12 is found and deleted.
// 87 is found and deleted.
// Finding Error: 5 is not in.
// 5 is inserted as the last element.
// Wrong Position for Insertion
// Wrong Position for Deletion
// 10 4 2 5

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR)
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR)
        printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR)
        printf("Wrong Answer\n");
    for (P = L; P; P = P->Next)
        printf("%d ", P->Data);
    return 0;
}

Position Find(List L, ElementType X)
{
    while (L)
    {
        if (L->Data == X)
        {
            return L;
        }
        L = L->Next;
    }
    return ERROR;
}

List Insert(List L, ElementType X, Position P)
{
    if (P == L)
    {
        PtrToLNode head = (PtrToLNode)malloc(sizeof(struct LNode));
        head->Data = X;
        head->Next = L;
        return head;
    }
    else
    {
        List cursor = L;
        while (cursor)
        {
            if (P == cursor->Next)
            {
                PtrToLNode node = (PtrToLNode)malloc(sizeof(struct LNode));
                node->Data = X;
                node->Next = P;
                cursor->Next = node;
                return L;
            }
            cursor = cursor->Next;
        }
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

List Delete(List L, Position P)
{
    if (P)
    {
        if (P == L)
        {
            PtrToLNode head = L->Next;
            free(P);
            return head;
        }
        else
        {
            List cursor = L;
            while (cursor)
            {
                if (P == cursor->Next)
                {
                    PtrToLNode node = P->Next;
                    free(P);
                    cursor->Next = node;
                    return L;
                }
                cursor = cursor->Next;
            }
        }
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}