/*
 * @lc app=leetcode.cn id=面试题 02.06 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.06] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list-lcci/description/
 *
 * LCCI
 * Easy (49.10%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    69.7K
 * Total Submissions: 142K
 * Testcase Example:  '[1,2]'
 *
 * 编写一个函数，检查输入的链表是否是回文的。
 *
 *
 *
 * 示例 1：
 *
 * 输入： 1->2
 * 输出： false
 *
 *
 * 示例 2：
 *
 * 输入： 1->2->2->1
 * 输出： true
 *
 *
 *
 *
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
    ListNode(int x) : val(x), next(NULL) {}
};
// @lc code=start
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
    bool isPalindrome(ListNode *head) {

        vector<int> x;
        while (head) {
            x.push_back(head->val);
            head = head->next;
        }
        vector<int> y(x.size());
        reverse_copy(x.begin(), x.end(), y.begin());
        return x == y;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1->2\n
// @lcpr case=end

// @lcpr case=start
// 1->2->2->1\n
// @lcpr case=end

 */
