'''

描述
给你一个链表，请你两两交换相邻节点，你需要真正交换节点本身，而不是修改节点的值。

两两交换示例：
链表    ：1->2->3->4
交换后 ：2->1->4->3


链表    ：1->2->3
交换后： 2->1->3

数据范围：链表长度满足 
1
≤
�
≤
100
 
1≤n≤100  , 链表上的值满足 
1
≤
�
�
�
≤
100
 
1≤val≤100 
示例1
输入：
{1,2,3,4}
复制
返回值：
{2,1,4,3}
复制
示例2
输入：
{1,2,3}
复制
返回值：
{2,1,3}

'''


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next: ListNode = None


# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head ListNode类
# @return ListNode类
#
class Solution:

    def swapLinkedPair(self, head: ListNode) -> ListNode:
        # write code here

        h1, h2 = ListNode(0), ListNode(0)
        cur1, cur2 = h1, h2

        cur = head
        while cur:
            cur1.next = cur
            cur = cur.next
            cur1 = cur1.next
            cur1.next = None
            if not cur: break
            cur2.next = cur
            cur = cur.next
            cur2 = cur2.next
            cur2.next = None

        h = ListNode(0)
        cur = h
        cur1, cur2 = h1.next, h2.next
        while cur1 and cur2:
            cur.next = cur2
            cur2 = cur2.next
            cur = cur.next
            cur.next = None
            cur.next = cur1
            cur1 = cur1.next
            cur = cur.next
            cur.next = None
        if cur1: cur.next = cur1
        if cur2: cur.next = cur2

        return h.next
