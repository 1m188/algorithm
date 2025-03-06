#
# @lc app=leetcode.cn id=3427 lang=python3
# @lcpr version=30204
#
# [3427] 变长子数组求和
#
# https://leetcode.cn/problems/sum-of-variable-length-subarrays/description/
#
# algorithms
# Easy (91.92%)
# Likes:    6
# Dislikes: 0
# Total Accepted:    4.7K
# Total Submissions: 5.1K
# Testcase Example:  '[2,3,1]'
#
# 给你一个长度为 n 的整数数组 nums 。对于 每个 下标 i（0 <= i < n），定义对应的子数组 nums[start ... i]（start
# = max(0, i - nums[i])）。
#
# 返回为数组中每个下标定义的子数组中所有元素的总和。
# 子数组 是数组中的一个连续、非空 的元素序列。
#
#
#
# 示例 1：
#
#
# 输入：nums = [2,3,1]
#
# 输出：11
#
# 解释：
#
#
#
#
# 下标 i
# 子数组
# 和
#
#
# 0
# nums[0] = [2]
# 2
#
#
# 1
# nums[0 ... 1] = [2, 3]
# 5
#
#
# 2
# nums[1 ... 2] = [3, 1]
# 4
#
#
# 总和
#
# 11
#
#
#
#
# 总和为 11 。因此，输出 11 。
#
#
# 示例 2：
#
#
# 输入：nums = [3,1,1,2]
#
# 输出：13
#
# 解释：
#
#
#
#
# 下标 i
# 子数组
# 和
#
#
# 0
# nums[0] = [3]
# 3
#
#
# 1
# nums[0 ... 1] = [3, 1]
# 4
#
#
# 2
# nums[1 ... 2] = [1, 1]
# 2
#
#
# 3
# nums[1 ... 3] = [1, 1, 2]
# 4
#
#
# 总和
#
# 13
#
#
#
#
# 总和为 13 。因此，输出为 13 。
#
#
#
#
# 提示：
#
#
# 1 <= n == nums.length <= 100
# 1 <= nums[i] <= 1000
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def subarraySum(self, nums: List[int]) -> int:
        res = [0 for _ in range(len(nums))]
        starts = [max(0, i - nums[i]) for i in range(len(nums))]
        for i in range(len(nums)):
            res[i] = sum(nums[starts[i]:i + 1])
        return sum(res)


# @lc code=end

#
# @lcpr case=start
# [2,3,1]\n
# @lcpr case=end

# @lcpr case=start
# [3,1,1,2]\n
# @lcpr case=end

#
