/*
 * @lc app=leetcode.cn id=面试题 04.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.04] 检查平衡性
 *
 * https://leetcode.cn/problems/check-balance-lcci/description/
 *
 * LCCI
 * Easy (59.94%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    49.9K
 * Total Submissions: 83.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。示例 1:给定二叉树
 * [3,9,20,null,null,15,7]    3   / \  9  20    /  \   15   7返回 true 。示例
 * 2:给定二叉树 [1,2,2,3,3,null,null,4,4]      1     / \    2   2   / \  3   3 /
 * \4   4返回 false 。
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lcpr-template-end
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
class Solution {
private:
    int judge(TreeNode *node) {
        if (!node) return 0;
        int left = judge(node->left);
        if (left == -1) return -1;
        int right = judge(node->right);
        if (right == -1) return -1;

        int diff = abs(left - right);
        return diff > 1 ? -1 : max(left, right) + 1; // 注意+1添加上自身的高度
    }

public:
    bool isBalanced(TreeNode *root) {
        return judge(root) != -1;
    }
};
// @lc code=end
