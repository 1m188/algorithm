'''

描述
合并 k 个升序的链表并将结果作为一个升序的链表返回其头节点。

数据范围：节点总数 
0
≤
�
≤
5000
0≤n≤5000，每个节点的val满足 
∣
�
�
�
∣
<
=
1000
∣val∣<=1000
要求：时间复杂度 
�
(
�
�
�
�
�
)
O(nlogn)
示例1
输入：
[{1,2,3},{4,5,6,7}]
复制
返回值：
{1,2,3,4,5,6,7}
复制
示例2
输入：
[{1,2},{1,4,5},{6}]
复制
返回值：
{1,1,2,4,5,6}

'''

from typing import List


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
# @param lists ListNode类一维数组
# @return ListNode类
#
class Solution:

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        # write code here

        def build_heap(li: list[ListNode]):  # 构建小根堆
            for i in range((len(li) - 1 - 1) // 2, -1, -1):
                adjust(li, i)

        def adjust(li: list[ListNode], index: int):  # 调整小根堆
            length = len(li)
            while True:
                idx = index
                left = index * 2 + 1
                right = index * 2 + 2
                if left < length and li[left].val < li[idx].val: idx = left
                if right < length and li[right].val < li[idx].val: idx = right
                if idx == index: break
                li[index], li[idx] = li[idx], li[index]
                index = idx

        i = 0
        while i < len(lists):
            if not lists[i]: lists.pop(i)
            else: i += 1

        build_heap(lists)
        head = ListNode(0)
        cur = head
        while lists:
            root = lists[0]
            lists[0] = root.next
            root.next = None
            cur.next = root
            cur = cur.next
            if lists[0] == None:
                lists.pop(0)
                if not lists: break
                build_heap(lists)
            else:
                adjust(lists, 0)
        h = head.next
        head.next = None
        del head
        return h
