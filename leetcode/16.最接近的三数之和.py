#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
# https://leetcode.cn/problems/3sum-closest/description/
#
# algorithms
# Medium (45.56%)
# Likes:    1196
# Dislikes: 0
# Total Accepted:    380.7K
# Total Submissions: 835.4K
# Testcase Example:  '[-1,2,1,-4]\n1'
#
# 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。
#
# 返回这三个数的和。
#
# 假定每组输入只存在恰好一个解。
#
#
#
# 示例 1：
#
#
# 输入：nums = [-1,2,1,-4], target = 1
# 输出：2
# 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
#
#
# 示例 2：
#
#
# 输入：nums = [0,0,0], target = 1
# 输出：0
#
#
#
#
# 提示：
#
#
# 3 <= nums.length <= 1000
# -1000 <= nums[i] <= 1000
# -10^4 <= target <= 10^4
#
#
#
'''
类似于三数之和为0的那个题目，这里也是一样，排序，之后从头遍历，遇到重复的
元素则跳过，因为前面的元素从后面选择两个数有更大的空间，而后面的重复的元素
选择空间更小，无法达到比前面的距离更小的距离。对于每个和，计算和target的距离，
选择更小的，如果直接等于target了，直接返回，如果>target右边的数左移，<target
左边的数右移
'''

from typing import List


# @lc code=start
class Solution:

    def threeSumClosest(self, nums: List[int], target: int) -> int:

        nums.sort()
        dist = float("inf")  # 初始无穷大的距离
        res = 0

        for i in range(len(nums)):

            if i != 0 and nums[i] == nums[i - 1]: continue

            left, right = i + 1, len(nums) - 1

            while left < right:
                x = nums[i] + nums[left] + nums[right]

                if abs(x - target) < dist:
                    res = x
                    dist = abs(x - target)

                if x == target: return target
                elif x > target:
                    right -= 1
                else:
                    left += 1

        return res


# @lc code=end
