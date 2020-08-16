/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.75%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    66.7K
 * Total Submissions: 109.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

#include "cstddef"
#include "vector"
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
    vector<vector<int>> res;
    vector<int> path;

    void ps(TreeNode *root, const int sum, int ns = 0)
    {
        if (!(root->left || root->right))
        {
            if (ns + root->val == sum)
            {
                path.push_back(root->val);
                res.push_back(path);
                path.pop_back();
            }
        }
        else
        {
            path.push_back(root->val);
            if (root->left)
                ps(root->left, sum, ns + root->val);
            if (root->right)
                ps(root->right, sum, ns + root->val);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (!root)
            return res;

        ps(root, sum);
        return res;
    }
};
// @lc code=end
