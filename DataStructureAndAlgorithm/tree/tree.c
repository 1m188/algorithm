/*

树与二叉树——天勤2021数据结构

*/

#include "stdio.h"
#include "malloc.h"
#include "memory.h"
#include "stdbool.h"

#define MAX_SIZE 100

int imax(int a, int b)
{
    return a > b ? a : b;
}

/***********************************************  二叉树  ********************************************************/

// 二叉树链式存储结构
typedef struct BTNode
{
    char data;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

// 对树中某节点进行的访问操作
void Visit(BTNode *p)
{
    printf("%c", p->data);
}

// 先序遍历
void preorder(BTNode *p)
{
    if (p)
    {
        Visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

// 中序遍历
void inorder(BTNode *p)
{
    if (p)
    {
        inorder(p->lchild);
        Visit(p);
        inorder(p->rchild);
    }
}

// 后序遍历
void postorder(BTNode *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        Visit(p);
    }
}

// 表达式(a-(b+c))*(d/e)存储在如图（没有图...其实是一个中缀表达式树里面）所示的一颗以二叉链表为存储结构的二叉树中（二叉树节点的
// data域为char字符型），编写程序求出该表达式的值（表达式中的操作数都是一位的整数）。

// 两个一位整数所进行的简单运算操作
int op(int a, char c, int b)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (b == 0)
        {
            printf("ERROR\n");
            return 0;
        }
        else
            return a / b;
    default:
        printf("Nonsence op!\n");
        return 0;
    }
}

// 后序遍历树，获取两个操作数并计算
int comp(BTNode *p)
{
    // 如果p节点左右节点都有，则必定为操作符节点
    // 有一个节点没有则必为操作数节点
    // 注意字符转数字
    return p ? ((p->lchild && p->rchild) ? op(comp(p->lchild), p->data, comp(p->rchild)) : p->data - '0') : 0;
}

// 写一个算法求一颗二叉树的深度，二叉树以二叉链表为存储方式
int getDepth(BTNode *p)
{
    // 二叉树的深度为其根节点的深度，而根节点的深度又为两个子节点的深度中的大值+1，因此递归求取
    // 定义空节点深度为0，根节点深度为1
    return p ? imax(getDepth(p->lchild), getDepth(p->rchild)) + 1 : 0;
}

// 在一棵以二叉链表为存储结构的二叉树中，查找data域等于key的节点是否存在（找到任何一个满足要求的即可），如果存在，让q指针
// 指向该节点，否则q保持为NULL，假设data为char型

// 选择先序遍历来遍历整个树，对每个节点进行判断
// q初始传进来的时候为NULL
// 唯一的缺点是q其实是指向最后一个找到的key节点，而前面所有的找到的key节点最后都被替换
// 改进的方法是进行剪枝
void search(BTNode *p, BTNode **q, char key)
{
    if (p)
    {
        if (p->data == key) // 找到节点则不继续递归
            *q = p;
        else // 否则到左右子树中查找
        {
            search(p->lchild, q, key);
            search(p->rchild, q, key);
        }
    }
}

// 改进过后的剪枝版本
// 如果找到了key，则不再进行递归查找
void search_cut(BTNode *p, BTNode **q, char key)
{
    if (p)
    {
        if (p->data == key) // 如果本节点找到了就算了
            *q = p;
        else
        {
            search_cut(p->lchild, q, key); // 否则到左子树查找
            if (!*q)                       // 除非左子树也没找到才去右子树找
                search_cut(p->rchild, q, key);
        }
    }
}

// 假设二叉树采用采用二叉链表存储结构存储，编写一个程序，输出先序遍历序列中第k个节点的值，假设k不大于总的节点数（节点data域
// 类型为char型）

// 添加一全局计数器，先序遍历到第k个值的时候输出
int n_trave = 0;
void trave(BTNode *p, int k)
{
    if (p)
    {
        // 第一次来到节点时计数
        if (++n_trave == k) // 如果本节点满足第k个节点直接输出并且返回
            printf("%c", p->data);
        else
        {
            trave(p->lchild, k); // 否则到左子树去试探能否遍历到第k个
            if (n_trave < k)     // 剪枝优化，如果左子树还没有到第k个，去右子树，否则不去
                trave(p->rchild, k);
        }
    }
}

// 将题目中的先序遍历改为中序遍历
void trave_in(BTNode *p, int k)
{
    if (p)
    {
        trave_in(p->lchild, k); // n必然小于k
        if (++n_trave == k)
            printf("%c", p->data);
        if (n_trave < k)
            trave_in(p->rchild, k);
    }
}

// 将题目中的先序遍历改为后序遍历
void trave_post(BTNode *p, int k)
{
    if (p)
    {
        trave_post(p->lchild, k);
        if (n_trave < k)
            trave_post(p->rchild, k);
        if (++n_trave == k)
            printf("%c", p->data);
    }
}

// 层次遍历
void level(BTNode *p)
{
    if (p)
    {
        int front = 0, rear = 0;
        BTNode *que[MAX_SIZE]; // 定义一个循环队列，用来存储树节点指针

        rear = (rear + 1) % MAX_SIZE;
        que[rear] = p;        // 压入根节点
        while (front != rear) // 当队列非空
        {
            front = (front + 1) % MAX_SIZE; // 取出当前节点进行操作
            BTNode *q = que[front];
            Visit(q);

            // 压入左子树
            if (q->lchild)
            {
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = q->lchild;
            }

            // 压入右子树
            if (q->rchild)
            {
                rear = (rear + 1) % MAX_SIZE;
                que[rear] = q->rchild;
            }
        }
    }
}

// 假设二叉树采用二叉链表存储结构存储，设计一个算法，求出该二叉树的宽度（具有节点数最多的那一层上的节点个数）

// 首先用层次遍历逐层遍历整个树，为树中所有节点标记层次（节点层次为其上一层层号+1，第一层为1），并将所有节点按层储存在队列（数组）里
// 遍历队列，找到最多节点个数那一层的节点个数
// 其中值得注意的是，用作队列的数组足够长，可以容纳所有节点，因此不需要做循环队列的操作，直接按照普通的队列操作即可

// 顺序非循环队列的队列元素
typedef struct
{
    BTNode *p; // 当前节点指针
    int lno;   // 层号
} St;

// 求二叉树宽度
int maxNode(BTNode *b)
{
    if (b)
    {
        St que[MAX_SIZE];
        int front = 0, rear = 0; // 定义顺序非循环队列
        int Lno = 0;             // 层号

        // 用来存储每层的节点数，下标索引为层数
        int *lnonum = (int *)malloc(sizeof(int) * MAX_SIZE);
        memset(lnonum, 0, sizeof(int) * MAX_SIZE);

        rear++;
        que[rear].p = b;
        que[rear].lno = 1;
        while (front != rear)
        {
            front++;
            BTNode *q = que[front].p;
            Lno = que[front].lno; // Lno用来存取当前节点的层次号
            lnonum[Lno]++;        // 使当前层节点数+1

            if (q->lchild) // 压入左子节点
            {
                rear++;
                que[rear].p = q->lchild;
                que[rear].lno = Lno + 1; // 根据当前层次号推导其子节点的层号
            }

            if (q->rchild) // 压入右子节点
            {
                rear++;
                que[rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
        } // 循环结束的时候，Lno保存的是这个二叉树的最大层号

        // 接下来找出含有最多节点的层的节点数

        int max = 1;
        for (int i = 2; i <= Lno; i++)
            if (lnonum[i] > lnonum[max])
                max = i;
        max = lnonum[max];
        free(lnonum);
        return max;
    }
    else // 空树返回0宽度
        return 0;
}

// 非递归先序遍历
void preorderNonrecursion(BTNode *bt)
{
    if (bt)
    {
        BTNode *stack[MAX_SIZE]; // 定义非递归所使用的栈
        memset(stack, NULL, sizeof(BTNode *) * MAX_SIZE);
        int top = -1;

        stack[++top] = bt; // 根节点入栈

        while (top != -1) // 栈非空时进行循环
        {
            BTNode *p = stack[top--]; // 出栈并对头节点进行访问操作
            Visit(p);

            // 后续子节点入栈，注意先右后左
            if (p->rchild)
                stack[++top] = p->rchild;
            if (p->lchild)
                stack[++top] = p->lchild;
        }
    }
}

// 非递归中序遍历
void inorderNonrecursion(BTNode *bt)
{
    if (bt)
    {
        BTNode *stack[MAX_SIZE];
        memset(stack, NULL, sizeof(BTNode *) * MAX_SIZE);
        int top = -1;

        // 在弹栈的过程中有可能会使栈空而此时并没有遍历完整个树，使用p指针来辅助判定
        BTNode *p = bt;

        while (top != -1 || p)
        {
            // 中序遍历，先从左子节点开始，从左边一撸到底，直到末端
            while (p)
            {
                stack[++top] = p;
                p = p->lchild;
            }

            // 此时末端子节点没有左子节点，此时访问栈顶节点为中间节点
            // 然后进入右子节点重复操作
            if (top != -1)
            {
                p = stack[top--];
                Visit(p);
                p = p->rchild;
            }

            // 右子节点也遍历完了之后，栈顶为上一层的左子节点，然后重复循环
        }
    }
}

// 非递归后序遍历
void postorderNonrecursion(BTNode *bt)
{
    // 此处定义两个栈，首先使用相反的左右节点访问顺序进行先序遍历，所有出栈的节点都放到第二个栈中
    // 然后对第二个栈再做出栈操作，即为后序遍历

    if (bt)
    {
        BTNode *stack1[MAX_SIZE];
        int top1 = -1;
        memset(stack1, NULL, sizeof(BTNode *) * MAX_SIZE);

        BTNode *stack2[MAX_SIZE];
        int top2 = -1;
        memset(stack2, NULL, sizeof(BTNode *) * MAX_SIZE);

        // 根节点入栈，开始做左右相反的先序遍历
        stack1[++top1] = bt;
        while (top1 != -1)
        {
            BTNode *p = stack1[top1--];
            stack2[++top2] = p; // 在先序遍历中输出的节点要加到第二个栈中

            if (p->lchild)
                stack1[++top1] = p->lchild;
            if (p->rchild)
                stack1[++top1] = p->rchild;
        }

        // 第二个栈逐次弹出，出栈序列即为后序遍历
        while (top2 != -1)
        {
            BTNode *p = stack2[top2--];
            Visit(p);
        }
    }
}

/* 二叉树线索化

将空节点指针利用起来按照某种遍历顺序指向其前驱或者后继节点，如果ltag==false，则其lchild指向左子节点，否则为线索指向直接前驱，rtag同上，
右子节点和直接后继

在建立线索二叉树的过程中，需要有两个指针，一个指向当前处理节点，另一个指向当前节点在某种遍历顺序下的直接前驱，通过递归遍历进行二叉树的线索化，
最后pre=p，当p指向p的后继的时候，pre即为p的前驱 */

// 线索二叉树节点定义
typedef struct TBTNode
{
    char data;
    bool ltag, rtag; // 线索标记
    struct TBTNode *lchild;
    struct TBTNode *rchild;
} TBTNode;

// 通过递归中序遍历对二叉树线索化的算法
void InThread(TBTNode *p, TBTNode **pre)
{
    if (p)
    {
        InThread(p->lchild, pre); // 递归，左子树线索化

        if (!p->lchild) // 建立当前节点的前驱线索
        {
            p->lchild = *pre;
            p->ltag = true;
        }

        if (*pre && !(*pre)->rchild) // 建立前驱节点的后继线索
        {
            (*pre)->rchild = p;
            (*pre)->rtag = true;
        }

        *pre = p; // 使pre指向当前节点，即当p指向后继的时候，pre为p的前驱

        InThread(p->rchild, pre); // 递归，右子树线索化
    }
}

// 通过递归中序遍历建立中序线索二叉树
void createInThread(TBTNode *root)
{
    if (root)
    {
        TBTNode **pre = NULL; // 前驱节点指针
        InThread(root, pre);

        // 这里最后处理中序最后一个节点
        (*pre)->rchild = NULL;
        (*pre)->rtag = true;
    }
}

// 求以p为根的中序线索二叉树中，中序序列下的第一个节点算法
TBTNode *First(TBTNode *p)
{
    // 求取最左下节点
    while (!p->ltag)
        p = p->lchild;
    return p;
}

// 求在中序线索二叉树中，节点p在中序下的后继节点的算法
void *Next(TBTNode *p)
{
    if (!p->rtag)
        return First(p->rchild);
    else
        return p->rchild;
}

// 求中序序列下最后一个节点的函数
TBTNode *Last(TBTNode *p)
{
    // 求最右下节点
    while (!p->rtag)
        p = p->rchild;
    return p;
}

// 求中序序列下前驱节点的函数
TBTNode *Prior(TBTNode *p)
{
    if (!p->ltag)
        return Last(p->lchild);
    else
        return p->lchild;
}

// 在中序线索二叉树上执行中序遍历的算法
void Inorder(TBTNode *root)
{
    for (TBTNode *p = First(root); p; p = Next(p))
        Visit(p);
}

// 先序线索二叉树
void preThread(TBTNode *p, TBTNode **pre)
{
    if (p)
    {
        if (!p->lchild)
        {
            p->lchild = *pre;
            p->ltag = true;
        }

        if (*pre && !(*pre)->rchild)
        {
            (*pre)->rchild = p;
            (*pre)->rtag = true;
        }

        *pre = p;

        // 这里注意递归条件需要判定不是线索才能够递归，刚才的操作有可能改变p的左子树指向
        if (!p->ltag)
            preThread(p->lchild, pre);
        if (!p->rtag)
            preThread(p->rchild, pre);
    }
}

// 在先序线索二叉树上执行先序遍历的算法
void Preorder(TBTNode *root)
{
    if (root)
    {
        TBTNode *p = root;
        while (p)
        {
            while (!p->ltag) // 左指针不是线索，此时p为顶点节点，边访问边左移
            {
                Visit(p);
                p = p->lchild;
            }
            Visit(p);      // 此时左指针为线索，但顶点还未被访问，访问
            p = p->rchild; // 此时p没有左子节点，右子节点要么为子节点，要么为线索（即后继），总之去右边重复过程
        }
    }
}

// 后序线索二叉树
void postThread(TBTNode *p, TBTNode **pre)
{
    if (p)
    {
        postThread(p->lchild, pre); // 递归，左子树线索化
        postThread(p->rchild, pre); // 递归，右子树线索化

        if (!p->lchild)
        {
            p->lchild = *pre;
            p->ltag = true;
        }

        if (*pre && !(*pre)->rchild)
        {
            (*pre)->rchild = p;
            (*pre)->rtag = true;
        }

        *pre = p;
    }
}

/****************************************************************************************************************/

/***********************************************  树和森林与二叉树的互相转换  ********************************************************/
/*

树转换为二叉树
1. 将每个节点的子节点从左到右除了第一个和父节点的连接保留外，其他的连接全部断开
2. 从左至右兄弟节点依次指针指向连接

二叉树转换为树
做上述相反的操作即可

森林转换为二叉树
1. 将森林中每个树转换为二叉树（则根节点必最多只有一个子节点）
2. 将第一个树的右子节点指针指向第二个树的根节点，第二个树的根节点的右子节点指针指向第三个树的根节点...以此类推

二叉树转化为森林
1. 先将每个独立的树拆出来（即断开每个根节点的右子节点指针）
2. 按照二叉树转换为树的方法对每个树进行转换

树和森林的遍历
1. 对树：先序遍历和后序遍历。
2. 对森林：先序遍历和后序遍历。
都是和二叉树先序遍历和后序遍历一样的概念。

*/
/****************************************************************************************************************/

/***********************************************  树与二叉树的应用  ********************************************************/
/*

1. 二叉排序树与二叉平衡树
2. Huffman树

*/
/****************************************************************************************************************/

int main(int argc, char *argv[])
{
    return 0;
}