/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (33.52%)
 * Total Accepted:    103.7K
 * Total Submissions: 309.3K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */
/**
 */
//Definition for singly-linked list.

// #include "cstddef"
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(l1->val + l2->val);
        int c = head->val / 10;
        head->val %= 10;
        l1 = l1->next;
        l2 = l2->next;

        ListNode *cursor = head;
        while (l1 && l2)
        {
            cursor->next = new ListNode(l1->val + l2->val + c);
            cursor = cursor->next;
            c = cursor->val / 10;
            cursor->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }

        ListNode *l = l1 ? l1 : l2;
        while (l)
        {
            cursor->next = new ListNode(l->val + c);
            cursor = cursor->next;
            c = cursor->val / 10;
            cursor->val %= 10;
            l = l->next;
        }
        if (c)
        {
            cursor->next = new ListNode(c);
        }

        return head;
    }
};
