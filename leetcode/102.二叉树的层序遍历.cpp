/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (63.17%)
 * Likes:    606
 * Dislikes: 0
 * Total Accepted:    180.7K
 * Total Submissions: 285.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 
 * 
 * 示例：
 * 二叉树：[3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

#include "cstddef"
#include "queue"
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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        vector<vector<int>> res;
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty())
        {
            queue<TreeNode *> nque;
            vector<int> vec;
            while (!que.empty())
            {
                TreeNode *t = que.front();
                que.pop();
                vec.push_back(t->val);
                if (t->left)
                    nque.push(t->left);
                if (t->right)
                    nque.push(t->right);
            }
            res.push_back(vec);
            que.swap(nque);
        }

        return res;
    }
};
// @lc code=end
