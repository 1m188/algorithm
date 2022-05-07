// 6-11 先序输出叶结点 （15 分）
// 本题要求按照先序遍历的顺序输出给定二叉树的叶结点。

// 函数接口定义：

// void PreorderPrintLeaves( BinTree BT );
// 其中BinTree结构定义如下：

// typedef struct TNode *Position;
// typedef Position BinTree;
// struct TNode{
//     ElementType Data;
//     BinTree Left;
//     BinTree Right;
// };
// 函数PreorderPrintLeaves应按照先序遍历的顺序输出给定二叉树BT的叶结点，格式为一个空格跟着一个字符。

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
// void PreorderPrintLeaves( BinTree BT );

// int main()
// {
//     BinTree BT = CreatBinTree();
//     printf("Leaf nodes are:");
//     PreorderPrintLeaves(BT);
//     printf("\n");

//     return 0;
// }
// /* 你的代码将被嵌在这里 */
// 输出样例（对于图中给出的树）：

// Leaf nodes are: D E H I

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
void PreorderPrintLeaves(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("Leaf nodes are:");
    PreorderPrintLeaves(BT);
    printf("\n");

    return 0;
}

void PreorderPrintLeaves(BinTree BT)
{
    if (BT)
    {
        PreorderPrintLeaves(BT->Left);
        if (!BT->Left && !BT->Right)
        {
            printf(" %c", BT->Data);
        }
        PreorderPrintLeaves(BT->Right);
    }
}