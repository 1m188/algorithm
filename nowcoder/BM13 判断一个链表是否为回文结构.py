'''
描述
给定一个链表，请判断该链表是否为回文结构。
回文是指该字符串正序逆序完全一致。
数据范围： 链表节点数 0 \le n \le 10^50≤n≤10 
5
 ，链表中每个节点的值满足 |val| \le 10^7∣val∣≤10 
7
 
示例1
输入：
{1}
复制
返回值：
true
复制
示例2
输入：
{2,1}
复制
返回值：
false
复制
说明：
2->1     
示例3
输入：
{1,2,2,1}
复制
返回值：
true
复制
说明：
1->2->2->1     
'''


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head ListNode类 the head
# @return bool布尔型
#
class Solution:

    def isPail(self, head: ListNode) -> bool:
        # write code here

        li = []
        cur = head
        while cur:
            li.append(cur.val)
            cur = cur.next
        return li == list(reversed(li))
