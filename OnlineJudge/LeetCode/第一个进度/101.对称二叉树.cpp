/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (45.20%)
 * Total Accepted:    22.8K
 * Total Submissions: 50.4K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */

// Definition for a binary tree node.

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
    bool judge(TreeNode *left, TreeNode *right)
    {
        if (!left)
        {
            return !right;
        }
        else if (!right)
        {
            return false;
        }
        else if (left->val == right->val)
        {
            return judge(left->left, right->right) && judge(left->right, right->left);
        }
        else
        {
            return false;
        }
    }

  public:
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            return judge(root->left, root->right);
        }
        else
        {
            return true;
        }
    }
};
