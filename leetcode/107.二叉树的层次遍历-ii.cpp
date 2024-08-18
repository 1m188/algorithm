/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (59.03%)
 * Total Accepted:    10.4K
 * Total Submissions: 17.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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
  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> vec;
        if (root)
        {
            queue<TreeNode *> q;
            q.push(root);
            int num = 1, count = 0;
            while (!q.empty())
            {
                vec.push_back({});
                while (num)
                {
                    TreeNode *node = q.front();
                    q.pop();
                    vec.back().push_back(node->val);
                    num--;
                    if (node->left)
                    {
                        q.push(node->left);
                        count++;
                    }
                    if (node->right)
                    {
                        q.push(node->right);
                        count++;
                    }
                }
                num = count;
                count = 0;
            }
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};

// #include "vector"
// #include "queue"
// #include "algorithm"
// using namespace std;
