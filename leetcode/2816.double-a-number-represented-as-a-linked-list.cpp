/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 * @lcpr version=30204
 *
 * [2816] 翻倍以链表形式表示的数字
 *
 * https://leetcode.cn/problems/double-a-number-represented-as-a-linked-list/description/
 *
 * algorithms
 * Medium (60.34%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    9.7K
 * Total Submissions: 16K
 * Testcase Example:  '[1,8,9]'
 *
 * 给你一个 非空 链表的头节点 head ，表示一个不含前导零的非负数整数。
 *
 * 将链表 翻倍 后，返回头节点 head 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,8,9]
 * 输出：[3,7,8]
 * 解释：上图中给出的链表，表示数字 189 。返回的链表表示数字 189 * 2 = 378 。
 *
 * 示例 2：
 *
 * 输入：head = [9,9,9]
 * 输出：[1,9,9,8]
 * 解释：上图中给出的链表，表示数字 999 。返回的链表表示数字 999 * 2 = 1998 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [1, 10^4] 内
 * 0 <= Node.val <= 9
 * 生成的输入满足：链表表示一个不含前导零的数字，除了数字 0 本身。
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *doubleIt(ListNode *head) {
        function<int(ListNode *)> func = [&](ListNode *node) -> int {
            if (!node) return 0;
            int x = func(node->next);
            int y = node->val * 2 + x;
            node->val = y % 10;
            return y / 10;
        };
        int x = func(head);
        if (x) {
            auto head_new = new ListNode(x);
            head_new->next = head;
            return head_new;
        } else {
            return head;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,8,9]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9]\n
// @lcpr case=end

 */
