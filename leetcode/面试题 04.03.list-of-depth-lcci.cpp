/*
 * @lc app=leetcode.cn id=面试题 04.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 04.03] 特定深度节点链表
 *
 * https://leetcode.cn/problems/list-of-depth-lcci/description/
 *
 * LCCI
 * Medium (80.81%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    38.7K
 * Total Submissions: 47.9K
 * Testcase Example:  '[1,2,3,4,5,null,7,8]'
 *
 * 给定一棵二叉树，设计一个算法，创建含有某一深度上所有节点的链表（比如，若一棵树的深度为 D，则会创建出 D
 * 个链表）。返回一个包含所有深度的链表的数组。
 *
 *
 *
 * 示例：
 *
 * 输入：[1,2,3,4,5,null,7,8]
 *
 * ⁠       1
 * ⁠      /  \
 * ⁠     2    3
 * ⁠    / \    \
 * ⁠   4   5    7
 * ⁠  /
 * ⁠ 8
 *
 * 输出：[[1],[2,3],[4,5,7],[8]]
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        if (!tree) return {};

        auto getList = [](const vector<TreeNode *> &vec) -> ListNode * {
            if (vec.empty()) return nullptr;
            ListNode *head = new ListNode(vec[0]->val);
            ListNode *cur = head;
            for (int i = 1; i < vec.size(); i++) {
                cur->next = new ListNode(vec[i]->val);
                cur = cur->next;
            }
            return head;
        };

        vector<ListNode *> res;
        vector<TreeNode *> vec{tree};
        while (!vec.empty()) {
            res.push_back(getList(vec));
            vector<TreeNode *> vec1;
            for (TreeNode *node : vec) {
                if (node->left) vec1.push_back(node->left);
                if (node->right) vec1.push_back(node->right);
            }
            vec = vec1;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,null,7,8]1/  \ 2    3/ \    \ 4   5    7/8\n
// @lcpr case=end

 */
