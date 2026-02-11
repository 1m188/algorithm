#
# @lc app=leetcode.cn id=面试题 17.14 lang=python3
# @lcpr version=30204
#
# [面试题 17.14] 最小K个数
#
# https://leetcode.cn/problems/smallest-k-lcci/description/
#
# LCCI
# Medium (56.78%)
# Likes:    253
# Dislikes: 0
# Total Accepted:    134K
# Total Submissions: 236.2K
# Testcase Example:  '[1,2,3]\n0'
#
# 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
#
# 示例：
#
# 输入： arr = [1,3,5,7,2,4,6,8], k = 4
# 输出： [1,2,3,4]
#
#
# 提示：
#
#
# 0 <= len(arr) <= 100000
# 0 <= k <= min(100000, len(arr))
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def smallestK(self, arr: List[int], k: int) -> List[int]:

        if k == 0:
            return []

        def adjust(heap: List[int], start: int, end: int) -> None:
            while True:
                index = start
                if start * 2 + 1 <= end and heap[start * 2 + 1] > heap[index]:
                    index = start * 2 + 1
                if start * 2 + 2 <= end and heap[start * 2 + 2] > heap[index]:
                    index = start * 2 + 2
                if index == start:
                    break
                heap[start], heap[index] = heap[index], heap[start]
                start = index

        def build_heap(heap: List[int]) -> None:
            for i in range((len(heap) - 1 - 1) // 2, -1, -1):
                adjust(heap, i, len(heap) - 1)

        heap = [arr[i] for i in range(k)]
        build_heap(heap)
        for i in range(k, len(arr)):
            if arr[i] < heap[0]:
                heap[0] = arr[i]
                adjust(heap, 0, k - 1)
        return heap


# @lc code=end


#
# @lcpr case=start
# [1,3,5,7,2,4,6,8]\n4\n
# @lcpr case=end

#
