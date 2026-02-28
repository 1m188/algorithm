"""
描述
给定一个链表，请你删除链表中所有值等于val的元素。
示例1
输入：
{1,1,4,5,1,4},4
复制
返回值：
{1,1,5,1}
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
# @param val int整型
# @return ListNode类
#
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        # write code here

        if not head:
            return None
        if head.val == val:
            return self.removeElements(head.next, val)

        cur = head
        while cur.next and cur.next.val != val:
            cur = cur.next
        if cur.next and cur.next.val == val:
            cur.next = self.removeElements(cur.next, val)
        return head
