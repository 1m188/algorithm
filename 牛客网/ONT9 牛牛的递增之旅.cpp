/*
描述
牛牛在冒险旅程中发现了一串神奇的链表。这个链表中的每个节点都包含一个指向下一个节点的指针。牛牛发现，这个链表是一个非常特殊的链表，它是一个递增的链表。然而，牛牛发现了一个问题，链表中可能会有重复的元素。为了解决这个问题，牛牛想要将这个链表转换成一个没有重复元素的链表。请你帮助牛牛实现这个函数。
示例1
输入：
{1,2,2}
复制
返回值：
{1,2}
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
    ListNode *removeDuplicates(ListNode *head) {
        // write code here

        ListNode *cur = head;

        while (cur && cur->next) {

            if (cur->next->val == cur->val) {
                cur->next = cur->next->next;
            } else
                cur = cur->next;
        }

        return head;
    }
};