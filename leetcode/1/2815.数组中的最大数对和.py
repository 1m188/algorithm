#
# @lc app=leetcode.cn id=2815 lang=python3
#
# [2815] 数组中的最大数对和
#
# https://leetcode.cn/problems/max-pair-sum-in-an-array/description/
#
# algorithms
# Easy (68.50%)
# Likes:    9
# Dislikes: 0
# Total Accepted:    7.1K
# Total Submissions: 10.4K
# Testcase Example:  '[51,71,17,24,42]'
#
# 给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。
#
# 返回最大和，如果不存在满足题意的数字对，返回 -1 。
#
#
#
# 示例 1：
#
# 输入：nums = [51,71,17,24,42]
# 输出：88
# 解释：
# i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。
# i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
# 可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
#
# 示例 2：
#
# 输入：nums = [1,2,3,4]
# 输出：-1
# 解释：不存在数对满足数位上最大的数字相等。
#
#
#
#
# 提示：
#
#
# 2 <= nums.length <= 100
# 1 <= nums[i] <= 10^4
#
#
#

from typing import List


# @lc code=start
class Solution:

    def maxSum(self, nums: List[int]) -> int:

        def get_maxi(num):
            li = []
            while num:
                li.append(num % 10)
                num = int(num / 10)
            return max(li)

        res = -1
        nums.sort(reverse=True)
        for i in range(len(nums)):
            maxi = get_maxi(nums[i])
            for j in range(i + 1, len(nums)):
                if maxi != get_maxi(nums[j]): continue
                else: res = max(res, nums[i] + nums[j])
        return res


# @lc code=end
