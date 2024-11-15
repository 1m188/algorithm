/*
 * @lc app=leetcode.cn id=LCR 154 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 154] 复杂链表的复制
 *
 * https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/description/
 *
 * algorithms
 * Medium (71.45%)
 * Likes:    797
 * Dislikes: 0
 * Total Accepted:    309.7K
 * Total Submissions: 433.5K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random
 * 指针指向链表中的任意节点或者 null。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 *
 * 示例 4：
 *
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -10000 <= Node.val <= 10000
 * Node.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 *
 *
 *
 *
 * 注意：本题与主站 138
 * 题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 *
 *
 *
 */
#include <cstddef>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        auto copyLink = [&](Node *head) -> Node * {
            Node *newhead = new Node(0);
            Node *cur1 = newhead, *cur2 = head;
            while (cur2) {
                cur1->next = new Node(cur2->val);
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            cur1 = newhead->next;
            delete newhead;
            return cur1;
        };

        Node *newhead = copyLink(head);

        unordered_map<Node *, Node *> umap;
        umap[nullptr] = nullptr;
        for (Node *cur1 = head, *cur2 = newhead; cur1; cur1 = cur1->next, cur2 = cur2->next) {
            umap[cur1] = cur2;
        }

        for (Node *cur = head; cur; cur = cur->next) {
            if (!cur->random) continue;
            umap[cur]->random = umap[cur->random];
        }

        return newhead;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[7,null],[13,0],[11,4],[10,2],[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[2,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[3,null],[3,0],[3,null]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
