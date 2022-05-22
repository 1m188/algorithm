/**
 * @file L2-006 树的遍历.cpp
 * @date 2022-05-22
 */

/*
给定一棵二叉树的后序遍历和中序遍历，请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。

输入格式：
输入第一行给出一个正整数N（≤30），是二叉树中结点的个数。第二行给出其后序遍历序列。第三行给出其中序遍历序列。数字间以空格分隔。

输出格式：
在一行中输出该树的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7
输出样例：
4 1 6 3 5 7 2
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 模拟普通的层序遍历，但是在两个数组上，不断地通过中序遍历和后序遍历找出
两棵子树，并且压入队列待后访问 */

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

/**
 * @brief 索引信息
          将当前子树的中序遍历端点索引和后序遍历端点索引
          保存起来（包括端点）
 */
struct Index {
    int pl = 0; // 后序遍历左边界
    int pr = 0; // 后序遍历右边界
    int il = 0; // 中序遍历左边界
    int ir = 0; // 中序遍历右边界
};

vector<int> postorder, // 后序遍历序列
    inorder;           // 中序遍历序列

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);

    postorder.resize(n);
    inorder.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
}

/**
 * @brief 模拟层序遍历
 */
void layerorder() {

    Index index;
    index.pr = postorder.size() - 1;
    index.ir = inorder.size() - 1;

    queue<Index> que({index}); // 将第一个头节点压入

    while (!que.empty()) {

        index = que.front();
        que.pop();

        // 按照格式输出
        if (index.pr == postorder.size() - 1)
            printf("%d", postorder[index.pr]);
        else
            printf(" %d", postorder[index.pr]);

        // 找出两棵子树的中序序列分界点
        int idx = index.il;
        while (idx <= index.ir && inorder[idx] != postorder[index.pr])
            idx++;

        // 判定左右子树是否存在
        int ln = idx - index.il, rn = index.ir - idx;

        if (ln > 0) {
            Index t;
            t.pl = index.pl;
            t.pr = index.pl + ln - 1;
            t.il = index.il;
            t.ir = idx - 1;
            que.push(t);
        }
        if (rn > 0) {
            Index t;
            t.pl = index.pl + ln;
            t.pr = index.pr - 1;
            t.il = idx + 1;
            t.ir = index.ir;
            que.push(t);
        }
    }
}

int main() {
    input();
    layerorder();
    return 0;
}