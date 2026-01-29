/**
 * @file JZ86 在二叉树中找到两个节点的最近公共祖先.cpp
 * @date 2022-05-11
 */

/*
描述
给定一棵二叉树(保证非空)以及这棵树上的两个节点对应的val值 o1 和 o2，
请找到 o1 和 o2 的最近公共祖先节点。

数据范围：树上节点数满足 1≤n≤10^5, 节点值val满足区间 [0,n)
要求：时间复杂度 O(n)

注：本题保证二叉树中每个节点的val值均不相同。

如当输入{3,5,1,6,2,0,8,#,#,7,4},5,1时，二叉树{3,5,1,6,2,0,8,#,#,7,4}如下图所示：

所以节点值为5和节点值为1的节点的最近公共祖先节点的节点值为3，所以对应的输出为3。
节点本身可以视为自己的祖先
示例1
输入：
{3,5,1,6,2,0,8,#,#,7,4},5,1

返回值：
3

示例2
输入：
{3,5,1,6,2,0,8,#,#,7,4},2,7

返回值：
2
*/

/* 因为每个元素值都不一样，且n个节点值刚好是0-n-1，自然想到能用数组来存储，
每个索引，代表该节点，而又要求祖先，不妨让每个数组索引里的值指向其父节点
索引，自然想到并查集。

1. 遍历一遍树，找到树的总节点数
2. 遍历一遍树，构造并查集
3. 从目标两个节点开始寻找一直到最终根节点的路径
4. 从根节点开始，寻找两条路径最后相同的节点即为结果

遍历了两遍树，找路径也可以看作是O(n)的操作，然后对于两条路径的对比也是O(n)，
整个过程就是O(n)的时间复杂度 */

#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

class Solution {
  private:
    vector<int> vec; // 并查集
    int n = 0;       // 树节点数

    /**
     * @brief 递归先序遍历获取树的节点数
     * @param root 数根节点
     */
    void get_size(TreeNode *root) {
        if (root) {
            n++;
            get_size(root->left);
            get_size(root->right);
        }
    }

    /**
     * @brief 递归先序遍历构建并查集
     * @param root 数根节点
     */
    void build_ufs(TreeNode *root) {
        if (root) {
            if (root->left)
                vec[root->left->val] = root->val;
            if (root->right)
                vec[root->right->val] = root->val;
            build_ufs(root->left);
            build_ufs(root->right);
        }
    }

  public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode *root, int o1, int o2) {
        // write code here

        get_size(root);
        vec.resize(n);
        for (int i = 0; i < n; i++) // 初始化并查集，每个节点默认祖先都是自己
            vec[i] = i;
        build_ufs(root);

        // 构建两条从目标节点到树根节点的路径
        stack<int> o1path({o1}), o2path({o2});
        while (vec[o1] != o1) {
            o1path.push(vec[o1]);
            o1 = vec[o1];
        }
        while (vec[o2] != o2) {
            o2path.push(vec[o2]);
            o2 = vec[o2];
        }

        int ans = 0;
        // 从树根开始找到两条路径最后相等的部分
        // 就是两目标节点最近的公共祖先
        while (!o1path.empty() && !o2path.empty()) {
            if (o1path.top() == o2path.top())
                ans = o1path.top();
            o1path.pop();
            o2path.pop();
        }
        return ans;
    }
};