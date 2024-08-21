/*
 * @lc app=leetcode.cn id=LCR 123 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 123] 图书整理 I
 *
 * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
 *
 * algorithms
 * Easy (73.93%)
 * Likes:    480
 * Dislikes: 0
 * Total Accepted:    681.3K
 * Total Submissions: 921.5K
 * Testcase Example:  '[3,6,4,1]'
 *
 *
 * 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [3,6,4,1]
 *
 * 输出：[1,4,6,3]
 *
 *
 *
 *
 * 提示：
 *
 * 0 <= 链表长度 <= 10000
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
    vector<int> reverseBookList(ListNode *head) {

        ListNode *head_new = new ListNode();
        ListNode *cur = head_new->next;
        while (head) {
            ListNode *node = head;
            head = head->next;
            node->next = nullptr;
            head_new->next = node;
            node->next = cur;
            cur = node;
        }
        cur = head_new->next;
        delete head_new;

        vector<int> res;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,6,4,1]\n
// @lcpr case=end

 */
