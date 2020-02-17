/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.22%)
 * Total Accepted:    42.3K
 * Total Submissions: 81.1K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *cursor = new ListNode(0);
        ListNode *head = cursor;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cursor->next = l1;
                l1 = l1->next;
                cursor = cursor->next;
            }
            else
            {
                cursor->next = l2;
                l2 = l2->next;
                cursor = cursor->next;
            }
        }
        if (l1)
        {
            cursor->next = l1;
        }
        else
        {
            cursor->next = l2;
        }
        cursor = head;
        head = head->next;
        delete cursor;
        return head;
    }
};
