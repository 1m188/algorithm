/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 *
 * https://leetcode.cn/problems/split-linked-list-in-parts/description/
 *
 * algorithms
 * Medium (60.70%)
 * Likes:    310
 * Dislikes: 0
 * Total Accepted:    65.2K
 * Total Submissions: 107.5K
 * Testcase Example:  '[1,2,3]\n5'
 *
 * 给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。
 *
 * 每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。
 *
 * 这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。
 *
 * 返回一个由上述 k 部分组成的数组。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3], k = 5
 * 输出：[[1],[2],[3],[],[]]
 * 解释：
 * 第一个元素 output[0] 为 output[0].val = 1 ，output[0].next = null 。
 * 最后一个元素 output[4] 为 null ，但它作为 ListNode 的字符串表示是 [] 。
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
 * 输出：[[1,2,3,4],[5,6,7],[8,9,10]]
 * 解释：
 * 输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。前面部分的长度大于等于后面部分的长度。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 1000]
 * 0 <= Node.val <= 1000
 * 1 <= k <= 50
 *
 *
 */

#include <vector>
using namespace std;

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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {

        int length = 0;
        ListNode *cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        vector<ListNode *> res;

        if (k >= length) { // 单个拆分
            ListNode *cur = head;
            while (cur) {
                res.push_back(cur);
                cur = cur->next;
                res.back()->next = nullptr;
            }
            res.resize(k, nullptr);
        } else if (k == 1) { // 无需拆分
            res.push_back(head);
        } else { // 刚好拆分
            if (length % k == 0) {

                int len = length / k;
                ListNode *start = head;
                for (int i = 0; i < k; i++) {
                    ListNode *cur = start;
                    int cnt = 1;
                    while (cnt < len) {
                        cur = cur->next;
                        cnt++;
                    }
                    ListNode *newstart = cur->next;
                    cur->next = nullptr;
                    res.push_back(start);
                    start = newstart;
                }

            } else { // 无法等长拆分

                int len = length / k;
                int remainder = length % k;

                ListNode *start = head;
                for (int i = 0; i < k; i++) {
                    ListNode *cur = start;
                    int cnt = 1;
                    int len_ = len;
                    if (remainder > 0) {
                        len_++;
                        remainder--;
                    }
                    while (cnt < len_) {
                        cur = cur->next;
                        cnt++;
                    }
                    ListNode *newstart = cur->next;
                    cur->next = nullptr;
                    res.push_back(start);
                    start = newstart;
                }
            }
        }

        return std::move(res);
    }
};
// @lc code=end
