/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (58.85%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 28.9K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 例如：
 * 
 * 
 * 输入: 二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 */

#include "cstddef"
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
    vector<int> bst;

    void midFindGet(TreeNode *root)
    {
        if (root)
        {
            midFindGet(root->left);
            bst.push_back(root->val);
            midFindGet(root->right);
        }
    }

    void midFindSet(TreeNode *root)
    {
        if(root)
        {
            midFindSet(root->left);
            int val = bst[0];
            bst.erase(bst.begin());
            root->val = val;
            midFindSet(root->right);
        }
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        midFindGet(root);
        for (int i = 0; i < bst.size(); i++)
        {
            for (int j = i + 1; j < bst.size(); j++)
            {
                bst[i] += bst[j];
            }
        }
        midFindSet(root);
        return root;
    }
};
// @lc code=end
