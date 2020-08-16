/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (70.93%)
 * Likes:    513
 * Dislikes: 0
 * Total Accepted:    76.2K
 * Total Submissions: 107.5K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为一个单链表。
 * 
 * 
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    void dfs(TreeNode *root)
    {
        if (root && (root->left || root->right))
        {
            TreeNode *left = root->left, *right = root->right;
            root->left = root->right = nullptr;
            if (left)
            {
                dfs(left);
                TreeNode *cur = left;
                while (cur->right)
                    cur = cur->right;
                cur->right = right;
                root->right = left;
            }
            else
                root->right = right;
            dfs(right);
        }
    }

    TreeNode *rdfs(TreeNode *root)
    {
        if (root && (root->left || root->right))
        {
            TreeNode *left = root->left, *right = root->right;
            root->left = nullptr;
            TreeNode *n = nullptr;
            if (left)
            {
                n = rdfs(left);
                n->right = right;
                root->right = left;
            }
            if (right)
                n = rdfs(right);
            return n;
        }
        else
            return root;
    }

public:
    void flatten(TreeNode *root)
    {
        dfs(root);
        // rdfs(root);
    }
};
// @lc code=end
