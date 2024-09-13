/*
 * @lc app=leetcode.cn id=LCR 027 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 027] 回文链表
 *
 * https://leetcode.cn/problems/aMhZSa/description/
 *
 * algorithms
 * Easy (60.21%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    81.2K
 * Total Submissions: 134.8K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给定一个链表的 头节点 head ，请判断其是否为回文链表。
 *
 * 如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入: head = [1,2,3,3,2,1]
 * 输出: true
 *
 * 示例 2：
 *
 *
 *
 * 输入: head = [1,2]
 * 输出: false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表 L 的长度范围为 [1, 10^5]
 * 0 <= node.val <= 9
 *
 *
 *
 *
 * 进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 *
 *
 * 注意：本题与主站 234 题相同：https://leetcode-cn.com/problems/palindrome-linked-list/
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
    bool isPalindrome(ListNode *head) {
        vector<ListNode *> vec;
        for (ListNode *cur = head; cur; cur = cur->next)
            vec.push_back(cur);
        reverse(vec.begin(), vec.end());
        for (const auto &e : vec) {
            if (e->val != head->val) return false;
            head = head->next;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,3,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */
