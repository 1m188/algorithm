/*
 * @lc app=leetcode.cn id=面试题 02.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.04] 分割链表
 *
 * https://leetcode.cn/problems/partition-list-lcci/description/
 *
 * LCCI
 * Medium (59.54%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    52K
 * Total Submissions: 87.4K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 *
 * 你不需要 保留 每个分区中各节点的初始相对位置。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,4,3,2,5,2], x = 3
 * 输出：[1,2,2,4,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [2,1], x = 2
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 200] 内
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
    ListNode *partition(ListNode *head, int x) {

        ListNode *small = new ListNode(0);
        ListNode *big = new ListNode(0);
        ListNode *cur1 = small, *cur2 = big;

        while (head) {
            if (head->val < x) {
                cur1->next = head;
                head = head->next;
                cur1 = cur1->next;
                cur1->next = nullptr;
            } else {
                cur2->next = head;
                head = head->next;
                cur2 = cur2->next;
                cur2->next = nullptr;
            }
        }

        cur1->next = big->next;
        return small->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
