'''

描述
给出一个长度为 n 的单链表和一个值 x ，单链表的每一个值为 listi ，请返回一个链表的头结点，要求新链表中小于 x 的节点全部在大于等于 x 的节点左侧，并且两个部分之内的节点之间与原来的链表要保持相对顺序不变。

例如：
给出 
1
→
4
→
3
→
2
→
5
→
2
1→4→3→2→5→2 和 
�
=
3
x=3
返回 
1
→
2
→
2
→
4
→
3
→
5
1→2→2→4→3→5

数据范围： 
�
≤
200
n≤200 ， 
−
100
≤
�
�
�
�
[
�
]
≤
100
−100≤list[i]≤100
进阶：时间复杂度 
�
(
�
)
O(n) ， 空间复杂度 
�
(
1
)
O(1)
示例1
输入：
{1,4,3,2,5,2},3
复制
返回值：
{1,2,2,4,3,5}
复制
示例2
输入：
{1,2,3,4,1},5
复制
返回值：
{1,2,3,4,1}

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
# @param x int整型
# @return ListNode类
#
class Solution:

    def partition(self, head: ListNode, x: int) -> ListNode:
        # write code here

        small, large = ListNode(0), ListNode(0)

        cur_s = small
        cur_l = large

        cur = head
        while cur:
            if cur.val < x:
                cur_s.next = cur
                cur_s = cur_s.next
                cur = cur.next
                cur_s.next = None
            else:
                cur_l.next = cur
                cur_l = cur_l.next
                cur = cur.next
                cur_l.next = None

        cur_s.next = large.next
        return small.next
