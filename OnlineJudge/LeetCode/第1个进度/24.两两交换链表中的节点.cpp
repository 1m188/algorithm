/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.89%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    135.3K
 * Total Submissions: 203.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
 * 
 */

#include "cstddef"

struct ListNode
{
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *hd = new ListNode(0);
        hd->next = head;
        head = nullptr;

        for (ListNode *c = hd; c->next && c->next->next; c = c->next->next)
        {
            ListNode *t = c->next->next;
            c->next->next = t->next;
            t->next = c->next;
            c->next = t;
        }

        head = hd->next;
        delete hd;
        return head;
    }
};
// @lc code=end
