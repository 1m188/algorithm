/*

描述
删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次
例如：
给出的链表为
1
→
1
→
2
1→1→2,返回
1
→
2
1→2.
给出的链表为
1
→
1
→
2
→
3
→
3
1→1→2→3→3,返回
1
→
2
→
3
1→2→3.

数据范围：链表长度满足
0
≤
�
≤
100
0≤n≤100，链表中任意节点的值满足
∣
�
�
�
∣
≤
100
∣val∣≤100
进阶：空间复杂度
�
(
1
)
O(1)，时间复杂度
�
(
�
)
O(n)
示例1
输入：
{1,1,2}
复制
返回值：
{1,2}
复制
示例2
输入：
{}
复制
返回值：
{}

*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write code here

        if (!head) return head;

        auto *cur = head;
        while (cur) {
            if (!cur->next) break;
            if (cur->next->val == cur->val) {
                auto *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};