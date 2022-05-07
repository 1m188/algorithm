/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

//拿数组保存链表的每个节点指针，如果有重复的话说明是环的开头，否则直到最后的NULL就没有环

#include "vector"
#include "algorithm"

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
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        std::vector<ListNode *> vec;
        while (pHead)
        {
            auto it = std::find(vec.begin(), vec.end(), pHead);
            if (it == vec.end())
            {
                vec.push_back(pHead);
                pHead = pHead->next;
            }
            else
            {
                return pHead;
            }
        }
        return NULL;
    }
};