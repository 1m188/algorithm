/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (56.59%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    47.5K
 * Total Submissions: 80.3K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
 * 
 */

#include "cstddef"
#include "vector"
using namespace std;

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
    ListNode *partition(ListNode *head, int x)
    {
        // vector<int> svec, bvec;
        // for (const ListNode *c = head; c; c = c->next)
        //     if (c->val < x)
        //         svec.push_back(c->val);
        //     else
        //         bvec.push_back(c->val);

        // int idx = 0;
        // ListNode *cur = head;
        // for (; cur && idx < svec.size(); cur = cur->next)
        //     cur->val = svec[idx++];
        // idx = 0;
        // for (; cur && idx < bvec.size(); cur = cur->next)
        //     cur->val = bvec[idx++];
        // return head;

        ListNode *shd = new ListNode(0), *bhd = new ListNode(0);
        ListNode *st = shd, *bt = bhd;
        for (ListNode *c = head; c;)
        {
            ListNode *t = c;
            c = c->next;
            t->next = nullptr;
            if (t->val < x)
            {
                st->next = t;
                st = st->next;
            }
            else
            {
                bt->next = t;
                bt = bt->next;
            }
        }

        st->next = bhd->next;
        delete bhd;
        head = shd->next;
        delete shd;
        return head;
    }
};
// @lc code=end
