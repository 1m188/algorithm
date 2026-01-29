'''

描述
农场里有一群牛，每头牛都有一个独特的编号，编号由一个整数表示，整数范围是[0, 200]。牛群中的牛用单链表表示，链表已经按照非降序排列。

因为一些事故，导致一头牛可能多次出现在链表中。给你一个链表的头 head，删除链表中所有重复的编号，只留下所有牛的不重复编号。返回已排序的链表。

示例1
输入：
{1,2,2,3,3,4,5,5}
复制
返回值：
{1,2,3,4,5}
复制
备注：
链表中节点数目在范围 [0, 1000] 内
0 <= Node.val <= 200

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

    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # write code here

        if not head: return head

        cur = head
        while cur.next:
            if cur.val == cur.next.val:
                cur.next = cur.next.next
            else:
                cur = cur.next
        return head
