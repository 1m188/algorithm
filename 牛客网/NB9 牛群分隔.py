'''

描述
农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[0, 100]，同时也表示牛的体重级别。牛群中的牛用单链表表示。

现在，农场主想要调整牛群的顺序，使体重较大的牛在一边，体重较小的牛在一边。给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例1
输入：
{1,2,3,4,5,6,7,8,9},5
复制
返回值：
{1,2,3,4,5,6,7,8,9}
复制
示例2
输入：
{4,3,2,5,2},3
复制
返回值：
{2,2,4,3,5}
复制
备注：
链表中节点的数目在范围 [0, 200] 内
0 <= Node.val <= 100
0 <= x <= 200

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

    def cow_partition(self, head: ListNode, x: int) -> ListNode:
        # write code here

        if not head or not head.next: return head

        li = []
        cur = head
        while cur:
            li.append(cur)
            cur = cur.next
        for i in li:
            i.next = None

        mi, ma = [], []
        for i in li:
            if i.val >= x: ma.append(i)
            else: mi.append(i)

        if not mi or not ma: return head

        head = ListNode(0)
        cur = head
        while mi:
            cur.next = mi.pop(0)
            cur = cur.next
        while ma:
            cur.next = ma.pop(0)
            cur = cur.next
        return head.next
