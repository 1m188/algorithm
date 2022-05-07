/*
描述
输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
如果该链表长度小于k，请返回一个长度为 0 的链表。


数据范围：0≤n≤10^5
0≤ai≤10^9
0≤k≤10^9
 
要求：空间复杂度 O(n)，时间复杂度 O(n)
进阶：空间复杂度 O(1)，时间复杂度 O(n)

例如输入{1,2,3,4,5},2时，对应的链表结构如下图所示：

其中蓝色部分为该链表的最后2个结点，所以返回倒数第2个结点（也即结点值为4的结点）即可，
系统会打印后面所有的节点来比较。

示例1
输入：
{1,2,3,4,5},2

返回值：
{4,5}

说明：
返回倒数第2个节点4，系统会打印后面所有的节点来比较。 

示例2
输入：
{2},8

返回值：
{}
*/

/* 双指针

第一个从头走k个，之后第二个跟着从头开始走，
两个指针之间的距离就是k，
第一个指针走到最后面的地方的话，
第二个指针就是目标答案 */

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
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        // write code here

        if (!pHead)
            return nullptr;

        ListNode *cur = pHead;
        while (k--) {
            // 这里需要注意，在没有头节点的情况下，cur是可能走到最后一个节点的后面一个节点
            // 的，即null，这样代表答案应该是第一个节点
            if (cur)
                cur = cur->next;
            else
                return nullptr;
        }

        ListNode *c = pHead;
        while (cur) {
            c = c->next;
            cur = cur->next;
        }

        return c;
    }
};