/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (72.47%)
 * Likes:    623
 * Dislikes: 0
 * Total Accepted:    213.1K
 * Total Submissions: 294K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 * 
 */

#include "cstddef"
#include "stack"
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
    void recur(TreeNode *n, vector<int> &vec)
    {
        if (n)
        {
            recur(n->left, vec);
            vec.push_back(n->val);
            recur(n->right, vec);
        }
    }

    // 借助栈的中序非递归遍历
    void iter(TreeNode *n, vector<int> &vec)
    {
        stack<TreeNode *> nst;

        while (n || !nst.empty())
        {
            if (n)
            {
                nst.push(n);
                n = n->left;
            }
            else
            {
                n = nst.top();
                vec.push_back(n->val);
                nst.pop();
                n = n->right;
            }
        }
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;

        // recur(root, res);
        iter(root, res);

        return res;
    }
};
// @lc code=end
