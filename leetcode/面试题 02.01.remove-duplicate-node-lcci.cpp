/*
 * @lc app=leetcode.cn id=面试题 02.01 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.01] 移除重复节点
 *
 * https://leetcode.cn/problems/remove-duplicate-node-lcci/description/
 *
 * LCCI
 * Easy (66.30%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    103.2K
 * Total Submissions: 155.6K
 * Testcase Example:  '[1, 2, 3, 3, 2, 1]'
 *
 * 编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
 *
 * ⁠示例1:
 *
 * ⁠输入：[1, 2, 3, 3, 2, 1]
 * ⁠输出：[1, 2, 3]
 *
 *
 * ⁠示例2:
 *
 * ⁠输入：[1, 1, 1, 1, 2]
 * ⁠输出：[1, 2]
 *
 *
 * 提示：
 *
 *
 * 链表长度在[0, 20000]范围内。
 * 链表元素在[0, 20000]范围内。
 *
 *
 * ⁠进阶：
 *
 * 如果不得使用临时缓冲区，该怎么解决？
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
    ListNode *removeDuplicateNodes(ListNode *head) {
        if (!head) return head;
        unordered_set<int> uset;
        uset.insert(head->val);
        ListNode *cur = head;
        while (cur->next) {
            ListNode *next = cur->next;
            if (uset.find(next->val) == uset.end()) {
                uset.insert(next->val);
                cur = cur->next;
            } else {
                cur->next = next->next;
            }
        }
        return head;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 2, 3, 3, 2, 1]\n
// @lcpr case=end

// @lcpr case=start
// [1, 1, 1, 1, 2]\n
// @lcpr case=end

 */
