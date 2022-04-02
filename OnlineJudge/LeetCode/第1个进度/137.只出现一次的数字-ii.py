#
# @lc app=leetcode.cn id=137 lang=python3
#
# [137] 只出现一次的数字 II
#
# https://leetcode-cn.com/problems/single-number-ii/description/
#
# algorithms
# Medium (72.06%)
# Likes:    836
# Dislikes: 0
# Total Accepted:    117.9K
# Total Submissions: 163.5K
# Testcase Example:  '[2,2,3,2]'
#
# 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
#
#
#
# 示例 1：
#
#
# 输入：nums = [2,2,3,2]
# 输出：3
#
#
# 示例 2：
#
#
# 输入：nums = [0,1,0,1,0,1,99]
# 输出：99
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 3 * 10^4
# -2^31 <= nums[i] <= 2^31 - 1
# nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
#
#
#
#
# 进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
#
#

from typing import List


# @lc code=start
class Solution:

    def singleNumber(self, nums: List[int]) -> int:

        s1, s2 = set(), set()

        for i in nums:
            if i in s1 and i in s2:
                s1.remove(i)
                s2.remove(i)
            elif i in s1:
                s2.add(i)
            elif i in s2:
                s1.add(i)
            else:
                s1.add(i)

        return s1.pop() if s1 else s2.pop()


# @lc code=end
