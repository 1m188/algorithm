/*
题目描述
输入两个链表，找出它们的第一个公共结点。
*/

//从第一个链表的头依次开始和第二个链表的节点比较

#include "cstddef"

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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode *p2 = pHead2;
        while (pHead1)
        {
            while (p2)
            {
                if (p2 == pHead1)
                {
                    return p2;
                }
                else
                {
                    p2 = p2->next;
                }
            }
            pHead1 = pHead1->next;
            p2 = pHead2;
        }
        return pHead1;
    }
};