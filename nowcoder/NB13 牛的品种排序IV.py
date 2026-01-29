'''

描述
在一个牧场中，有n头牛，牛的品种分为黑牛和白牛，用0和1分别表示。现在需要对牛群进行排序，使得相同品种的牛相邻，并按照黑牛和白牛的顺序排列。这些牛是按照链表的形式存储的。

请你在不使用库内置的sort函数的情况下解决这个问题。

示例1
输入：
{1,0,1,0,1,0}
复制
返回值：
{0,0,0,1,1,1}
复制
示例2
输入：
{1,0,0}
复制
返回值：
{0,0,1}
复制
备注：
n == cows.length
1 <= n <= 3000
Node.val 为 0 或 1

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
# @return ListNode类
#
class Solution:

    def sortCowsIV(self, head: ListNode) -> ListNode:
        # write code here

        if not head.next: return head

        li: list[ListNode] = []
        cur = head
        while cur:
            li.append(cur)
            cur = cur.next
            li[-1].next = None

        zeros, ones = [], []
        for node in li:
            if node.val == 0: zeros.append(node)
            else: ones.append(node)

        li = zeros + ones

        head = ListNode(0)
        cur = head
        while li:
            cur.next = li.pop(0)
            cur = cur.next
        return head.next
