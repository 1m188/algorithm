"""
描述
你需要将一个序列，按照从表头向表尾的顺序转化为一个单链表。
示例1
输入：
[1,3,8]
复制
返回值：
{1,3,8}
"""

from typing import List


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
# @param arr int整型一维数组
# @return ListNode类
#
class Solution:
    def vectorToListnode(self, arr: List[int]) -> ListNode:
        # write code here

        head = ListNode(0)
        cur = head
        for i in arr:
            cur.next = ListNode(i)
            cur = cur.next
        return head.next
