/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (39.89%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    59K
 * Total Submissions: 133.9K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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
    ListNode *removeElements(ListNode *head, int val)
    {
        while (head && head->val == val)
        {
            ListNode *temp = head->next;
            delete head;
            head = temp;
        }

        ListNode *cursor = head;
        while (cursor)
        {
            ListNode *node = cursor->next;
            if (node && node->val == val)
            {
                cursor->next = node->next;
                delete node;
            }
            else
            {
                cursor = cursor->next;
            }
        }

        return head;
    }
};
// @lc code=end
