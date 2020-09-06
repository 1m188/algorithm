#
# @lc app=leetcode.cn id=1254 lang=python3
#
# [1254] 统计封闭岛屿的数目
#
# https://leetcode-cn.com/problems/number-of-closed-islands/description/
#
# algorithms
# Medium (58.14%)
# Likes:    50
# Dislikes: 0
# Total Accepted:    8K
# Total Submissions: 13.8K
# Testcase Example:  '[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],
# [1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]'
#
# 有一个二维矩阵 grid ，每个位置要么是陆地（记号为 0 ）要么是水域（记号为 1 ）。
#
# 我们从一块陆地出发，每次可以往上下左右 4 个方向相邻区域走，能走到的所有陆地区域，我们将其称为一座「岛屿」。
#
# 如果一座岛屿 完全 由水域包围，即陆地边缘上下左右所有相邻区域都是水域，那么我们将其称为 「封闭岛屿」。
#
# 请返回封闭岛屿的数目。
#
#
#
# 示例 1：
#
#
#
# 输入：grid =
# [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
# 输出：2
# 解释：
# 灰色区域的岛屿是封闭岛屿，因为这座岛屿完全被水域包围（即被 1 区域包围）。
#
# 示例 2：
#
#
#
# 输入：grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
# 输出：1
#
#
# 示例 3：
#
# 输入：grid = [[1,1,1,1,1,1,1],
# [1,0,0,0,0,0,1],
# [1,0,1,1,1,0,1],
# [1,0,1,0,1,0,1],
# [1,0,1,1,1,0,1],
# [1,0,0,0,0,0,1],
# ⁠            [1,1,1,1,1,1,1]]
# 输出：2
#
#
#
#
# 提示：
#
#
# 1 <= grid.length, grid[0].length <= 100
# 0 <= grid[i][j] <=1
#
#
#

from typing import List


# @lc code=start
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        res = 0
        m, n = len(grid), len(grid[0])
        fl = [[False] * n for _ in range(m)]

        def bfs(pos: (int, int)):
            x, y = pos
            fl[x][y] = True
            bl = [pos]

            f = False
            while bl:
                x, y = bl.pop(0)
                for i, j in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                    if not f \
                       and (i == 0 or i == m - 1 or j == 0 or j == n - 1) \
                       and not grid[i][j]:
                        f = True
                    if i > 0 and i < m - 1 and j > 0 and j < n - 1 \
                       and not grid[i][j] and not fl[i][j]:
                        fl[i][j] = True
                        bl.append((i, j))

            if not f:
                nonlocal res
                res += 1

        for i in range(1, m - 1):
            for j in range(1, n - 1):
                if not grid[i][j] and not fl[i][j]:
                    bfs((i, j))
        return res


# @lc code=end
