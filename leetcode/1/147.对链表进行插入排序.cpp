/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 *
 * https://leetcode-cn.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (63.55%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 56.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 对链表进行插入排序。
 * 
 * 
 * 插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
 * 每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。
 * 
 * 
 * 
 * 插入排序算法：
 * 
 * 
 * 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
 * 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
 * 重复直到所有输入数据插入完为止。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2：
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return head;

        for (ListNode *ci = head; ci->next;)
        {
            if (ci->next->val >= ci->val)
            {
                ci = ci->next;
                continue;
            }

            ListNode *n = ci->next;
            ci->next = n->next;
            n->next = nullptr;

            if (n->val < head->val)
                n->next = head, head = n;
            else
                for (ListNode *cj = head; cj != ci; cj = cj->next)
                    if (cj->next->val > n->val)
                    {
                        n->next = cj->next;
                        cj->next = n;
                        break;
                    }
        }
        return head;
    }
};
// @lc code=end
