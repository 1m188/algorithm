/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (39.14%)
 * Likes:    205
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 29.2K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
 * 
 * 注意：两个节点之间的路径长度由它们之间的边数表示。
 * 
 * 示例 1:
 * 
 * 输入:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
 * 
 */

#include "cstddef"
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
    int maxLen = 1;
    int findPath(TreeNode *root, int val)
    {
        if (root && root->val == val)
        {
            return 1 + max(findPath(root->left, val), findPath(root->right, val));
        }
        else
        {
            return 0;
        }
    }

    void preFind(TreeNode *root)
    {
        if (root)
        {
            maxLen = max(maxLen, 1 + findPath(root->left, root->val) + findPath(root->right, root->val));
            preFind(root->left);
            preFind(root->right);
        }
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        preFind(root);
        return maxLen - 1;
    }
};
// @lc code=end
