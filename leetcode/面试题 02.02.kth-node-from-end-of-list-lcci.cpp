/*
 * @lc app=leetcode.cn id=面试题 02.02 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.02] 返回倒数第 k 个节点
 *
 * https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/description/
 *
 * LCCI
 * Easy (77.29%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    109.3K
 * Total Submissions: 141.4K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 实现一种算法，找出单向链表中倒数第 k 个节点。返回该节点的值。
 *
 * 注意：本题相对原题稍作改动
 *
 * 示例：
 *
 * 输入： 1->2->3->4->5 和 k = 2
 * 输出： 4
 *
 * 说明：
 *
 * 给定的 k 保证是有效的。
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
    int kthToLast(ListNode *head, int k) {

        ListNode *cur = head;
        int cnt = 1;
        while (cur->next) {
            cur = cur->next;
            cnt++;
        }

        cnt = cnt - k;
        cur = head;
        while (cnt--)
            cur = cur->next;
        return cur->val;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

 */
