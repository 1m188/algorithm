'''

描述
农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[-100, 100]。牛群中的牛用单链表表示。

现在，农场主想要调整牛群的顺序。给你一个链表的头节点 head ，将链表每头牛向右移动 k 个位置。

示例1
输入：
{1,2,3,4,5,6,7,8,9},3
复制
返回值：
{7,8,9,1,2,3,4,5,6}
复制
示例2
输入：
{1,2,3},4
复制
返回值：
{3,1,2}
复制
备注：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9

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
# @param k int整型
# @return ListNode类
#
class Solution:

    def rotateLeft(self, head: ListNode, k: int) -> ListNode:
        # write code here

        if not head or not head.next: return head

        li = []
        cur = head
        while cur:
            li.append(cur)
            cur = cur.next
            li[-1].next = None

        n = len(li)
        k %= n

        if k != 0:
            li_new = [None for _ in range(n)]
            for i in range(n):
                li_new[(i + k) % n] = li[i]
            li = li_new

        head = ListNode(0)
        cur = head
        while li:
            cur.next = li.pop(0)
            cur = cur.next
        return head.next
