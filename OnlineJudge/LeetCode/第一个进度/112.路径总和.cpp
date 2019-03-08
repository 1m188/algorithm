/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (44.87%)
 * Total Accepted:    11.8K
 * Total Submissions: 26.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
 * 
 */
/**
 * Definition for a binary tree node.
 */

// #include "cstddef"

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
  private:
    bool get(TreeNode *root, const int target, int sum = 0)
    {
        sum += root->val;
        if (!root->left && !root->right)
        {
            return sum == target;
        }
        else
        {
            bool b1 = false;
            if (root->left)
            {
                b1 = get(root->left, target, sum);
            }
            bool b2 = false;
            if (root->right)
            {
                b2 = get(root->right, target, sum);
            }
            return b1 || b2;
        }
    }

  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
        {
            return false;
        }
        else
        {
            return get(root, sum);
        }
    }
};
