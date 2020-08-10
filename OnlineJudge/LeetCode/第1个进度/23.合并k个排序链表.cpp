/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (49.50%)
 * Likes:    835
 * Dislikes: 0
 * Total Accepted:    154K
 * Total Submissions: 292.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
private:
    void adjust_heap(vector<ListNode *> &vec, int left, int right)
    {
        auto tmp = vec[left];
        int m = left * 2 + 1;
        while (m <= right)
        {
            if (m + 1 <= right && vec[m + 1]->val < vec[m]->val)
                m++;
            if (vec[m]->val < tmp->val)
            {
                vec[left] = vec[m];
                left = m;
                m = left * 2 + 1;
            }
            else
                break;
        }
        vec[left] = tmp;
    }

    void build_heap(vector<ListNode *> &vec)
    {
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            adjust_heap(vec, i, vec.size() - 1);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        for (auto it = lists.begin(); it < lists.end();)
            if (!*it)
                it = lists.erase(it);
            else
                it++;

        build_heap(lists);

        ListNode *hd = new ListNode(0);
        ListNode *c = hd;

        while (!lists.empty())
        {
            ListNode *t = lists[0];
            lists[0] = t->next;
            t->next = NULL;
            if (!lists[0])
            {
                swap(lists.front(), lists.back());
                lists.pop_back();
            }
            adjust_heap(lists, 0, lists.size() - 1);
            c->next = t;
            c = c->next;
        }

        c = hd->next;
        delete hd;
        return c;
    }
};
// @lc code=end
