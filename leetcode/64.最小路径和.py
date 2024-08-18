#
# @lc app=leetcode.cn id=64 lang=python3
#
# [64] 最小路径和
#
# https://leetcode-cn.com/problems/minimum-path-sum/description/
#
# algorithms
# Medium (69.13%)
# Likes:    1224
# Dislikes: 0
# Total Accepted:    353.1K
# Total Submissions: 510.6K
# Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
#
# 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
#
# 说明：每次只能向下或者向右移动一步。
#
#
#
# 示例 1：
#
#
# 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
# 输出：7
# 解释：因为路径 1→3→1→1→1 的总和最小。
#
#
# 示例 2：
#
#
# 输入：grid = [[1,2,3],[4,5,6]]
# 输出：12
#
#
#
#
# 提示：
#
#
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 200
# 0 <= grid[i][j] <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:
    '''
    动态规划

    假设dp[i][j]为从(i,j)这个地方到右下角的最小路径和

    则有递推公式

    dp[i][j] = grid[i][j] + min(dp[i][j + 1], dp[i + 1][j])

    即为当前路径消耗加上从当前到右下角最小的路径消耗

    注意题目说的只能往右边或者下面走动
    '''

    def minPathSum(self, grid: List[List[int]]) -> int:

        m = len(grid)
        n = len(grid[0])

        dp = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                if i == m - 1 and j == n - 1:
                    dp[i][j] = grid[i][j]
                    continue

                t1 = dp[i][j + 1] if j + 1 < n else 40000
                t2 = dp[i + 1][j] if i + 1 < m else 40000

                dp[i][j] = grid[i][j] + min(t1, t2)

        return dp[0][0]


# @lc code=end
