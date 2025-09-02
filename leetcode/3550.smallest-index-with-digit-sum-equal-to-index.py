#
# @lc app=leetcode.cn id=3550 lang=python3
# @lcpr version=30204
#
# [3550] 数位和等于下标的最小下标
#
# https://leetcode.cn/problems/smallest-index-with-digit-sum-equal-to-index/description/
#
# algorithms
# Easy (80.14%)
# Likes:    5
# Dislikes: 0
# Total Accepted:    5.2K
# Total Submissions: 6.5K
# Testcase Example:  '[1,3,2]'
#
# 给你一个整数数组 nums 。
#
# 返回满足 nums[i] 的数位和（每一位数字相加求和）等于 i 的 最小 下标 i 。
#
# 如果不存在满足要求的下标，返回 -1 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,3,2]
#
# 输出：2
#
# 解释：
#
#
# nums[2] = 2，其数位和等于 2 ，与其下标 i = 2 相等。因此，输出为 2 。
#
#
#
# 示例 2：
#
#
# 输入：nums = [1,10,11]
#
# 输出：1
#
# 解释：
#
#
# nums[1] = 10，其数位和等于 1 + 0 = 1，与其下标 i = 1 相等。
# nums[2] = 11，其数位和等于是 1 + 1 = 2，与其下标 i = 2 相等。
# 由于下标 1 是满足要求的最小下标，输出为 1 。
#
#
#
# 示例 3：
#
#
# 输入：nums = [1,2,3]
#
# 输出：-1
#
# 解释：
#
#
# 由于不存在满足要求的下标，输出为 -1 。
#
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 100
# 0 <= nums[i] <= 1000
#
#
#

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:

    def smallestIndex(self, nums: List[int]) -> int:

        def digit_sum(n: int):
            s = 0
            while n:
                s += n % 10
                n //= 10
            return s

        for i, v in enumerate(nums):
            if digit_sum(v) == i: return i
        return -1


# @lc code=end

#
# @lcpr case=start
# [1,3,2]\n
# @lcpr case=end

# @lcpr case=start
# [1,10,11]\n
# @lcpr case=end

# @lcpr case=start
# [1,2,3]\n
# @lcpr case=end

#
