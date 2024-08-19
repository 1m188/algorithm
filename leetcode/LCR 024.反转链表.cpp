/*
 * @lc app=leetcode.cn id=LCR 024 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 024] 反转链表
 *
 * https://leetcode.cn/problems/UHnkqh/description/
 *
 * algorithms
 * Easy (75.35%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    144.5K
 * Total Submissions: 191.8K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1,2]
 * 输出：[2,1]
 *
 *
 * 示例 3：
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 <= Node.val <= 5000
 *
 *
 *
 *
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 *
 *
 *
 *
 *
 * 注意：本题与主站 206 题相同： https://leetcode-cn.com/problems/reverse-linked-list/
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
    ListNode *reverseList(ListNode *head) {

        function<ListNode *(ListNode *, ListNode *)> func = [&](ListNode *next, ListNode *pre) -> ListNode * {
            if (!pre) return next;
            ListNode *cur = pre->next;
            pre->next = next;
            return func(pre, cur);
        };
        return func(nullptr, head);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
