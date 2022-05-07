/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (54.05%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    11.6K
 * Total Submissions: 21.5K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 案例 1:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * 输出: True
 * 
 * 
 * 
 * 
 * 案例 2:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * 输出: False
 * 
 * 
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
    vector<int> vec;
    void midFind(TreeNode *root)
    {
        if (root)
        {
            midFind(root->left);
            vec.push_back(root->val);
            midFind(root->right);
        }
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        midFind(root);
        if (vec.size() < 2)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < vec.size(); i++)
            {
                for (int j = i + 1; j < vec.size(); j++)
                {
                    int cmp = vec[i] + vec[j] - k;
                    if (cmp == 0)
                    {
                        return true;
                    }
                    else if (cmp > 0)
                    {
                        break;
                    }
                }
            }
            return false;
        }
    }
};
// @lc code=end
