/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (57.93%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    47.1K
 * Total Submissions: 81.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 
 * 
 * 进阶：
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 8 -> 0 -> 7
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
    void rev(ListNode *h)
    {
        ListNode *n = h->next;
        h->next = nullptr;

        while (n)
        {
            ListNode *t = n;
            n = n->next;
            t->next = h->next;
            h->next = t;
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l1h = new ListNode(0), *l2h = new ListNode(0);
        l1h->next = l1, l2h->next = l2;

        rev(l1h), rev(l2h);
        l1 = l1h->next, l2 = l2h->next;

        ListNode *nh = new ListNode(0);

        bool add = false;
        while (l1 && l2)
        {
            int res = l1->val + l2->val + add;
            ListNode *n = new ListNode(res % 10);
            n->next = nh->next;
            nh->next = n;
            add = res / 10;
            l1 = l1->next, l2 = l2->next;
        }

        if (l1)
            l2 = l1;
        while (l2)
        {
            int res = l2->val + add;
            ListNode *n = new ListNode(res % 10);
            n->next = nh->next;
            nh->next = n;
            add = res / 10;
            l2 = l2->next;
        }

        if (add)
        {
            ListNode *n = new ListNode(1);
            n->next = nh->next;
            nh->next = n;
        }

        delete l1h;
        delete l2h;
        l2 = nh->next;
        delete nh;
        return l2;
    }
};
// @lc code=end
