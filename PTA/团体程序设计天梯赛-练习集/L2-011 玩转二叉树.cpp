/**
 * @file L2-011 玩转二叉树.cpp
 * @date 2022-05-24
 */

/*
给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
1 2 3 4 5 6 7
4 1 3 2 6 5 7
输出样例：
4 6 1 7 5 3 2
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 通过先序遍历和中序遍历可以重构二叉树，但这里不用重构的方法，而是通过两个数组
直接访问各个子树，题目要求镜像层序遍历，就是先遍历右子树再遍历左子树 */

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief 记录当前子树在中序序列和先序序列中的两端索引
 */
struct Node {
    int pl = 0; // 先序左边界索引
    int pr = 0; // 先序右边界索引
    int il = 0; // 中序左边界索引
    int ir = 0; // 中序右边界索引
};

vector<int> preorder, // 先序序列
    inorder;          // 中序序列

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);

    preorder.resize(n);
    inorder.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);
}

/**
 * @brief 镜像层序遍历
 */
void layerorder() {
    queue<Node> que;
    Node node;
    node.pr = preorder.size() - 1;
    node.ir = inorder.size() - 1;
    que.push(node);

    while (!que.empty()) {
        node = que.front();
        que.pop();

        if (node.pl == 0) // 题目要求的空格
            printf("%d", preorder[node.pl]);
        else
            printf(" %d", preorder[node.pl]);

        // 找到中序序列中的根节点位置
        int idx = node.il;
        while (inorder[idx] != preorder[node.pl])
            idx++;

        // 判断是否有左右子树，如果有则压入队列
        // 这里注意要先访问右子树再访问左子树，镜像层序遍历
        int ln = idx - node.il, rn = node.ir - idx;
        if (rn > 0) { // 先右
            Node t;
            t.pl = node.pl + ln + 1;
            t.pr = node.pr;
            t.il = idx + 1;
            t.ir = node.ir;
            que.push(t);
        }
        if (ln > 0) { // 再左
            Node t;
            t.pl = node.pl + 1;
            t.pr = node.pl + ln - 1;
            t.il = node.il;
            t.ir = idx - 1;
            que.push(t);
        }
    }
}

int main() {
    input();
    layerorder();
    return 0;
}