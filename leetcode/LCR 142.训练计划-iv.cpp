/*
 * @lc app=leetcode.cn id=LCR 142 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 142] 训练计划 IV
 *
 * https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/description/
 *
 * algorithms
 * Easy (71.83%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    390.2K
 * Total Submissions: 543.3K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 给定两个以 有序链表 形式记录的训练计划 l1、l2，分别记录了两套核心肌群训练项目编号，请合并这两个训练计划，按训练项目编号 升序
 * 记录于链表并返回。
 *
 * 注意：新链表是通过拼接给定的两个链表的所有节点组成的。
 *
 *
 *
 * 示例 1：
 *
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 *
 * 示例 2：
 *
 * 输入：l1 = [], l2 = []
 * 输出：[]
 *
 * 示例 3：
 *
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 *
 *
 *
 * 提示：
 *
 * 0 <= 链表长度 <= 1000
 *
 *
 *
 * 注意：本题与主站 21 题相同：https://leetcode-cn.com/problems/merge-two-sorted-lists/
 *
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *trainningPlan(ListNode *l1, ListNode *l2) {

        if (!l1 && !l2) return nullptr;
        if (!l1) {
            ListNode *cur = l2->next;
            l2->next = trainningPlan(l1, cur);
            return l2;
        }
        if (!l2) {
            ListNode *cur = l1->next;
            l1->next = trainningPlan(cur, l2);
            return l1;
        }

        if (l1->val < l2->val) {
            ListNode *cur = l1->next;
            l1->next = trainningPlan(cur, l2);
            return l1;
        } else {
            ListNode *cur = l2->next;
            l2->next = trainningPlan(l1, cur);
            return l2;
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,4]\n[1,3,4]\n
// @lcpr case=end

// @lcpr case=start
// []\n[]\n
// @lcpr case=end

// @lcpr case=start
// []\n[0]\n
// @lcpr case=end

 */
