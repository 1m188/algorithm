#
# @lc app=leetcode.cn id=547 lang=python3
#
# [547] 省份数量
#
# https://leetcode-cn.com/problems/number-of-provinces/description/
#
# algorithms
# Medium (62.02%)
# Likes:    772
# Dislikes: 0
# Total Accepted:    206K
# Total Submissions: 332.1K
# Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
#
#
#
# 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c
# 间接相连。
#
# 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
#
# 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而
# isConnected[i][j] = 0 表示二者不直接相连。
#
# 返回矩阵中 省份 的数量。
#
#
#
# 示例 1：
#
#
# 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
# 输出：2
#
#
# 示例 2：
#
#
# 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
# 输出：3
#
#
#
#
# 提示：
#
#
# 1 <= n <= 200
# n == isConnected.length
# n == isConnected[i].length
# isConnected[i][j] 为 1 或 0
# isConnected[i][i] == 1
# isConnected[i][j] == isConnected[j][i]
#
#
#
#
#

from typing import List


# @lc code=start
class Solution:

    def findCircleNum(self, isConnected: List[List[int]]) -> int:

        n = len(isConnected)

        self.flags = [[False for _ in range(n)] for _ in range(n)]
        self.con = isConnected

        res = 0
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] and not self.flags[i][j]:
                    res += 1
                    self.dfs(i, j)

        return res

    def dfs(self, x: int, y: int):

        self.flags[x][y] = True

        for i in range(len(self.con)):
            if self.con[y][i] and not self.flags[y][i]:
                self.dfs(y, i)


# @lc code=end
