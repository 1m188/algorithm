/*
 * @lc app=leetcode.cn id=面试题 04.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.02] 最小高度树
 *
 * https://leetcode.cn/problems/minimum-height-tree-lcci/description/
 *
 * LCCI
 * Easy (79.10%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    52.9K
 * Total Submissions: 66.9K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。示例:给定有序数组:
 * [-10,-3,0,5,9],一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 0          / \        -3   9        /   /      -10  5
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
// @lcpr-template-end
struct TreeNode {
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
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {

        int n = nums.size();
        if (n == 0) return nullptr;
        if (n == 1) return new TreeNode(nums[0]);

        int mid = n / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left, right;
        for (int i = 0; i < mid; i++)
            left.push_back(nums[i]);
        for (int i = mid + 1; i < n; i++)
            right.push_back(nums[i]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
// @lc code=end
