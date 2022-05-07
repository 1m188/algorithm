/*

描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）。 
下图是一个含有5个结点的复杂链表。图中实线箭头表示next指针，虚线箭头表示random指针。为简单起见，指向null的指针没有画出。


示例:
输入:{1,2,3,4,5,3,5,#,2,#}
输出:{1,2,3,4,5,3,5,#,2,#}
解析:我们将链表分为两段，前半部分{1,2,3,4,5}为ListNode，后半部分{3,5,#,2,#}是随机指针域表示。
以上示例前半部分可以表示链表为的ListNode:1->2->3->4->5
后半部分，3，5，#，2，#分别的表示为
1的位置指向3，2的位置指向5，3的位置指向null，4的位置指向2，5的位置指向null
如下图:

示例1
输入：
{1,2,3,4,5,3,5,#,2,#}

返回值：
{1,2,3,4,5,3,5,#,2,#}

*/

/* 这里的思路用的是将每个链表节点后面插入一个新的节点，label值和random值和原来的一样，
之后将每个新节点的random值向后移动一个节点（精髓都在这里），
之后再将新旧两个链表节点分开成两条链表 */

#include <cstddef>

struct RandomListNode
{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL)
    {
    }
};

class Solution
{
public:
    RandomListNode *Clone(RandomListNode *pHead)
    {
        if (!pHead) // 处理特殊空的情况
            return pHead;

        // 在每个旧链表节点后面接上一个新的链表节点复制
        for (RandomListNode *cur = pHead; cur; cur = cur->next->next)
        {
            RandomListNode *n = new RandomListNode(cur->label);
            n->random = cur->random;
            n->next = cur->next;
            cur->next = n;
        }

        // 修改random指针
        for (RandomListNode *cur = pHead->next;;)
        {
            if (cur->random)
                cur->random = cur->random->next;

            if (cur->next)
                cur = cur->next->next;
            else
                break;
        }

        // 重新分开成两个链表
        RandomListNode *h1 = pHead, *h2 = pHead->next; // 老的和新的两个链表的头节点
        RandomListNode *c1 = h1, *c2 = h2;             // 游标指针
        for (RandomListNode *cur = h2->next; cur; cur = cur->next->next)
        {
            c1->next = cur;
            c1 = c1->next;
            c2->next = cur->next;
            c2 = c2->next;
        }
        c1->next = nullptr;
        c2->next = nullptr;

        return h2;
    }
};