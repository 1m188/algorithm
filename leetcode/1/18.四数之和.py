#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#
# https://leetcode-cn.com/problems/4sum/description/
#
# algorithms
# Medium (39.31%)
# Likes:    1235
# Dislikes: 0
# Total Accepted:    313.1K
# Total Submissions: 796.7K
# Testcase Example:  '[1,0,-1,0,-2,2]\n0'
#
# 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
# nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
#
#
# 0 <= a, b, c, d < n
# a、b、c 和 d 互不相同
# nums[a] + nums[b] + nums[c] + nums[d] == target
#
#
# 你可以按 任意顺序 返回答案 。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,0,-1,0,-2,2], target = 0
# 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
#
#
# 示例 2：
#
#
# 输入：nums = [2,2,2,2,2], target = 8
# 输出：[[2,2,2,2]]
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 200
# -10^9 <= nums[i] <= 10^9
# -10^9 <= target <= 10^9
#
#
#

'''
类似三数之和=0的做法，只不过0变成了target，同时数目也增加到了4个，
首先固定一个最开始的数，之后target-该数变成new target，之后就是
三数之和的模板，至于重复内容也是一样的判断方法
'''

from typing import List


# @lc code=start
class Solution:

    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        if len(nums) < 4: return []

        nums.sort()
        res = []

        for a in range(len(nums)):

            if a != 0 and nums[a] == nums[a - 1]: continue

            ntgt = target - nums[a]

            for i in range(a + 1, len(nums)):

                if i != a + 1 and nums[i] == nums[i - 1]: continue

                left, right = i + 1, len(nums) - 1

                while left < right:

                    x = nums[i] + nums[left] + nums[right]

                    if x == ntgt:
                        res.append([nums[a], nums[i], nums[left], nums[right]])
                        left += 1
                        right -= 1
                        while left < right and nums[left] == nums[
                                left - 1] and nums[right] == nums[right + 1]:
                            left += 1
                            right -= 1
                    elif x > ntgt:
                        right -= 1
                    else:
                        left += 1

        return res


# @lc code=end
