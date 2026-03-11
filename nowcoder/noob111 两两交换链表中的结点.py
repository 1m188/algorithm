"""
描述
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。

链表中的元素个数不超过
100
100 个。
示例1
输入：
{7,0,1,2}
复制
返回值：
{0,7,2,1}
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


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
    def swapPairs(self, head: ListNode) -> ListNode:
        # write code here

        if head is None or head.next is None:
            return head

        a, b, c = head, head.next, head.next.next
        b.next = a
        a.next = self.swapPairs(c)
        return b
