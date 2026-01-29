'''
描述
给定一个节点数为n的无序单链表，对其按升序排序。

数据范围：0 < n \le 1000000<n≤100000，保证节点权值在[-10^9,10^9][−10 
9
 ,10 
9
 ]之内。
要求：空间复杂度 O(n)O(n)，时间复杂度 O(nlogn)O(nlogn)

示例1
输入：
[1,3,2,4,5]
复制
返回值：
{1,2,3,4,5}
复制
示例2
输入：
[-1,0,-2]
复制
返回值：
{-2,-1,0}
'''


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head ListNode类 the head node
# @return ListNode类
#
class Solution:

    def sortInList(self, head: ListNode) -> ListNode:
        # write code here

        li = []
        cur = head
        while cur:
            li.append(cur.val)
            cur = cur.next
        li.sort()
        cur = head
        while cur:
            cur.val = li.pop(0)
            cur = cur.next
        return head