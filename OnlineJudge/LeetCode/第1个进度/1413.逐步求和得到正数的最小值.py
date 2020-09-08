#
# @lc app=leetcode.cn id=1413 lang=python3
#
# [1413] 逐步求和得到正数的最小值
#
# https://leetcode-cn.com/problems/minimum-value-to-get-positive-step-by-step-sum/description/
#
# algorithms
# Easy (67.66%)
# Likes:    13
# Dislikes: 0
# Total Accepted:    5.7K
# Total Submissions: 8.4K
# Testcase Example:  '[-3,2,-3,4,2]'
#
# 给你一个整数数组 nums 。你可以选定任意的 正数 startValue 作为初始值。
#
# 你需要从左到右遍历 nums 数组，并将 startValue 依次累加上 nums 数组中的值。
#
# 请你在确保累加和始终大于等于 1 的前提下，选出一个最小的 正数 作为 startValue 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [-3,2,-3,4,2]
# 输出：5
# 解释：如果你选择 startValue = 4，在第三次累加时，和小于 1 。
# ⁠               累加求和
# startValue = 4 | startValue = 5 | nums
# (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
# (1 +2 ) = 3  | (2 +2 ) = 4    |   2
# (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
# (0 +4 ) = 4  | (1 +4 ) = 5    |   4
# (4 +2 ) = 6  | (5 +2 ) = 7    |   2
#
#
# 示例 2：
#
#
# 输入：nums = [1,2]
# 输出：1
# 解释：最小的 startValue 需要是正数。
#
#
# 示例 3：
#
#
# 输入：nums = [1,-2,-3]
# 输出：5
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# -100 <= nums[i] <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:
    def one(self, nums: List[int]) -> int:
        '''
        单纯递增startval并遍历验证
        '''
        def jud(nums, num):
            for n in nums:
                num += n
                if num < 1:
                    return False
            return True

        sv = 1
        while True:
            if jud(nums, sv):
                return sv
            else:
                sv += 1

    def rev(self, nums: List[int]) -> int:
        '''
        从后往前递推
        '''
        sv = 1
        for i in reversed(nums):
            sv -= i
            if sv < 1:
                sv = 1
        return sv

    def minStartValue(self, nums: List[int]) -> int:
        # return self.one(nums)
        return self.rev(nums)


# @lc code=end
