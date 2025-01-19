'''
描述
给定一个用单链表表示的整数，然后把这个整数加一。

数据范围：链表长度满足 
1
≤
n
≤
1000
 
1≤n≤1000  ，链表上每个节点的值满足 
0
≤
v
a
l
≤
9
 
0≤val≤9  ，可以保证链表在非 0 的情况下没有前导零

例如输入{1,2,3}时，对应的输出为{1,2,4}，转换过程如下图所示：

示例1
输入：
{1,2,3}
复制
返回值：
{1,2,4}
复制
示例2
输入：
{1,2,0}
复制
返回值：
{1,2,1}
复制
示例3
输入：
{9}
复制
返回值：
{1,0}
'''


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

    def plusOne(self, head: ListNode) -> ListNode:
        # write code here
        x, n = self.po(head)
        if x != 0:
            node = ListNode(x)
            node.next = n
            n = node
        return n

    def po(self, node: ListNode) -> tuple[int, ListNode]:
        if not node: return 1, node
        x, n = self.po(node.next)
        node.next = n
        val = node.val + x
        node.val = val % 10
        return val // 10, node
