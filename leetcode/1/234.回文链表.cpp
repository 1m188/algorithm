/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.74%)
 * Likes:    400
 * Dislikes: 0
 * Total Accepted:    63.5K
 * Total Submissions: 157K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

#include "vector"

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || (head && !head->next))
        {
            return true;
        }
        else
        {
            std::vector<int> vec;
            while (head)
            {
                vec.push_back(head->val);
                head = head->next;
            }
            int x = 0, y = vec.size() - 1;
            while (x <= y)
            {
                if (vec[x] != vec[y])
                {
                    return false;
                }
                x++, y--;
            }
            return true;
        }
    }
};
// @lc code=end
