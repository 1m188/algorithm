/*
03-树1 树的同构 （25 分)
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。


图1



图2

现给定两棵树，请你判断它们是否是同构的。
输入格式:

输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:

如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：

8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
输出样例1:

Yes
输入样例2（对应图2）：

8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4
输出样例2:

No
*/

#include "stdio.h"
#include "stdlib.h"

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

//树节点
struct TreeNode
{
    //节点内容
    ElementType Element;
    //左子树
    Tree Left;
    //右子树
    Tree Right;
} T1[MaxTree], T2[MaxTree];

//构建二叉树
Tree BuildTree(struct TreeNode T[])
{
    //根节点索引
    Tree Root = -1;

    int N = 0;
    scanf("%d\n", &N);

    if (N)
    {
        int i = 0;

        //检测根节点
        int *check = (int *)malloc(sizeof(int) * N);
        for (i = 0; i < N; i++)
        {
            check[i] = 0;
        }

        //输入树节点以及左右子树索引
        for (i = 0; i < N; i++)
        {
            char cl = '\0', cr = '\0';
            scanf("%c %c %c\n", &T[i].Element, &cl, &cr);

            //判断左右子树是否存在
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
            {
                T[i].Left = Null;
            }
            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
            {
                T[i].Right = Null;
            }
        }

        //获取根节点
        for (i = 0; i < N; i++)
        {
            if (!check[i])
            {
                Root = i;
                free(check);
                break;
            }
        }
    }

    return Root;
}

//判断两棵二叉树是否同构
int Isomorphic(Tree R1, Tree R2)
{
    //同时为空
    if (R1 == Null && R2 == Null)
        return 1;

    //一空一非空
    if ((R1 == Null && R2 != Null) || (R1 != Null && R2 == Null))
        return 0;

    //两边元素内容不相等
    if (T1[R1].Element != T2[R2].Element)
        return 0;

    //都没有左子树
    if (T1[R1].Left == Null && T2[R2].Left == Null)
        return Isomorphic(T1[R1].Right, T2[R2].Right);

    //不需要交换左右子树
    if (T1[R1].Left != Null && T2[R2].Left != Null && T1[T1[R1].Left].Element == T2[T2[R2].Left].Element)
        return Isomorphic(T1[R1].Left, T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right);
    else
        return Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left);
}

int main()
{
    Tree R1 = -1, R2 = -1;
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if (Isomorphic(R1, R2))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}