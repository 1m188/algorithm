'''

描述
给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为
1
→
2
→
3
→
3
→
4
→
4
→
5
1→2→3→3→4→4→5, 返回
1
→
2
→
5
1→2→5.
给出的链表为
1
→
1
→
1
→
2
→
3
1→1→1→2→3, 返回
2
→
3
2→3.

数据范围：链表长度 
0
≤
�
≤
10000
0≤n≤10000，链表中的值满足 
∣
�
�
�
∣
≤
1000
∣val∣≤1000
要求：空间复杂度 
�
(
�
)
O(n)，时间复杂度 
�
(
�
)
O(n)
进阶：空间复杂度 
�
(
1
)
O(1)，时间复杂度 
�
(
�
)
O(n)
示例1
输入：
{1,2,2}
复制
返回值：
{1}
复制
示例2
输入：
{}
复制
返回值：
{}

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

        def dfs(node: ListNode) -> ListNode:
            if not node: return node
            if not node.next: return node
            f = False
            while node.next and node.val == node.next.val:
                f = True
                node.next = node.next.next
            if not f:
                node.next = dfs(node.next)
                return node
            else:
                return dfs(node.next)

        return dfs(head)
