/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 *
 * https://leetcode-cn.com/problems/binary-tree-tilt/description/
 *
 * algorithms
 * Easy (52.97%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 16K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个二叉树，计算整个树的坡度。
 * 
 * 一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。
 * 
 * 整个树的坡度就是其所有节点的坡度之和。
 * 
 * 示例:
 * 
 * 
 * 输入: 
 * ⁠        1
 * ⁠      /   \
 * ⁠     2     3
 * 输出: 1
 * 解释: 
 * 结点的坡度 2 : 0
 * 结点的坡度 3 : 0
 * 结点的坡度 1 : |2-3| = 1
 * 树的坡度 : 0 + 0 + 1 = 1
 * 
 * 
 * 注意:
 * 
 * 
 * 任何子树的结点的和不会超过32位整数的范围。
 * 坡度的值不会超过32位整数的范围。
 * 
 * 
 */

#include "cstddef"
#include "cmath"

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
    int nodeSum(TreeNode *root)
    {
        return root ? root->val + nodeSum(root->left) + nodeSum(root->right) : 0;
    }

    int slope(TreeNode *root)
    {
        return root ? abs(nodeSum(root->left) - nodeSum(root->right)) : 0;
    }

public:
    int findTilt(TreeNode *root)
    {
        return root ? findTilt(root->left) + slope(root) + findTilt(root->right) : 0;
    }
};
// @lc code=end
