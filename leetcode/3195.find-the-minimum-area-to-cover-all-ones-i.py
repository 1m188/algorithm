#
# @lc app=leetcode.cn id=3195 lang=python3
# @lcpr version=30204
#
# [3195] 包含所有 1 的最小矩形面积 I
#
# https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/description/
#
# algorithms
# Medium (81.61%)
# Likes:    6
# Dislikes: 0
# Total Accepted:    11.3K
# Total Submissions: 13.7K
# Testcase Example:  '[[0,1,0],[1,0,1]]'
#
# 给你一个二维 二进制 数组 grid。请你找出一个边在水平方向和竖直方向上、面积 最小 的矩形，并且满足 grid 中所有的 1 都在矩形的内部。
#
# 返回这个矩形可能的 最小 面积。
#
#
#
# 示例 1：
#
#
# 输入： grid = [[0,1,0],[1,0,1]]
#
# 输出： 6
#
# 解释：
#
#
#
# 这个最小矩形的高度为 2，宽度为 3，因此面积为 2 * 3 = 6。
#
#
# 示例 2：
#
#
# 输入： grid = [[0,0],[1,0]]
#
# 输出： 1
#
# 解释：
#
#
#
# 这个最小矩形的高度和宽度都是 1，因此面积为 1 * 1 = 1。
#
#
#
#
# 提示：
#
#
# 1 <= grid.length, grid[i].length <= 1000
# grid[i][j] 是 0 或 1。
# 输入保证 grid 中至少有一个 1 。
#
#
#

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:

    def minimumArea(self, grid: List[List[int]]) -> int:

        m, n = len(grid), len(grid[0])
        up, down, left, right = 0, 0, 0, 0

        for i in range(m):
            if any(grid[i]):
                up = i
                break

        for i in range(m - 1, -1, -1):
            if any(grid[i]):
                down = i
                break

        for j in range(n):
            if any(grid[i][j] for i in range(m)):
                left = j
                break

        for j in range(n - 1, -1, -1):
            if any(grid[i][j] for i in range(m)):
                right = j
                break

        return (down - up + 1) * (right - left + 1)


# @lc code=end

#
# @lcpr case=start
# [[0,1,0],[1,0,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,0],[1,0]]\n
# @lcpr case=end

#
