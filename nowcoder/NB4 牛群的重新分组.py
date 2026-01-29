'''

描述
农场里有一群牛，每头牛都有一个编号，编号由一个整数表示，整数范围是[0, 1000]。牛群中的牛用单链表表示。

现在，农场主想要重新分组牛群。给定一个单链表的头指针 head 和一个整数 k，每 k 个节点一组进行翻转，请你返回修改后的牛群链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
示例1
输入：
{1,2,3,4,5},2
复制
返回值：
{2,1,4,3,5}
复制
示例2
输入：
{1,2,3,4,5},3
复制
返回值：
{3,2,1,4,5}
复制
备注：
链表中的节点数目为 n
1 <= k <= n <= 5000
0 <= Node.val <= 10000

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
# @param k int整型
# @return ListNode类
#
class Solution:

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # write code here

        if not head.next or k == 1: return head

        def reverse(li: list, left: int, right: int):
            while left < right:
                li[left], li[right] = li[right], li[left]
                left += 1
                right -= 1

        li = []
        cur = head
        while cur:
            li.append(cur)
            tmp = cur.next
            cur.next = None
            cur = tmp

        left = 0
        while True:
            right = left + k - 1
            if right >= len(li): break
            reverse(li, left, right)
            left += k

        node = ListNode(0)
        cur = node
        while li:
            cur.next = li.pop(0)
            cur = cur.next
        return node.next
