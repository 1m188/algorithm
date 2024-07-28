/*
描述
牛牛是一个热爱链表的牛，他喜欢研究链表中元素的特殊性质。最近，他对一类特殊的链表产生了兴趣，这类链表的特点是其中的元素都是按升序排列，并且没有重复的元素。现在，牛牛想要考考你，看看你是否能够删除链表中的重复元素，使得每个元素只出现一次，并返回一个已排序的链表。
示例1
输入：
{1, 1, 1, 2, 2, 3, 4, 4, 5, 5}
复制
返回值：
{1,2,3,4,5}
复制
示例2
输入：
{0, 1, 1, 1, 1, 1}
复制
返回值：
{0,1}
复制
备注：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序排列
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

        ListNode *cur = head;
        while (cur && cur->next) {
            if (cur->next->val == cur->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};