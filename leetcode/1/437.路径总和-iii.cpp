/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (54.07%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 40.4K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树，它的每个结点都存放着一个整数值。
 * 
 * 找出路径和等于给定数值的路径总数。
 * 
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。
 * 
 * 示例：
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * 返回 3。和等于 8 的路径有:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3.  -3 -> 11
 * 
 * 
 */

// 本题最难的地方在于没有规定路径的起点和终点，一开始很容易想到前缀和，但是前缀和只对所有数都是正数的情况
// 成立，因此还是用了双重递归

#include "cstddef"

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
    // 寻找以root为根节点的成立的路径
    int findPath(TreeNode *root, int sum)
    {
        // 这里考虑到后面递归的时候可能会进入NULL节点
        if (!root)
        {
            return 0;
        }
        // 这里如果当前节点的值刚好等于目标值则路径成立
        int res = 0;
        if (root->val == sum)
        {
            res += 1;
        }
        // 考虑到题目中对于整数的范围规定是正数和负数，如果从当前成立路径开始后面有0或者正负抵消了
        // 的情况，因此递归传入根节点，判断以新的根节点是否成立路径，sum则减去当前的val说明当前节点
        // 纳入和的考虑之中
        return res + findPath(root->left, sum - root->val) + findPath(root->right, sum - root->val);
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        // 考虑传进来的根节点为空的情况
        if (!root)
        {
            return 0;
        }
        // 寻找当前节点为根节点成立的路径，之后对每个节点递归判断以当前节点为根节点成立的路径
        return findPath(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
// @lc code=end
