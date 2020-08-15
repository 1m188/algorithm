/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.72%)
 * Likes:    620
 * Dislikes: 0
 * Total Accepted:    104.7K
 * Total Submissions: 154.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *prebuild(const vector<int> &preorder, int pl, int pr, const vector<int> &inorder, int il, int ir)
    {
        if (pl > pr || il > ir)
            return nullptr;

        TreeNode *node = new TreeNode(preorder[pl]);
        int idx = il, ln = 0, rn = 0;
        while (inorder[idx] != preorder[pl])
            idx++, ln++;
        rn = ir - idx;

        node->left = prebuild(preorder, pl + 1, pl + ln, inorder, il, idx - 1);
        node->right = prebuild(preorder, pl + ln + 1, pl + ln + rn, inorder, idx + 1, ir);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return prebuild(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
