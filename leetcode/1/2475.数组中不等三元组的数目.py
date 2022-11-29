#
# @lc app=leetcode.cn id=2475 lang=python3
#
# [2475] 数组中不等三元组的数目
#
# https://leetcode.cn/problems/number-of-unequal-triplets-in-array/description/
#
# algorithms
# Easy (75.00%)
# Likes:    12
# Dislikes: 0
# Total Accepted:    7.4K
# Total Submissions: 9.9K
# Testcase Example:  '[4,4,2,4,3]'
#
# 给你一个下标从 0 开始的正整数数组 nums 。请你找出并统计满足下述条件的三元组 (i, j, k) 的数目：
#
#
# 0 <= i < j < k < nums.length
# nums[i]、nums[j] 和 nums[k] 两两不同 。
#
# 换句话说：nums[i] != nums[j]、nums[i] != nums[k] 且 nums[j] != nums[k] 。
#
#
#
#
# 返回满足上述条件三元组的数目。
#
#
#
# 示例 1：
#
#
# 输入：nums = [4,4,2,4,3]
# 输出：3
# 解释：下面列出的三元组均满足题目条件：
# - (0, 2, 4) 因为 4 != 2 != 3
# - (1, 2, 4) 因为 4 != 2 != 3
# - (2, 3, 4) 因为 2 != 4 != 3
# 共计 3 个三元组，返回 3 。
# 注意 (2, 0, 4) 不是有效的三元组，因为 2 > 0 。
#
#
# 示例 2：
#
#
# 输入：nums = [1,1,1,1,1]
# 输出：0
# 解释：不存在满足条件的三元组，所以返回 0 。
#
#
#
#
# 提示：
#
#
# 3 <= nums.length <= 100
# 1 <= nums[i] <= 1000
#
#
#

from typing import List


# @lc code=start
class Solution:

    def unequalTriplets(self, nums: List[int]) -> int:

        res = 0
        for i in range(len(nums) - 2):
            for j in range(i + 1, len(nums) - 1):
                for k in range(j + 1, len(nums)):
                    if nums[i] != nums[j] and nums[i] != nums[k] and\
                       nums[j] != nums[k]:
                        res += 1
        return res


# @lc code=end
