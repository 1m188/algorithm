/**
 * @file JZ18 删除链表的节点.cpp
 * @date 2022-05-09
 */

/*
描述
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。

1.此题对比原题有改动
2.题目保证链表中节点的值互不相同
3.该题只会输出返回的链表和结果做对比，所以若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

数据范围:
0<=链表节点值<=10000
0<=链表长度<=10000
示例1
输入：
{2,5,1,9},5

返回值：
{2,1,9}

说明：
给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 2 -> 1 -> 9   
示例2
输入：
{2,5,1,9},1

返回值：
{2,5,9}

说明：
给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 2 -> 5 -> 9   
*/

/* 递归 */

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode *deleteNode(ListNode *head, int val) {
        // write code here

        if (!head)
            return nullptr;
        if (head->val == val)
            return head->next;
        else {
            head->next = deleteNode(head->next, val);
            return head;
        }
    }
};