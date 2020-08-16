/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (69.27%)
 * Likes:    264
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 68K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *build(const vector<int> &inorder, const vector<int> &postorder, int il, int ir, int pl, int pr)
    {
        if (il > ir || pl > pr)
            return nullptr;

        TreeNode *node = new TreeNode(postorder[pr]);
        int idx = il, ln = 0, rn = 0;
        while (inorder[idx] != postorder[pr])
            idx++, ln++;
        rn = ir - idx;

        node->left = build(inorder, postorder, il, idx - 1, pl, pl + ln - 1);
        node->right = build(inorder, postorder, idx + 1, ir, pl + ln, pr - 1);
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
// @lc code=end
