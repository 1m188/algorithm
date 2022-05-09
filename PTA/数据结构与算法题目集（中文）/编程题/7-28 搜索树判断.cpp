/**
 * @file 7-28 搜索树判断.cpp
 * @date 2022-05-09
 */

/*
对于二叉搜索树，我们规定任一结点的左子树仅包含严格小于该结点的键值，
而其右子树包含大于或等于该结点的键值。如果我们交换每个节点的左子树和右子树，
得到的树叫做镜像二叉搜索树。

现在我们给出一个整数键值序列，
请编写程序判断该序列是否为某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，
如果是，则输出对应二叉树的后序遍历序列。

输入格式:
输入的第一行包含一个正整数N（≤1000），第二行包含N个整数，为给出的整数键值序列，数字间以空格分隔。

输出格式:
输出的第一行首先给出判断结果，如果输入的序列是某棵二叉搜索树或某镜像二叉搜索树的前序遍历序列，
则输出YES，否侧输出NO。如果判断结果是YES，下一行输出对应二叉树的后序遍历序列。
数字间以空格分隔，但行尾不能有多余的空格。

输入样例1:
7
8 6 5 7 10 8 11

输出样例1:
YES
5 7 6 8 11 10 8

输入样例2:
7
8 6 8 5 10 9 11

输出样例2:
NO

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 考察对于树的遍历和操作，题目意思不难理解，主要有两种方法，一种是构建一个树，在
树上直接操作；另一种是直接在给出的数组上操作；这里用的是第二种，注意各种递归及数组判断
的边界条件 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;  // 先序遍历序列
bool flag = true; // 判断是正二叉搜索树还是镜像二叉搜索树

/**
 * @brief 输入初始化
 */
void input() {
    int N = 0;
    cin >> N;
    vec.resize(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    if (N >= 2) // 如果节点大于一个，那么考察根节点和其左子树根节点的大小，判断正反二叉树
        flag = vec[0] > vec[1];
}

/**
 * @brief 递归判断是否是正二叉搜索树或者镜像二叉搜索树
 * @param left 当前子树根节点在先序遍历中的索引
 * @param right 当前子树先序遍历最后一个节点在先序遍历序列数组中的索引
 * @return true 是
 * @return false 否
 */
bool judge(int left = 0, int right = vec.size() - 1) {
    if (right <= left) // 递归边界条件
        return true;

    int idx = left + 1;

    // 这里根据提前判断好的正反二叉树找右子树的第一个节点
    // 并且判断右子树是否仍然符合flag所表示的规则，不符合
    // 直接返回false，符合则继续分别判断两个子树
    if (flag) {
        while (idx <= right && vec[idx] < vec[left])
            idx++;
        for (int i = idx; i <= right; i++)
            if (vec[i] < vec[left])
                return false;
    } else {
        while (idx <= right && vec[idx] >= vec[left])
            idx++;
        for (int i = idx; i <= right; i++)
            if (vec[i] >= vec[left])
                return false;
    }
    return judge(left + 1, idx - 1) && judge(idx, right);
}

/**
 * @brief 输出后序遍历序列
 * @param left 当前子树根节点在先序序列中的索引
 * @param right 当前子树先序遍历最后一个节点在先序序列中的索引
 */
void postorder(int left = 0, int right = vec.size() - 1) {
    if (right < left) // 判断非法
        return;
    else if (right == left) { // 判断唯一节点和某些叶子节点
        cout << vec[left];
        // 这里注意是最后一个节点输出的时候后面不能有空格
        // 而后序遍历最后一个节点就是树根节点
        if (!(left == 0 && right == vec.size() - 1))
            cout << ' ';
        return;
    }

    int idx = left + 1;
    if (flag) { // 分出两个子树
        while (idx <= right && vec[idx] < vec[left])
            idx++;
    } else {
        while (idx <= right && vec[idx] >= vec[left])
            idx++;
    }

    // 分别后序遍历
    postorder(left + 1, idx - 1);
    postorder(idx, right);

    // 后续遍历完两个子树之后对当前节点进行输出（后序遍历：左右中）
    cout << vec[left];
    if (!(left == 0 && right == vec.size() - 1))
        cout << ' ';
}

int main() {
    input();
    if (judge()) {
        cout << "YES\n";
        postorder();
    } else {
        cout << "NO";
    }
    return 0;
}