/*
 * @lc app=leetcode.cn id=面试题 17.12 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.12] BiNode
 *
 * https://leetcode.cn/problems/binode-lcci/description/
 *
 * LCCI
 * Easy (63.91%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 54.1K
 * Testcase Example:  '[4,2,5,1,3,null,6,0]'
 *
 *
 * 二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求依然符合二叉搜索树的性质，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。
 *
 * 返回转换后的单向链表的头节点。
 *
 * 注意：本题相对原题稍作改动
 *
 *
 *
 * 示例：
 *
 * 输入： [4,2,5,1,3,null,6,0]
 * 输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
 *
 *
 * 提示：
 *
 *
 * 节点数量不会超过 100000。
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
private:
    TreeNode *pre = nullptr;
    TreeNode *head = nullptr;

public:
    TreeNode *convertBiNode(TreeNode *root) {
        if (!root) return nullptr;
        convertBiNode(root->left);
        if (pre == nullptr) {
            pre = root;
        } else {
            pre->left = nullptr;
            pre->right = root;
            root->left = nullptr;
            pre = root;
        }
        if (head == nullptr) head = root;
        convertBiNode(root->right);
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,5,1,3,null,6,0]\n
// @lcpr case=end

 */
