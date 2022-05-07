/*
描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
例如，链表 1->2->3->3->4->4->5  处理后为 1->2->5

数据范围：链表长度满足 0≤n≤1000  ，链表中的值满足 1≤val≤1000 

进阶：空间复杂度 O(n)  ，时间复杂度 O(n)

例如输入{1,2,3,3,4,4,5}时，对应的输出为{1,2,5}，对应的输入输出链表如下图所示：

示例1
输入：
{1,2,3,3,4,4,5}

返回值：
{1,2,5}

示例2
输入：
{1,1,1,8}

返回值：
{8}
*/

/* 递归解决，对于<两个节点的部分，直接返回，对于>=两个节点的部分，前一个节点
就等于后面的节点传入函数之后的结果，对于前两个节点有重合的部分，则直接返回
该类节点后面值不一样的节点指针，递归进行 */

#include <cstddef>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

class Solution {
  public:
    ListNode *deleteDuplication(ListNode *pHead) {

        // 本身为空或者只有一个节点则必不可能有重复，所以直接返回
        if (!pHead || !pHead->next)
            return pHead;

        if (pHead->val == pHead->next->val) { // 两个值相同，找到后面不同的指针进行返回
            ListNode *cur = pHead;
            while (cur && cur->val == pHead->val) // 找一个不相同的
                cur = cur->next;

            // 这里是对于后面不同的值的指针其本身可能还有重复
            // 于是递归进行，直到后面返回来的没有重复了，也就是
            // 除去该节点之后所有重复节点的最终结果
            return deleteDuplication(cur);
        } else { // 如果没有重复，那么该节点的next应指向其后面链表传入函数内容的最终结果
            pHead->next = deleteDuplication(pHead->next);
            return pHead;
        }
    }
};