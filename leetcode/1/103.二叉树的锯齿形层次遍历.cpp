/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.78%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    65.6K
 * Total Submissions: 119.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

#include "cstddef"
#include "deque"
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};

        deque<TreeNode *> dque;
        vector<vector<int>> res;
        dque.push_back(root);
        bool isLeft = true;

        while (!dque.empty())
        {
            vector<int> vec;
            deque<TreeNode *> ndque;
            while (!dque.empty())
            {
                TreeNode *t = nullptr;
                if (isLeft)
                {
                    t = dque.front();
                    dque.pop_front();
                    if (t->left)
                        ndque.push_back(t->left);
                    if (t->right)
                        ndque.push_back(t->right);
                }
                else
                {
                    t = dque.back();
                    dque.pop_back();
                    if (t->right)
                        ndque.push_front(t->right);
                    if (t->left)
                        ndque.push_front(t->left);
                }
                vec.push_back(t->val);
            }
            res.push_back(vec);
            dque.swap(ndque);
            isLeft = !isLeft;
        }

        return res;
    }
};
// @lc code=end
