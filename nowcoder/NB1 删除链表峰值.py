'''

描述
农场主人有一群牛，他给每只牛都打了一个编号，编号由整数表示。这些牛按照编号的大小形成了一个链表。现在农场主人想删除链表中比前后结点值都大的牛的编号，你能帮他设计一个算法来实现这个功能吗？注意，只考虑删除前，首尾的牛的编号不删除。


示例1
输入：
{1,3,2,4,5}
复制
返回值：
{1,2,4,5}
复制
示例2
输入：
{5,4,3,2,1}
复制
返回值：
{5,4,3,2,1}
复制
备注：
链表长度[0, 10000]
0 < Node.val <= 10000

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

    def deleteNodes(self, head: ListNode) -> ListNode:
        # write code here

        if not head or not head.next or not head.next.next: return head

        li = []
        cur = head
        while cur and cur.next and cur.next.next:
            a, b, c = cur.val, cur.next.val, cur.next.next.val
            if a < b > c: li.append(cur.next)
            cur = cur.next

        cur = head
        while cur.next and li:
            if cur.next == li[0]:
                cur.next = cur.next.next
                li.pop(0)
            else:
                cur = cur.next
        return head
