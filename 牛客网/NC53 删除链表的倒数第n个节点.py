'''
描述
给定一个链表，删除链表的倒数第 n 个节点并返回链表的头指针
例如，
给出的链表为: 1\to 2\to 3\to 4\to 51→2→3→4→5, n= 2n=2.
删除了链表的倒数第 nn 个节点之后,链表变为1\to 2\to 3\to 51→2→3→5.

数据范围： 链表长度 0\le n \le 10000≤n≤1000，链表中任意节点的值满足 0 \le val \le 1000≤val≤100
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
备注：
题目保证 nn 一定是有效的
示例1
输入：
{1,2},2    
复制
返回值：
{2} 
'''


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head ListNode类
# @param n int整型
# @return ListNode类
#
class Solution:

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # write code here

        if n == 1:
            if not head.next: return None
            cur = head
            while cur.next.next:
                cur = cur.next
            cur.next = None
            return head

        cur = head
        for _ in range(n):
            cur = cur.next
        cc = head
        while cur:
            cc = cc.next
            cur = cur.next
        if cc != head:
            cc.val, cc.next.val = cc.next.val, cc.val
            cc.next = cc.next.next
            return head
        else:
            return head.next