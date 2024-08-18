/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 *
 * https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (64.88%)
 * Likes:    154
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 44.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
 * 
 * 如果有两个中间结点，则返回第二个中间结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4,5]
 * 输出：此列表中的结点 3 (序列化形式：[3,4,5])
 * 返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
 * 注意，我们返回了一个 ListNode 类型的对象 ans，这样：
 * ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next
 * = NULL.
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,3,4,5,6]
 * 输出：此列表中的结点 4 (序列化形式：[4,5,6])
 * 由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定链表的结点数介于 1 和 100 之间。
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
    ListNode *middleNode(ListNode *head)
    {
        int num = 0;
        ListNode *cursor = head;
        while (cursor)
        {
            num++;
            cursor = cursor->next;
        }
        num /= 2;
        while (num--)
        {
            head = head->next;
        }
        return head;
    }
};
// @lc code=end
