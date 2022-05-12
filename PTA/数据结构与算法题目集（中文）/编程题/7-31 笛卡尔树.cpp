/**
 * @file 7-31 笛卡尔树.cpp
 * @date 2022-05-12
 */

/*
笛卡尔树是一种特殊的二叉树，其结点包含两个关键字K1和K2。
首先笛卡尔树是关于K1的二叉搜索树，即结点左子树的所有K1值都比该结点的K1值小，右子树则大。
其次所有结点的K2关键字满足优先队列（不妨设为最小堆）的顺序要求，
即该结点的K2值比其子树中所有结点的K2值小。给定一棵二叉树，请判断该树是否笛卡尔树。

输入格式:
输入首先给出正整数N（≤1000），为树中结点的个数。
随后N行，每行给出一个结点的信息，包括：
结点的K1值、K2值、左孩子结点编号、右孩子结点编号。设结点从0~(N-1)顺序编号。
若某结点不存在孩子结点，则该位置给出−1。

输出格式:
输出YES如果该树是一棵笛卡尔树；否则输出NO。

输入样例1:
6
8 27 5 1
9 40 -1 -1
10 20 0 3
12 21 -1 4
15 22 -1 -1
5 35 -1 -1

输出样例1:
YES

输入样例2:
6
8 27 5 1
9 40 -1 -1
10 20 0 3
12 11 -1 4
15 22 -1 -1
50 35 -1 -1

输出样例2:
NO

代码长度限制
16 KB

时间限制
400 ms

内存限制
64 MB
*/

/* 1. 按照输入构建树
   2. 判定是否是二叉搜索树
   3. 判定是否是小顶堆
   
这中间有一些坑，值得注意：

1. vector初始化，当使用构造函数初始化类似vector<int> vec(N,int)时，需要注意
他是申请了一个变量int，然后把这个int复制到所有数组元素中去，当使用
vec<Node *> x(N,new Node())时，他是申请了一次Node内存空间，然后将返回来的
指针复制到每个数组元素中去，所以这种方法申请的数组他每个元素的指针指向的都是
同一块内存！！！

2. 二叉搜索树的判定，对于二叉搜索树，其根节点应该大于其左子树每一个节点，
小于右子树每一个节点，不能够仅仅判断根、左子树根，右子树根，这种三元组合
来判定。 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 树节点
 */
struct Node {
    int K1 = 0, K2 = 0;
    Node *left = nullptr, *right = nullptr;
};

/**
 * @brief 根据输入构建树
 * @return Node* 树根节点
 */
Node *build_tree() {
    int N = 0;
    cin >> N;

    // 判定该编号节点是否为根（无父节点）
    vector<bool> root_f(N, true);

    /* 注意！！！！！！！！！！！！！！！！！！！！！！！！！！！！！ */
    /* 不能使用vector<Node *> vec(N,new Node())！！！这是将new返回的同一个
    指针赋值到每一个数组元素中！！！这样每一个元素指向的都是同一个对象！！
    还是要手动每个元素申请和赋值 */
    vector<Node *> vec(N); // 存储树节点指针并为其编号的数组
    for (auto &e : vec)
        e = new Node();
    /*******************************************************/

    for (int i = 0; i < N; i++) {
        cin >> vec[i]->K1 >> vec[i]->K2;

        int lefti = 0, righti = 0;
        cin >> lefti >> righti;
        if (lefti != -1) { // 一方面要指向相应的节点，另一方面要从根的备选节点中擦除
            vec[i]->left = vec[lefti];
            root_f[lefti] = false;
        }
        if (righti != -1) {
            vec[i]->right = vec[righti];
            root_f[righti] = false;
        }
    }

    int idx = -1;
    for (int i = 0; i < N; i++)
        if (root_f[i]) { // 找到那个唯一的true，无父结点，就是根节点
            idx = i;
            break;
        }
    return vec[idx];

    /* 返回之后，数组本身消失，其中所存储的指针也消失，但指针new出来的内存空间还在
    由于之前构建树的时候有left，right等指针指向节点，所以数组及其保存的备份指针
    消失之后，留下的就是真正的树了 */
}

/**
 * @brief 非递归中序遍历 判定是否是二叉搜索树
 * @param root 树根节点
 * @return true 是
 * @return false 否
 */
bool judge_binsearch(Node *root) {
    vector<Node *> st;
    Node *pre = nullptr;

    while (!st.empty() || root) {
        if (root) {
            st.push_back(root);
            root = root->left;
        } else {
            root = st.back();
            st.pop_back();

            // 前者节点值大于等于当前节点值，不符合严格递增的定义
            if (pre && pre->K1 >= root->K1)
                return false;

            pre = root;
            root = root->right;
        }
    }

    return true;
}

/**
 * @brief 递归判定是否是小顶堆
 * @param root 数根节点
 * @return true 是
 * @return false 否
 */
bool judge_priority(Node *root) {
    if (!root || (!root->left && !root->right))
        return true;

    if (root->left) {
        if (root->left->K2 <= root->K2)
            return false;
        if (!judge_priority(root->left))
            return false;
    }
    if (root->right) {
        if (root->right->K2 <= root->K2)
            return false;
        if (!judge_priority(root->right))
            return false;
    }

    return true;
}

int main() {
    Node *root = build_tree();
    if (judge_binsearch(root) && judge_priority(root))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}