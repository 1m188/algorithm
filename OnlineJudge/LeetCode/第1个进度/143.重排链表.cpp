/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (55.03%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    33.8K
 * Total Submissions: 60K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 示例 1:
 * 
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 * 
 * 示例 2:
 * 
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 * 
 */

struct ListNode
{
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
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        head = new ListNode(0, head);
        ListNode *c = head, *cc = head;

        while (cc->next)
        {
            c = c->next;
            cc = cc->next;
            if (cc->next)
                cc = cc->next;
            else
                break;
        }

        cc = new ListNode();
        while (c->next)
        {
            ListNode *t = c->next;
            c->next = t->next;
            t->next = cc->next;
            cc->next = t;
        }

        c = head->next;
        while (cc->next)
        {
            ListNode *t = cc->next;
            cc->next = t->next;
            t->next = c->next;
            c->next = t;
            c = c->next->next;
        }

        delete cc;
        ListNode *t = head;
        head = head->next;
        delete t;
    }
};
// @lc code=end
