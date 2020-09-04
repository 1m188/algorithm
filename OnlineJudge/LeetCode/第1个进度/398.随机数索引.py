#
# @lc app=leetcode.cn id=398 lang=python3
#
# [398] 随机数索引
#
# https://leetcode-cn.com/problems/random-pick-index/description/
#
# algorithms
# Medium (62.18%)
# Likes:    73
# Dislikes: 0
# Total Accepted:    7K
# Total Submissions: 11.2K
# Testcase Example:  '["Solution","pick"]\n[[[1,2,3,3,3]],[3]]'
#
# 给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。
#
# 注意：
# 数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。
#
# 示例:
#
#
# int[] nums = new int[] {1,2,3,3,3};
# Solution solution = new Solution(nums);
#
# // pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
# solution.pick(3);
#
# // pick(1) 应该返回 0。因为只有nums[0]等于1。
# solution.pick(1);
#
#
#

from typing import List
from random import randint


# @lc code=start
class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums

    def pick(self, target: int) -> int:
        n = self.nums.count(target)
        if n == 1:
            return self.nums.index(target)
        else:
            idn = randint(1, n)
            for i in range(len(self.nums)):
                if self.nums[i] == target:
                    idn -= 1
                    if not idn:
                        return i


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
# @lc code=end
