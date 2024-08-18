/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 *
 * https://leetcode-cn.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (50.86%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 12.5K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
 * 
 * 如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
 * 
 * 我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
 * 
 * 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4], x = 4, y = 3
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 
 * 输入：root = [1,2,3,null,4], x = 2, y = 3
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 二叉树的节点数介于 2 到 100 之间。
 * 每个节点的值都是唯一的、范围为 1 到 100 的整数。
 * 
 * 
 * 
 * 
 */

#include "cstddef"
#include "queue"
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
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root->val == x || root->val == y)
        {
            return false;
        }

        queue<TreeNode *> q;
        q.push(root);
        int num = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                if (node->val == x || node->val == y)
                {
                    num++;
                }
                if (node->left && node->right && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x)))
                {
                    return false;
                }
            }
            if (num == 1)
            {
                return false;
            }
            else if (num == 2)
            {
                break;
            }
        }
        return true;
    }
};
// @lc code=end
