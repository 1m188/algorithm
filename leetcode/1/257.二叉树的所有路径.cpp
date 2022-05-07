/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (57.45%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    25.1K
 * Total Submissions: 40.4K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
 * 
 */

#include "cstddef"
#include "vector"
#include "string"
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
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
        {
            return vector<string>();
        }
        else if (!root->left && !root->right)
        {
            return vector<string>{to_string(root->val)};
        }
        else
        {
            string rootStr = to_string(root->val);
            vector<string> vec;
            if (root->left)
            {
                auto tmp = binaryTreePaths(root->left);
                for (const string &s : tmp)
                {
                    vec.push_back(rootStr + "->" + s);
                }
            }
            if (root->right)
            {
                auto tmp = binaryTreePaths(root->right);
                for (const string &s : tmp)
                {
                    vec.push_back(rootStr + "->" + s);
                }
            }
            return vec;
        }
    }
};
// @lc code=end
