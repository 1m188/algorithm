/**
 * @file NC322 链表的中间结点.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-09-03
 *
 * @copyright Copyright (c) 2025
 *
 */

/*
描述
给定一个头结点为
h
e
a
d
head的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
结点数量介于 1 和 100 之间。
示例1
输入：
{1,2,3}
复制
返回值：
{2,3}
复制
说明：
此列表中的中间为结点 2 ,测评系统对该结点序列化表述是 {2,3}
示例2
输入：
{1,2,3,4}
复制
返回值：
{3,4}
复制
说明：
此列表中的中间为结点 3 ,测评系统对该结点序列化表述是 {3,4}
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
    ListNode *middleNode(ListNode *head) {
        // write code here

        ListNode *head2 = head->next;

        while (true) {
            if (!head2) break;
            head = head->next;
            head2 = head2->next;
            if (!head2) break;
            head2 = head2->next;
            if (!head2) break;
        }

        return head;
    }
};