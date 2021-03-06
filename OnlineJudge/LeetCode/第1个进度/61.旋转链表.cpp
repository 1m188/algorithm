/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (39.97%)
 * Likes:    315
 * Dislikes: 0
 * Total Accepted:    77.3K
 * Total Submissions: 190.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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
    template <typename T>
    void rev(vector<T> &vec, int left, int right)
    {
        while (left < right)
            swap(vec[left++], vec[right--]);
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !k)
            return head;
        vector<int> vec;
        for (const ListNode *c = head; c; c = c->next)
            vec.push_back(c->val);
        k %= vec.size();
        if (!k)
            return head;
        rev(vec, 0, vec.size() - k - 1);
        rev(vec, vec.size() - k, vec.size() - 1);
        rev(vec, 0, vec.size() - 1);
        int idx = 0;
        for (ListNode *c = head; c; c = c->next)
            c->val = vec[idx++];
        return head;
    }
};
// @lc code=end
