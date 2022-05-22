/**
 * @file L2-004 这是二叉搜索树吗？.cpp
 * @date 2022-05-22
 */

/*
一棵二叉搜索树可被递归地定义为具有下列性质的二叉树：对于任一结点，

其左子树中所有结点的键值小于该结点的键值；
其右子树中所有结点的键值大于等于该结点的键值；
其左右子树都是二叉搜索树。
所谓二叉搜索树的“镜像”，即将所有结点的左右子树对换位置后所得到的树。

给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。

输入格式：
输入的第一行给出正整数 N（≤1000）。随后一行给出 N 个整数键值，其间以空格分隔。

输出格式：
如果输入序列是对一棵二叉搜索树或其镜像进行前序遍历的结果，则首先在一行中输出 YES ，然后在下一行输出该树后序遍历的结果。数字间有 1 个空格，一行的首尾不得有多余空格。若答案是否，则输出 NO。

输入样例 1：
7
8 6 5 7 10 8 11
输出样例 1：
YES
5 7 6 8 11 10 8
输入样例 2：
7
8 10 11 8 6 7 5
输出样例 2：
YES
11 8 10 7 5 6 8
输入样例 3：
7
8 6 8 5 10 9 11
输出样例 3：
NO
代码长度限制
16 KB
时间限制
400 ms
内存限制
64 MB
*/

/* 数组下标作为树的左右两部分的标识，注意细节 */

#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec; // 树（数组表示）

/**
 * @brief 输入
 */
void input() {
    int n = 0;
    scanf("%d", &n);

    vec.resize(n);

    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
}

/**
 * @brief 递归判断是否是二叉搜索树
 * @param left 当前待判断树的左边界索引
 * @param right 当前待判断树的右边界索引
 * @param reversed 是否是镜像二叉搜索树
 * @return true 是
 * @return false 否
 */
bool judge(int left, int right, bool reversed) {
    if (left >= right) // 超出索引范围
        return true;

    int idx = left + 1;

    if (reversed) { // 按照是否是镜像进行两棵子树的判断
        while (idx <= right && vec[idx] >= vec[left])
            idx++;
        for (int i = idx; i <= right; i++)
            if (vec[i] >= vec[left])
                return false;

    } else {
        while (idx <= right && vec[idx] < vec[left])
            idx++;
        for (int i = idx; i <= right; i++)
            if (vec[i] < vec[left])
                return false;
    }

    // 递归判断两棵子树内部
    return judge(left + 1, idx - 1, reversed) && judge(idx, right, reversed);
}

/**
 * @brief 后序遍历输出
 * @param left 当前待输出树的左边界索引
 * @param right 当前待输出树的右边界索引
 */
void postorder(int left = 0, int right = vec.size() - 1) {
    // 递归出口
    if (left > right)
        return;
    else if (left == right) {
        printf("%d ", vec[left]);
        return;
    }

    int idx = left + 1;
    if (vec[left] > vec[left + 1]) { // 根据镜像判断两棵子树的范围
        while (idx <= right && vec[idx] < vec[left])
            idx++;
        postorder(left + 1, idx - 1);
        postorder(idx, right);

    } else {
        while (idx <= right && vec[idx] >= vec[left])
            idx++;
        postorder(left + 1, idx - 1);
        postorder(idx, right);
    }

    // 输出当前节点
    // 注意这里要求行首尾不得有多余空格，最后一个输出的是数根节点，
    // 如果是数根节点的话后面就不用再加空格了
    if (left == 0 && right == vec.size() - 1)
        printf("%d", vec[left]);
    else
        printf("%d ", vec[left]);
}

int main() {
    input();
    if (vec.size() == 1) {
        printf("YES\n%d", vec[0]);
    } else if (judge(0, vec.size() - 1, vec[0] < vec[1])) {
        printf("YES\n");
        postorder();
    } else {
        printf("NO");
    }
    return 0;
}