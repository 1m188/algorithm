/*

查找——天勤2021数据结构

*/

#include "stddef.h"
#include "stdbool.h"
#include "malloc.h"

/*********************************************  顺序查找法和折半查找法  **************************************************************/

// 顺序查找法
int Search(int r[], int n, int k)
{
    for (int i = 0; i < n; i++)
        if (r[i] == k)
            return i;
    return -1; // 没找到返回-1
}

// 折半查找法
int bSearch(int r[], int n, int k)
{
    int left = 0, right = n - 1;
    int mid = (left + right) / 2;
    while (left < right)
    {
        if (r[mid] == k)
            return mid;
        else if (r[mid] < k)
            left = mid + 1;
        else
            right = mid - 1;
        mid = (left + right) / 2;
    }
    return r[mid] == k ? mid : -1;
}

/***********************************************************************************************************************************/

/*********************************************  二叉排序树和平衡二叉树  **************************************************************/

// 二叉排序树其实就是二分查找法的判定树，对于每个节点来说，其左子树的每个节点不大于（不小于）节点的值，右子树的每个节点不小于（不大于）节点的值
// 的一种树。
// 中序遍历可以获取一个单调的排序。

// 二叉排序树(bst)存储结构
typedef struct BTNode
{
    int key; // 关键字
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

// bst查找关键字的算法
BTNode *BSTSearch(BTNode *bt, int key)
{
    if (bt)
    {
        if (bt->key == key)
            return bt;
        else if (bt->key < key)
            return BSTSearch(bt->rchild, key);
        else
            return BSTSearch(bt->lchild, key);
    }
    else
        return NULL;
}

// bst插入关键字的算法
bool BSTInsert(BTNode **bt, int key)
{
    if (!*bt)
    {
        *bt = (BTNode *)malloc(sizeof(BTNode));
        (*bt)->key = key;
        return true;
    }
    else
    {
        if ((*bt)->key == key)
            return false;
        else if ((*bt)->key > key)
            return BSTInsert(&(*bt)->lchild, key);
        else
            return BSTInsert(&(*bt)->rchild, key);
    }
}

// bst的构造算法
void CreateBST(BTNode **bt, int key[], int n)
{
    *bt = NULL;
    for (int i = 0; i < n; i++)
        BSTInsert(bt, key[i]);
}

/*

bst节点的删除分为三种情况：
    1. 删除节点为叶子节点。这种情况直接删除即可。
    2. 删除节点只有左子树或右子树。这种情况删除节点后把子树的根接上去就可以了。
    3. 删除节点既有左子树也有右子树。这种情况寻找比删除节点小的最大值（即左子树的最右子节点）或比删除节点大的最小值（即右子树的最左子节点），
       二者交换，然后把交换后的下面的节点按照上述规则进行删除。

*/

/*

平衡二叉树（avl）是一种特殊的bst，其保持根节点的左右子树高度差的绝对值小于等于1，并且其每个节点的左右子树也遵循同样的规则。
每次插入节点的时候都有可能造成树的不平衡，此时需要进行调整，将失去平衡的最小子树调整即可。

平衡调整：LL，RR，LR，RL。

*/
/***********************************************************************************************************************************/

// B- B+树   B-树的基本操作

/*

散列(hash)表  根据给定的关键字来计算出关键字在表中的地址

查找成功ASL为对每个元素查找时需要比较的次数之和除以元素总数
查找失败ASL为对每个地址查找到第一个空地址时所需要的比较次数之和除以地址总数

常用hash函数构造方法：
    1. 直接定址法
    2. 数字分析法
    3. 平方取中法
    4. 除留余数法  所选的数应尽量为小于等于表长的素数

常用hash冲突处理方法：
    1. 开放定址法
        i 线性探查法  容易产生堆积问题
        ii 平方探查法  不一定能够探查得到所有地址，至少探查得到一半
    2. 链地址法

*/
/***********************************************************************************************************************************/

int main(int argc, char *argv[])
{
    return 0;
}