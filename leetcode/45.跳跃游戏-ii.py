#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#
# https://leetcode-cn.com/problems/jump-game-ii/description/
#
# algorithms
# Medium (44.21%)
# Likes:    1513
# Dislikes: 0
# Total Accepted:    297.8K
# Total Submissions: 673.5K
# Testcase Example:  '[2,3,1,1,4]'
#
# 给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
#
# 数组中的每个元素代表你在该位置可以跳跃的最大长度。
#
# 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
#
# 假设你总是可以到达数组的最后一个位置。
#
#
#
# 示例 1:
#
#
# 输入: nums = [2,3,1,1,4]
# 输出: 2
# 解释: 跳到最后一个位置的最小跳跃数是 2。
# 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
#
#
# 示例 2:
#
#
# 输入: nums = [2,3,0,1,4]
# 输出: 2
#
#
#
#
# 提示:
#
#
# 1 <= nums.length <= 10^4
# 0 <= nums[i] <= 1000
#
#
#

from typing import List


# @lc code=start
class Solution:

    def jump(self, nums: List[int]) -> int:

        res = 0

        i = len(nums) - 1
        while i > 0:
            j = i
            for k in range(i - 1, -1, -1):
                if nums[k] >= i - k:
                    j = k
            i = j
            res += 1

        return res


# @lc code=end
