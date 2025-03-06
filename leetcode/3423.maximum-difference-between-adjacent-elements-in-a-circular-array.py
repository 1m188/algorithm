#
# @lc app=leetcode.cn id=3423 lang=python3
# @lcpr version=30204
#
# [3423] 循环数组中相邻元素的最大差值
#
# https://leetcode.cn/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/
#
# algorithms
# Easy (84.55%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    2.3K
# Total Submissions: 2.8K
# Testcase Example:  '[1,2,4]'
#
# 给你一个 循环 数组 nums ，请你找出相邻元素之间的 最大 绝对差值。
#
# 注意：一个循环数组中，第一个元素和最后一个元素是相邻的。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,4]
#
# 输出：3
#
# 解释：
#
# 由于 nums 是循环的，nums[0] 和 nums[2] 是相邻的，它们之间的绝对差值是最大值 |4 - 1| = 3 。
#
#
# 示例 2：
#
#
# 输入：nums = [-5,-10,-5]
#
# 输出：5
#
# 解释：
#
# 相邻元素 nums[0] 和 nums[1] 之间的绝对差值为最大值 |-5 - (-10)| = 5 。
#
#
#
#
# 提示：
#
#
# 2 <= nums.length <= 100
# -100 <= nums[i] <= 100
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def maxAdjacentDistance(self, nums: List[int]) -> int:
        res = -1
        for i in range(len(nums) - 1):
            res = max(res, abs(nums[i] - nums[i + 1]))
        res = max(res, abs(nums[0] - nums[-1]))
        return res


# @lc code=end

#
# @lcpr case=start
# [1,2,4]\n
# @lcpr case=end

# @lcpr case=start
# [-5,-10,-5]\n
# @lcpr case=end

#
