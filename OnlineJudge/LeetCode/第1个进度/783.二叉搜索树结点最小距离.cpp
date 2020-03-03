/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树结点最小距离
 *
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (51.75%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 17.7K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * 给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。
 * 
 * 示例：
 * 
 * 
 * 输入: root = [4,2,6,1,3,null,null]
 * 输出: 1
 * 解释:
 * 注意，root是树结点对象(TreeNode object)，而不是数组。
 * 
 * 给定的树 [4,2,6,1,3,null,null] 可表示为下图:
 * 
 * ⁠         4
 * ⁠       /   \
 * ⁠     2      6
 * ⁠    / \    
 * ⁠   1   3  
 * 
 * 最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 * 
 * 注意：
 * 
 * 
 * 二叉树的大小范围在 2 到 100。
 * 二叉树总是有效的，每个节点的值都是整数，且不重复。
 * 
 * 
 */

#include "cstddef"
#include "vector"
#include "limits"
#include "algorithm"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    vector<int> tree;
    void midFind(TreeNode *root)
    {
        if (root)
        {
            midFind(root->left);
            tree.push_back(root->val);
            midFind(root->right);
        }
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        midFind(root);
        int res = INT_MAX;
        for (int i = tree.size() - 1; i >= 1; i--)
        {
            res = min(res, tree[i] - tree[i - 1]);
        }
        return res;
    }
};
// @lc code=end
