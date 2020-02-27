/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (55.60%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 17.9K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
 * 
 * 示例 :
 * 
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * 输出:
 * 1
 * 
 * 解释:
 * 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 * 
 * 
 * 注意: 树中至少有2个节点。
 * 
 */

#include "cstddef"
#include "vector"
#include "limits"
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
    int getMinimumDifference(TreeNode *root)
    {
        midFind(root);
        int res = INT_MAX;
        for (int i = 1; i < tree.size(); i++)
        {
            int diff = tree[i] - tree[i - 1];
            if (diff < res)
            {
                res = diff;
            }
        }
        return res;
    }
};
// @lc code=end
