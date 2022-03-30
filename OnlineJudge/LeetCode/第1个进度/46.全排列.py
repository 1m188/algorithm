#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#
# https://leetcode-cn.com/problems/permutations/description/
#
# algorithms
# Medium (78.50%)
# Likes:    1886
# Dislikes: 0
# Total Accepted:    564.2K
# Total Submissions: 718.8K
# Testcase Example:  '[1,2,3]'
#
# 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,2,3]
# 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#
#
# 示例 2：
#
#
# 输入：nums = [0,1]
# 输出：[[0,1],[1,0]]
#
#
# 示例 3：
#
#
# 输入：nums = [1]
# 输出：[[1]]
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 6
# -10 <= nums[i] <= 10
# nums 中的所有整数 互不相同
#
#
#

from typing import List


# @lc code=start
class Solution:

    def permute(self, nums: List[int]) -> List[List[int]]:

        self.n = len(nums)
        self.nums = nums
        self.res = []
        self.fl = [False for _ in range(self.n)]

        self.dfs([])

        return self.res

    def dfs(self, li: List[int]):

        f = True
        for i in range(self.n):
            if not self.fl[i]:
                f = False
                li.append(self.nums[i])
                self.fl[i] = True
                self.dfs(li)
                self.fl[i] = False
                li.pop()
        if f:
            self.res.append(li.copy())


# @lc code=end
