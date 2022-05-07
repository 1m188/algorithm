#
# @lc app=leetcode.cn id=1929 lang=python3
#
# [1929] 数组串联
#
# https://leetcode-cn.com/problems/concatenation-of-array/description/
#
# algorithms
# Easy (87.42%)
# Likes:    25
# Dislikes: 0
# Total Accepted:    24.7K
# Total Submissions: 28.2K
# Testcase Example:  '[1,2,1]'
#
# 给你一个长度为 n 的整数数组 nums 。请你构建一个长度为 2n 的答案数组 ans ，数组下标 从 0 开始计数 ，对于所有 0  的 i
# ，满足下述所有要求：
#
#
# ans[i] == nums[i]
# ans[i + n] == nums[i]
#
#
# 具体而言，ans 由两个 nums 数组 串联 形成。
#
# 返回数组 ans 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,1]
# 输出：[1,2,1,1,2,1]
# 解释：数组 ans 按下述方式形成：
# - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
# - ans = [1,2,1,1,2,1]
#
# 示例 2：
#
#
# 输入：nums = [1,3,2,1]
# 输出：[1,3,2,1,1,3,2,1]
# 解释：数组 ans 按下述方式形成：
# - ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
# - ans = [1,3,2,1,1,3,2,1]
#
#
#
#
# 提示：
#
#
# n == nums.length
# 1 <= n <= 1000
# 1 <= nums[i] <= 1000
#
#
#

from typing import List


# @lc code=start
class Solution:

    def getConcatenation(self, nums: List[int]) -> List[int]:
        return nums + nums


# @lc code=end
