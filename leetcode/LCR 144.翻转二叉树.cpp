/*
 * @lc app=leetcode.cn id=LCR 144 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 144] 翻转二叉树
 *
 * https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/description/
 *
 * algorithms
 * Easy (79.46%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    390.8K
 * Total Submissions: 491.9K
 * Testcase Example:  '[5,7,9,8,3,2,4]'
 *
 * 给定一棵二叉树的根节点 root，请左右翻转这棵二叉树，并返回其根节点。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：root = [5,7,9,8,3,2,4]
 * 输出：[5,9,7,4,2,3,8]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目范围在 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/
 *
 *
 *
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
    TreeNode *mirrorTree(TreeNode *root) {

        if (!root) return root;
        TreeNode *right = mirrorTree(root->right);
        TreeNode *left = mirrorTree(root->left);
        root->left = right;
        root->right = left;
        return root;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,7,9,8,3,2,4]\n
// @lcpr case=end

 */
