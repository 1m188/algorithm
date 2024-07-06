/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 *
 * https://leetcode.cn/problems/remove-nodes-from-linked-list/description/
 *
 * algorithms
 * Medium (75.86%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 44.5K
 * Testcase Example:  '[5,2,13,3,8]'
 *
 * 给你一个链表的头节点 head 。
 *
 * 移除每个右侧有一个更大数值的节点。
 *
 * 返回修改后链表的头节点 head 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [5,2,13,3,8]
 * 输出：[13,8]
 * 解释：需要移除的节点是 5 ，2 和 3 。
 * - 节点 13 在节点 5 右侧。
 * - 节点 13 在节点 2 右侧。
 * - 节点 8 在节点 3 右侧。
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,1,1,1]
 * 输出：[1,1,1,1]
 * 解释：每个节点的值都是 1 ，所以没有需要移除的节点。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给定列表中的节点数目在范围 [1, 10^5] 内
 * 1 <= Node.val <= 10^5
 *
 *
 */

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
    ListNode *removeNodes(ListNode *head) {

        if (!head) return nullptr;

        const auto reverse = [=](ListNode *head) -> ListNode * {
            ListNode *newhead = new ListNode(0, nullptr);
            ListNode *cur = head;
            while (cur) {
                ListNode *tmp = cur;
                cur = cur->next;
                tmp->next = nullptr;

                ListNode *next = newhead->next;
                newhead->next = tmp;
                tmp->next = next;
            }
            head = newhead->next;
            delete newhead;
            return head;
        };

        head = reverse(head);

        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->next->val < cur->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }

        head = reverse(head);
        return head;
    }
};
// @lc code=end
