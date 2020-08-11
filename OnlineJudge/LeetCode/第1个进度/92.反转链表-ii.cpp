/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (49.47%)
 * Likes:    465
 * Dislikes: 0
 * Total Accepted:    66.9K
 * Total Submissions: 131.1K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */

#include "algorithm"
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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (!head || m == n)
            return head;

        // ListNode *hd = new ListNode(0);
        // hd->next = head;
        // head = hd;

        // vector<int> vec;
        // for (int i = 0; i < m; i++)
        //     head = head->next;
        // ListNode *ht = head;
        // for (int i = 0; i <= n - m; i++, head = head->next)
        //     vec.push_back(head->val);
        // reverse(vec.begin(), vec.end());
        // int idx = 0;
        // for (int i = 0; i <= n - m; i++, ht = ht->next)
        //     ht->val = vec[idx++];

        // head = hd->next;
        // delete hd;
        // return head;

        /*************************************************************/

        ListNode *hd = new ListNode(0);
        hd->next = head;
        head = nullptr;

        ListNode *cur = hd;
        for (int i = 0; i < m - 1; i++)
            cur = cur->next;
        ListNode *pre = cur;
        cur = pre->next;
        pre->next = nullptr;

        ListNode *nh = new ListNode(0);
        ListNode *nt = cur;

        for (int i = 0; i <= n - m; i++)
        {
            ListNode *t = cur;
            cur = cur->next;
            t->next = nh->next;
            nh->next = t;
        }
        nt->next = cur;
        pre->next = nh->next;
        delete nh;

        head = hd->next;
        delete hd;
        return head;
    }
};
// @lc code=end
