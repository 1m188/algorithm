#
# @lc app=leetcode.cn id=384 lang=python3
#
# [384] 打乱数组
#
# https://leetcode-cn.com/problems/shuffle-an-array/description/
#
# algorithms
# Medium (53.02%)
# Likes:    92
# Dislikes: 0
# Total Accepted:    25.6K
# Total Submissions: 47.9K
# Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
#
# 打乱一个没有重复元素的数组。
#
#
#
# 示例:
#
# // 以数字集合 1, 2 和 3 初始化数组。
# int[] nums = {1,2,3};
# Solution solution = new Solution(nums);
#
# // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
# solution.shuffle();
#
# // 重设数组到它的初始状态[1,2,3]。
# solution.reset();
#
# // 随机返回数组[1,2,3]打乱后的结果。
# solution.shuffle();
#
#
#

from typing import List
from copy import deepcopy
from random import randint


# @lc code=start
class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.curvec = deepcopy(self.nums)

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        self.curvec = deepcopy(self.nums)
        return self.curvec

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        res = []
        while self.curvec:
            idx = randint(0, len(self.curvec) - 1)
            res.append(self.curvec.pop(idx))
        self.curvec = res
        return self.curvec


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
# @lc code=end
