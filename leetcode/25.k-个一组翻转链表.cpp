/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (57.08%)
 * Likes:    674
 * Dislikes: 0
 * Total Accepted:    91.3K
 * Total Submissions: 146.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
private:
    ListNode *rev(ListNode *head)
    {
        ListNode *n = head->next;
        head->next = nullptr;
        ListNode *nt = n;

        while (n)
        {
            ListNode *t = n;
            n = n->next;
            t->next = head->next;
            head->next = t;
        }

        return nt;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode *hd = new ListNode(0);
        hd->next = head;
        head = nullptr;

        ListNode *curh = new ListNode(0);
        ListNode *cur = hd;
        while (true)
        {
            ListNode *ht = cur;
            for (int i = 0; i < k && cur; i++)
                cur = cur->next;
            if (!cur)
                break;
            curh->next = ht->next;
            ht->next = nullptr;
            ListNode *he = cur->next;
            cur->next = nullptr;
            cur = rev(curh);
            ht->next = curh->next;
            curh->next = nullptr;
            cur->next = he;
        }

        delete curh;
        head = hd->next;
        delete hd;
        return head;
    }
};
// @lc code=end
