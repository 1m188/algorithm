#
# @lc app=leetcode.cn id=1985 lang=python3
# @lcpr version=30204
#
# [1985] 找出数组中的第 K 大整数
#
# https://leetcode.cn/problems/find-the-kth-largest-integer-in-the-array/description/
#
# algorithms
# Medium (44.33%)
# Likes:    60
# Dislikes: 0
# Total Accepted:    16.5K
# Total Submissions: 37.2K
# Testcase Example:  '["3","6","7","10"]\n4'
#
# 给你一个字符串数组 nums 和一个整数 k 。nums 中的每个字符串都表示一个不含前导零的整数。
#
# 返回 nums 中表示第 k 大整数的字符串。
#
# 注意：重复的数字在统计时会视为不同元素考虑。例如，如果 nums 是 ["1","2","2"]，那么 "2" 是最大的整数，"2"
# 是第二大的整数，"1" 是第三大的整数。
#
#
#
# 示例 1：
#
# 输入：nums = ["3","6","7","10"], k = 4
# 输出："3"
# 解释：
# nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
# 其中第 4 大整数是 "3"
#
#
# 示例 2：
#
# 输入：nums = ["2","21","12","1"], k = 3
# 输出："2"
# 解释：
# nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
# 其中第 3 大整数是 "2"
#
#
# 示例 3：
#
# 输入：nums = ["0","0"], k = 2
# 输出："0"
# 解释：
# nums 中的数字按非递减顺序排列为 ["0","0"]
# 其中第 2 大整数是 "0"
#
#
#
#
# 提示：
#
#
# 1 <= k <= nums.length <= 10^4
# 1 <= nums[i].length <= 100
# nums[i] 仅由数字组成
# nums[i] 不含任何前导零
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def kthLargestNumber(self, nums: List[str], k: int) -> str:

        def less(a: str, b: str) -> bool:
            if len(a) < len(b):
                return True
            elif len(a) > len(b):
                return False
            else:
                return a < b

        def adjust(heap: list, start: int, end: int) -> None:
            while True:
                index = start
                if (left := start * 2 + 1) <= end and less(heap[left], heap[index]):
                    index = left
                if (right := start * 2 + 2) <= end and less(heap[right], heap[index]):
                    index = right
                if index == start:
                    break
                heap[index], heap[start] = heap[start], heap[index]
                start = index

        def build_heap(arr: list) -> None:
            n = len(arr)
            for i in range((n - 1 - 1) // 2, -1, -1):
                adjust(arr, i, n - 1)

        heap = nums[:k]
        build_heap(heap)
        for i in range(k, len(nums)):
            if less(heap[0], nums[i]):
                heap[0] = nums[i]
                adjust(heap, 0, k - 1)
        return heap[0]


# @lc code=end


#
# @lcpr case=start
# ["3","6","7","10"]\n4\n
# @lcpr case=end

# @lcpr case=start
# ["2","21","12","1"]\n3\n
# @lcpr case=end

# @lcpr case=start
# ["0","0"]\n2\n
# @lcpr case=end

#
