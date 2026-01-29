/*

描述
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
数据范围： 0≤n≤1000，−1000≤节点值≤1000
要求：空间复杂度 O(1)，时间复杂度 O(n)

如输入{1,3,5},{2,4,6}时，合并后的链表为{1,2,3,4,5,6}，所以对应的输出为{1,2,3,4,5,6}，转换过程如下图所示：


或输入{-1,2,4},{1,3,4}时，合并后的链表为{-1,1,2,3,4,4}，所以对应的输出为{-1,1,2,3,4,4}，转换过程如下图所示：

示例1
输入：
{1,3,5},{2,4,6}

返回值：
{1,2,3,4,5,6}

示例2
输入：
{},{}

返回值：
{}

示例3
输入：
{-1,2,4},{1,3,4}

返回值：
{-1,1,2,3,4,4}

*/

#include <cstddef>

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        if (!pHead1 || !pHead2)
            return !pHead1 ? pHead2 : pHead1;

        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            }
            else
            {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
            cur->next = nullptr;
        }

        if (pHead1)
            cur->next = pHead1;
        if (pHead2)
            cur->next = pHead2;

        cur = head->next;

        delete head;

        return cur;
    }
};