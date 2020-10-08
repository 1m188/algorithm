#
# @lc app=leetcode.cn id=329 lang=python3
#
# [329] 矩阵中的最长递增路径
#
# https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
#
# algorithms
# Hard (46.06%)
# Likes:    309
# Dislikes: 0
# Total Accepted:    32K
# Total Submissions: 69.3K
# Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
#
# 给定一个整数矩阵，找出最长递增路径的长度。
#
# 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
#
# 示例 1:
#
# 输入: nums =
# [
# ⁠ [9,9,4],
# ⁠ [6,6,8],
# ⁠ [2,1,1]
# ]
# 输出: 4
# 解释: 最长递增路径为 [1, 2, 6, 9]。
#
# 示例 2:
#
# 输入: nums =
# [
# ⁠ [3,4,5],
# ⁠ [3,2,6],
# ⁠ [2,2,1]
# ]
# 输出: 4
# 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
#
#
#

from typing import List
from functools import lru_cache


# @lc code=start
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0

        res = 0
        m, n = len(matrix), len(matrix[0])

        @lru_cache(None)  # memoization
        def dfs(r, c):
            best = 1
            for i, j in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
                if 0 <= i < m and 0 <= j < n and matrix[i][j] > matrix[r][c]:
                    best = max(best, dfs(i, j) + 1)
            return best

        for i in range(m):
            for j in range(n):
                res = max(res, dfs(i, j))
        return res


# @lc code=end
