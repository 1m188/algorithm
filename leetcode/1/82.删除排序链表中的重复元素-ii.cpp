/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (46.75%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    59.4K
 * Total Submissions: 121.9K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *hd = new ListNode(0);
        hd->next = head;
        head = nullptr;

        for (ListNode *c = hd; c && c->next;)
        {
            ListNode *cc = c->next;
            bool flag = false;
            while (cc->next && cc->next->val == cc->val)
            {
                flag = true;
                ListNode *t = cc->next;
                cc->next = t->next;
                delete t;
            }
            if (flag)
            {
                c->next = cc->next;
                delete cc;
            }
            else
                c = c->next;
        }

        head = hd->next;
        delete hd;
        return head;
    }
};
// @lc code=end
