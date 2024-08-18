/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (63.13%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 21.9K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 * 
 * 
 * 注意：
 * 
 * 
 * 节点值的范围在32位有符号整数范围内。
 * 
 * 
 */

#include "cstddef"
#include "vector"
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> res;
        queue<TreeNode *> qn;
        qn.push(root);
        while (!qn.empty())
        {
            double average = 0;
            int num = qn.size();
            for (int i = 0; i < num; i++)
            {
                TreeNode *node = qn.front();
                qn.pop();
                average += node->val;
                if (node->left)
                {
                    qn.push(node->left);
                }
                if (node->right)
                {
                    qn.push(node->right);
                }
            }
            res.push_back(average / num);
        }
        return res;
    }
};
// @lc code=end
