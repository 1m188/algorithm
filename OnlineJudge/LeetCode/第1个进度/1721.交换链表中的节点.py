#
# @lc app=leetcode.cn id=1721 lang=python3
#
# [1721] 交换链表中的节点
#
# https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/description/
#
# algorithms
# Medium (64.25%)
# Likes:    48
# Dislikes: 0
# Total Accepted:    13.9K
# Total Submissions: 21.8K
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# 给你链表的头节点 head 和一个整数 k 。
#
# 交换 链表正数第 k 个节点和倒数第 k 个节点的值后，返回链表的头节点（链表 从 1 开始索引）。
#
#
#
# 示例 1：
#
#
# 输入：head = [1,2,3,4,5], k = 2
# 输出：[1,4,3,2,5]
#
#
# 示例 2：
#
#
# 输入：head = [7,9,6,6,7,8,3,0,9,5], k = 5
# 输出：[7,9,6,6,8,7,3,0,9,5]
#
#
# 示例 3：
#
#
# 输入：head = [1], k = 1
# 输出：[1]
#
#
# 示例 4：
#
#
# 输入：head = [1,2], k = 1
# 输出：[2,1]
#
#
# 示例 5：
#
#
# 输入：head = [1,2,3], k = 2
# 输出：[1,2,3]
#
#
#
#
# 提示：
#
#
# 链表中节点的数目是 n
# 1 <= k <= n <= 105
# 0 <= Node.val <= 100
#
#
#

from typing import Optional


class ListNode:

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

        if not head:
            return None

        n = 1
        ptr = head
        while ptr.next:
            ptr = ptr.next
            n += 1

        ptr = head
        for _ in range(k - 1):
            ptr = ptr.next

        p = head
        for _ in range(n - k):
            p = p.next

        p.val, ptr.val = ptr.val, p.val

        return head


# @lc code=end
