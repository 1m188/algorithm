"""
描述
你需要将一个单链表，按照从表头向表尾的顺序转化为一个序列。
示例1
输入：
{1,1,4,5,1,4}
复制
返回值：
[1,1,4,5,1,4]
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
# @param head ListNode类
# @return int整型一维数组
#
class Solution:
    def listnodeToVector(self, head: ListNode) -> List[int]:
        # write code here

        ans = []
        while head:
            ans.append(head.val)
            head = head.next
        return ans
