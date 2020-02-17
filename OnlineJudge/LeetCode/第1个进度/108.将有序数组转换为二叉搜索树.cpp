/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (61.03%)
 * Total Accepted:    13.4K
 * Total Submissions: 21.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 */

// #include "cstddef"

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution
{
  private:
    TreeNode *get(vector<int> &nums, int start, int end, TreeNode *node)
    {
        if (start > end)
        {
            return NULL;
        }
        else
        {
            int mid = (start + end) / 2;
            node = new TreeNode(nums[mid]);
            node->left = get(nums, start, mid - 1, node->left);
            node->right = get(nums, mid + 1, end, node->right);
            return node;
        }
    }

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
        {
            return NULL;
        }
        else
        {
            TreeNode *head = NULL;
            head = get(nums, 0, size - 1, head);
            return head;
        }
    }
};

// #include "vector"
// using namespace std;
