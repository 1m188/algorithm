#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
# https://leetcode.cn/problems/3sum/description/
#
# algorithms
# Medium (35.87%)
# Likes:    5016
# Dislikes: 0
# Total Accepted:    1.1M
# Total Submissions: 2.9M
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
# 且不重复的三元组。
#
# 注意：答案中不可以包含重复的三元组。
#
#
#
# 示例 1：
#
#
# 输入：nums = [-1,0,1,2,-1,-4]
# 输出：[[-1,-1,2],[-1,0,1]]
#
#
# 示例 2：
#
#
# 输入：nums = []
# 输出：[]
#
#
# 示例 3：
#
#
# 输入：nums = [0]
# 输出：[]
#
#
#
#
# 提示：
#
#
# 0 <= nums.length <= 3000
# -10^5 <= nums[i] <= 10^5
#
#
#

'''
双指针变种，关键在于去重，排序之后，挨个遍历元素，碰到重复元素则跳过，
因为之前的重复的元素已经做过了，每个遍历的元素作为第一个数，之后i+1和
n-1两个位置上的数作为第二个和第三个，如果为0，则变换两个位置向中间靠拢，
如果是重复数据的话跳过这个，直到最终没有可以取的数为止了。如果<0，第二个数
往右边移动，>0对第三个数往左边移动
'''

from typing import List


# @lc code=start
class Solution:

    def threeSum(self, nums: List[int]) -> List[List[int]]:

        if len(nums) < 3: return []

        nums.sort()
        res = []

        for i in range(len(nums)):

            if nums[i] > 0: return res
            if i != 0 and nums[i] == nums[i - 1]: continue

            left, right = i + 1, len(nums) - 1

            while left < right:
                if nums[i] + nums[left] + nums[right] == 0:
                    res.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[
                            left - 1] and nums[right] == nums[right + 1]:
                        left += 1
                        right -= 1
                elif nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                else:
                    left += 1

        return res


# @lc code=end
