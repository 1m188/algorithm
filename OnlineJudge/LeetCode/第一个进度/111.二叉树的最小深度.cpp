/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (37.18%)
 * Total Accepted:    11.7K
 * Total Submissions: 31.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
 * 
 */
/**
 * Definition for a binary tree node.
 */

// #include "cstddef"
// #include "algorithm"

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
    int min = 1000000;
    void get(TreeNode *root, int num = 1)
    {
        if (!root->left && !root->right)
        {
            if (num < min)
            {
                min = num;
            }
        }
        else
        {
            if (root->left)
            {
                get(root->left, num + 1);
            }
            if (root->right)
            {
                get(root->right, num + 1);
            }
        }
    }

  public:
    int minDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            get(root);
            return min;
        }
    }
};
