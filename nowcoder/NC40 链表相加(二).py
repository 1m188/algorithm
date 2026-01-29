'''
描述
假设链表中每一个节点的值都在 0 - 9 之间，那么链表整体就可以代表一个整数。
给定两个这种链表，请生成代表两个整数相加值的结果链表。
数据范围：0 \le n,m \le 10000000≤n,m≤1000000，链表任意值 0 \le val \le 90≤val≤9
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)

例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。

示例1
输入：
[9,3,7],[6,3]
复制
返回值：
{1,0,0,0}
复制
说明：
如题面解释     
示例2
输入：
[0],[6,3]
复制
返回值：
{6,3}
复制
备注：
1 \leq n, m \leq 10^61≤n,m≤10 
6
 
0 \leq a_i, b_i \leq 90≤a 
i
​
 ,b 
i
​
 ≤9
'''


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head1 ListNode类
# @param head2 ListNode类
# @return ListNode类
#
class Solution:

    def add(self, n1: str, n2: str) -> str:

        res = ''
        p = 0
        i, j = len(n1) - 1, len(n2) - 1

        while i >= 0 and j >= 0:
            x = int(n1[i]) + int(n2[j]) + p
            res = str(x % 10) + res
            p = x // 10
            i -= 1
            j -= 1
        while i >= 0:
            x = int(n1[i]) + p
            res = str(x % 10) + res
            p = x // 10
            i -= 1
        while j >= 0:
            x = int(n2[j]) + p
            res = str(x % 10) + res
            p = x // 10
            j -= 1
        if p: res = str(p) + res
        return res

    def addInList(self, head1: ListNode, head2: ListNode) -> ListNode:
        # write code here

        n1, n2 = '', ''

        cur = head1
        while cur:
            n1 += str(cur.val)
            cur = cur.next

        cur = head2
        while cur:
            n2 += str(cur.val)
            cur = cur.next

        n = self.add(n1, n2)

        newhead = ListNode(0)
        cur = newhead
        for c in n:
            cur.next = ListNode(int(c))
            cur = cur.next
        return newhead.next
