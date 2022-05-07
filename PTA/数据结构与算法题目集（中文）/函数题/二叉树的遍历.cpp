// 6-9 二叉树的遍历 （25 分）
// 本题要求给定二叉树的4种遍历。

// 函数接口定义：

// void InorderTraversal( BinTree BT );
// void PreorderTraversal( BinTree BT );
// void PostorderTraversal( BinTree BT );
// void LevelorderTraversal( BinTree BT );
// 其中BinTree结构定义如下：

// typedef struct TNode *Position;
// typedef Position BinTree;
// struct TNode{
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
// };
// 要求4个函数分别按照访问顺序打印出结点的内容，格式为一个空格跟着一个字符。

// 裁判测试程序样例：

// #include <stdio.h>
// #include <stdlib.h>

// typedef char ElementType;
// typedef struct TNode *Position;
// typedef Position BinTree;
// struct TNode{
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
// };

// BinTree CreatBinTree(); /* 实现细节忽略 */
// void InorderTraversal( BinTree BT );
// void PreorderTraversal( BinTree BT );
// void PostorderTraversal( BinTree BT );
// void LevelorderTraversal( BinTree BT );

// int main()
// {
//     BinTree BT = CreatBinTree();
//     printf("Inorder:");    InorderTraversal(BT);    printf("\n");
//     printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
//     printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
//     printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输出样例（对于图中给出的树）：

// Inorder: D B E F A G H C I
// Preorder: A B D F E C G H I
// Postorder: D E F B H G I C A
// Levelorder: A B C D F G I E H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}

void InorderTraversal(BinTree BT)
{
    if (BT)
    {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal(BinTree BT)
{
    if (BT)
    {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal(BinTree BT)
{
    if (BT)
    {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}

void LevelorderTraversal(BinTree BT)
{
    if (BT)
    {
        BinTree q[1000];
        int index = 0, lIndex = 0;
        q[lIndex] = BT;
        while (index <= lIndex)
        {
            BinTree t = q[index];
            printf(" %c", t->Data);
            if (t->Left)
            {
                q[++lIndex] = t->Left;
            }
            if (t->Right)
            {
                q[++lIndex] = t->Right;
            }
            index++;
        }
    }
}