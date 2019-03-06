/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (44.09%)
 * Total Accepted:    17.7K
 * Total Submissions: 40.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */

//  Definition for singly-linked list.

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head)
        {
            ListNode *cursor = head;
            int val = cursor->val;
            ListNode *last = cursor;
            cursor = cursor->next;
            while (cursor)
            {
                if (cursor->val == val)
                {
                    ListNode *t = cursor;
                    cursor = cursor->next;
                    last->next = cursor;
                    delete t;
                }
                else
                {
                    val = cursor->val;
                    last = cursor;
                    cursor = cursor->next;
                }
            }
        }
        return head;
    }
};
