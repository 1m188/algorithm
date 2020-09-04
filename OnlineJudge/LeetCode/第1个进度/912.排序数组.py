#
# @lc app=leetcode.cn id=912 lang=python3
#
# [912] 排序数组
#
# https://leetcode-cn.com/problems/sort-an-array/description/
#
# algorithms
# Medium (59.22%)
# Likes:    165
# Dislikes: 0
# Total Accepted:    83.5K
# Total Submissions: 140.4K
# Testcase Example:  '[5,2,3,1]'
#
# 给你一个整数数组 nums，请你将该数组升序排列。
#
#
#
#
#
#
# 示例 1：
#
# 输入：nums = [5,2,3,1]
# 输出：[1,2,3,5]
#
#
# 示例 2：
#
# 输入：nums = [5,1,1,2,0,0]
# 输出：[0,0,1,1,2,5]
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 50000
# -50000 <= nums[i] <= 50000
#
#
#

from typing import List


# @lc code=start
class Solution:
    def qsort(self, nums: List[int], left: int, right: int):
        if left >= right:
            return

        low, high = left, right
        tmp = nums[low]
        while low < high:
            while low < high and nums[high] >= tmp:
                high -= 1
            if low < high:
                nums[low] = nums[high]
                low += 1
            while low < high and nums[low] <= tmp:
                low += 1
            if low < high:
                nums[high] = nums[low]
                high -= 1
        nums[low] = tmp
        self.qsort(nums, left, low - 1)
        self.qsort(nums, low + 1, right)

    def sortArray(self, nums: List[int]) -> List[int]:
        self.qsort(nums, 0, len(nums) - 1)
        return nums


# @lc code=end
