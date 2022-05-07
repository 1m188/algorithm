/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.30%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    20.6K
 * Total Submissions: 43.4K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。
 * 
 * 示例 :
 * 给定二叉树
 * 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 
 */

#include "cstddef"
#include "algorithm"
#include "limits"
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
    int maxDiameter = INT_MIN;

    int deepth(TreeNode *root)
    {
        if (root)
        {
            return 1 + max(deepth(root->left), deepth(root->right));
        }
        else
        {
            return 0;
        }
    }

    int getDiameter(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            return deepth(root->left) + deepth(root->right);
        }
    }

    void midFind(TreeNode *root)
    {
        if (root)
        {
            midFind(root->left);
            int diameter = getDiameter(root);
            if (diameter > maxDiameter)
            {
                maxDiameter = diameter;
            }
            midFind(root->right);
        }
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        midFind(root);
        return maxDiameter;
    }
};
// @lc code=end
