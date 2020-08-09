/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (64.47%)
 * Likes:    675
 * Dislikes: 0
 * Total Accepted:    81K
 * Total Submissions: 121.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 * 
 * 示例 1:
 * 
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 * 
 * 
 * 示例 2:
 * 
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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
    void quickSort(vector<T> &vec, int left, int right)
    {
        if (left >= right)
            return;

        int low = left, high = right;
        T tmp = vec[low];

        while (low < high)
        {
            while (low < high && vec[high] >= tmp)
                high--;
            if (low < high)
                vec[low++] = vec[high];
            while (low < high && vec[low] <= tmp)
                low++;
            if (low < high)
                vec[high--] = vec[low];
        }
        vec[low] = tmp;
        quickSort(vec, left, low - 1);
        quickSort(vec, low + 1, right);
    }

public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> vec;
        for (const ListNode *cur = head; cur; cur = cur->next)
            vec.push_back(cur->val);
        quickSort(vec, 0, vec.size() - 1);
        int idx = 0;
        for (ListNode *cur = head; cur; cur = cur->next, idx++)
            cur->val = vec[idx];
        return head;
    }
};
// @lc code=end
