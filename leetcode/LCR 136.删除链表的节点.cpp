/*
 * @lc app=leetcode.cn id=LCR 136 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 136] 删除链表的节点
 *
 * https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/description/
 *
 * algorithms
 * Easy (59.28%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    400.6K
 * Total Submissions: 675.8K
 * Testcase Example:  '[4,5,1,9]\n5'
 *
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
 *
 * 返回删除后的链表的头节点。
 *
 * 示例 1:
 *
 * 输入: head = [4,5,1,9], val = 5
 * 输出: [4,1,9]
 * 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
 *
 *
 * 示例 2:
 *
 * 输入: head = [4,5,1,9], val = 1
 * 输出: [4,5,9]
 * 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 *
 *
 *
 *
 * 说明：
 *
 *
 * 题目保证链表中节点的值互不相同
 * 若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点
 *
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
    ListNode *deleteNode(ListNode *head, int val) {
        if (head->val == val) return head->next;
        ListNode *cur = head;
        while (cur->next) {
            ListNode *next = cur->next;
            if (next->val == val) {
                cur->next = next->next;
                break;
            } else {
                cur = next;
            }
        }
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,5,1,9]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,5,1,9]\n1\n
// @lcpr case=end

 */
