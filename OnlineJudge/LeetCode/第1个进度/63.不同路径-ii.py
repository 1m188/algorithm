#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
# https://leetcode-cn.com/problems/unique-paths-ii/description/
#
# algorithms
# Medium (40.04%)
# Likes:    777
# Dislikes: 0
# Total Accepted:    247.3K
# Total Submissions: 617.3K
# Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
#
# 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
#
# 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。
#
# 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
#
# 网格中的障碍物和空位置分别用 1 和 0 来表示。
#
#
#
# 示例 1：
#
#
# 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
# 输出：2
# 解释：3x3 网格的正中间有一个障碍物。
# 从左上角到右下角一共有 2 条不同的路径：
# 1. 向右 -> 向右 -> 向下 -> 向下
# 2. 向下 -> 向下 -> 向右 -> 向右
#
#
# 示例 2：
#
#
# 输入：obstacleGrid = [[0,1],[0,0]]
# 输出：1
#
#
#
#
# 提示：
#
#
# m == obstacleGrid.length
# n == obstacleGrid[i].length
# 1 <= m, n <= 100
# obstacleGrid[i][j] 为 0 或 1
#
#
#

from typing import List


# @lc code=start
class Solution:
    '''
    动态规划

    假设二维数组dp[i][j]为从平面上(i,j)处到右下角的路径数目
    则有递推公式

    dp[i][j] = dp[i][j + 1] + dp[i + 1][j]

    表示当前位置到右下角的路径数目为右边格子的路径数目加上
    下面格子的路径数目（因为题目提示只能够向下或向右走）

    至于右下角则只有一条路径可以走，就是原地不动

    如果碰到了障碍物，需要知道障碍物是无法到右下角的，所以障碍物的
    路径数目为0

    特殊的 如果起始地点或者目的地有障碍物 则可以直接返回0 因为
    永远也到不了目的地
    '''

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

        ob = obstacleGrid
        m = len(ob)
        n = len(ob[0])

        if ob[0][0] or ob[m - 1][n - 1]:
            return 0

        dp = [[0 for _ in range(n)] for _ in range(m)]

        # 这里在计算dp数组的时候，因为是从右往左，从下往上
        # 所以每次计算到的内容其右边和下面的内容都一定会
        # 提前计算好

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):

                if i == m - 1 and j == n - 1:
                    dp[i][j] = 1
                    continue

                # 计算右边和下面一格的路径数目
                t1 = dp[i][j + 1] if j + 1 < n and not ob[i][j + 1] else 0
                t2 = dp[i + 1][j] if i + 1 < m and not ob[i + 1][j] else 0

                dp[i][j] = t1 + t2

        return dp[0][0]


# @lc code=end
