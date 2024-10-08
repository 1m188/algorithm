/*
 * @lc app=leetcode.cn id=面试题 02.03 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.03] 删除中间节点
 *
 * https://leetcode.cn/problems/delete-middle-node-lcci/description/
 *
 * LCCI
 * Easy (85.91%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    103.9K
 * Total Submissions: 120.9K
 * Testcase Example:  '[4,5,1,9]\n5'
 *
 * 若链表中的某个节点，既不是链表头节点，也不是链表尾节点，则称其为该链表的「中间节点」。
 *
 * 假定已知链表的某一个中间节点，请实现一种算法，将该节点从链表中删除。
 *
 * 例如，传入节点 c（位于单向链表 a->b->c->d->e->f 中），将其删除后，剩余链表为 a->b->d->e->f
 *
 *
 *
 * 示例：
 *
 * 输入：节点 5 （位于单向链表 4->5->1->9 中）
 * 输出：不返回任何数据，从链表中删除传入的节点 5，使链表变为 4->1->9
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
    void deleteNode(ListNode *node) {

        swap(node->val, node->next->val);
        node->next = node->next->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 节点 5 （位于单向链表 4->5->1->9 中）\n
// @lcpr case=end

 */
