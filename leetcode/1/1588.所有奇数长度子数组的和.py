#
# @lc app=leetcode.cn id=1588 lang=python3
#
# [1588] 所有奇数长度子数组的和
#
# https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/description/
#
# algorithms
# Easy (83.87%)
# Likes:    167
# Dislikes: 0
# Total Accepted:    49.8K
# Total Submissions: 59.4K
# Testcase Example:  '[1,4,2,5,3]'
#
# 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。
#
# 子数组 定义为原数组中的一个连续子序列。
#
# 请你返回 arr 中 所有奇数长度子数组的和 。
#
#
#
# 示例 1：
#
# 输入：arr = [1,4,2,5,3]
# 输出：58
# 解释：所有奇数长度子数组和它们的和为：
# [1] = 1
# [4] = 4
# [2] = 2
# [5] = 5
# [3] = 3
# [1,4,2] = 7
# [4,2,5] = 11
# [2,5,3] = 10
# [1,4,2,5,3] = 15
# 我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
#
# 示例 2：
#
# 输入：arr = [1,2]
# 输出：3
# 解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
#
# 示例 3：
#
# 输入：arr = [10,11,12]
# 输出：66
#
#
#
#
# 提示：
#
#
# 1 <= arr.length <= 100
# 1 <= arr[i] <= 1000
#
#
#

from typing import List


# @lc code=start
class Solution:

    def sumOddLengthSubarrays(self, arr: List[int]) -> int:

        res = 0

        for long in range(1, len(arr) + 1, 2):
            start = 0
            end = start + long
            s = sum(arr[start:end])
            res += s
            while end < len(arr):
                s -= arr[start]
                start += 1
                end += 1
                s += arr[end - 1]
                res += s

        return res


# @lc code=end
