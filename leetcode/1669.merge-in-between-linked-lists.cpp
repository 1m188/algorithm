/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 * @lcpr version=30204
 *
 * [1669] 合并两个链表
 *
 * https://leetcode.cn/problems/merge-in-between-linked-lists/description/
 *
 * algorithms
 * Medium (77.08%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    52.6K
 * Total Submissions: 68.3K
 * Testcase Example:  '[10,1,13,6,9,5]\n3\n4\n[1000000,1000001,1000002]'
 *
 * 给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。
 *
 * 请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。
 *
 * 下图中蓝色边和节点展示了操作后的结果：
 *
 * 请你返回结果链表的头指针。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
 * 输出：[10,1,13,1000000,1000001,1000002,5]
 * 解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
 *
 *
 * 示例 2：
 *
 * 输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 =
 * [1000000,1000001,1000002,1000003,1000004]
 * 输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
 * 解释：上图中蓝色的边和节点为答案链表。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= list1.length <= 10^4
 * 1 <= a <= b < list1.length - 1
 * 1 <= list2.length <= 10^4
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {

        ListNode *cura = list1;
        for (int i = 0; i < a - 1; i++)
            cura = cura->next;
        ListNode *curb = list1;
        for (int i = 0; i <= b; i++)
            curb = curb->next;

        cura->next = list2;
        ListNode *cur = cura;
        while (cur->next)
            cur = cur->next;
        cur->next = curb;

        return list1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,1,13,6,9,5]\n3\n4\n[1000000,1000001,1000002]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2,3,4,5,6]\n2\n5\n[1000000,1000001,1000002,1000003,1000004]\n
// @lcpr case=end

 */
