'''
描述
给定一个单链表，请设定一个函数，将链表的奇数位节点和偶数位节点分别放在一起，重排后输出。
注意是节点的编号而非节点的数值。

数据范围：节点数量满足 0 \le n \le 10^50≤n≤10 
5
 ，节点中的值都满足 0 \le val \le 10000≤val≤1000
要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
示例1
输入：
{1,2,3,4,5,6}
复制
返回值：
{1,3,5,2,4,6}
复制
说明：
1->2->3->4->5->6->NULL
重排后为
1->3->5->2->4->6->NULL
   
示例2
输入：
{1,4,6,3,7}
复制
返回值：
{1,6,7,4,3}
复制
说明：
1->4->6->3->7->NULL
重排后为
1->6->7->4->3->NULL
奇数位节点有1,6,7，偶数位节点有4,3。重排后为1,6,7,4,3
   
备注：
链表长度不大于200000。每个数范围均在int内。
'''


class ListNode:

    def __init__(self, x):
        self.val = x
        self.next = None


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param head ListNode类
# @return ListNode类
#
class Solution:

    def oddEvenList(self, head: ListNode) -> ListNode:
        # write code here

        odd_head, even_head = ListNode(0), ListNode(0)

        odd_cur, even_cur = odd_head, even_head
        cur = head
        while cur:
            odd_cur.next = ListNode(cur.val)
            odd_cur = odd_cur.next
            cur = cur.next
            if cur:
                even_cur.next = ListNode(cur.val)
                even_cur = even_cur.next
                cur = cur.next

        cur = odd_head
        while cur.next:
            cur = cur.next
        cur.next = even_head.next
        return odd_head.next
