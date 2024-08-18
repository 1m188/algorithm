#
# @lc app=leetcode.cn id=695 lang=python3
#
# [695] 岛屿的最大面积
#
# https://leetcode-cn.com/problems/max-area-of-island/description/
#
# algorithms
# Medium (63.82%)
# Likes:    362
# Dislikes: 0
# Total Accepted:    62.7K
# Total Submissions: 98.2K
# Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
#
# 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
#
# 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
# 0（代表水）包围着。
#
# 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
#
#
#
# 示例 1:
#
# [[0,0,1,0,0,0,0,1,0,0,0,0,0],
# ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
# ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
# ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
# ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
# ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
# ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
# ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
#
#
# 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
#
# 示例 2:
#
# [[0,0,0,0,0,0,0,0]]
#
# 对于上面这个给定的矩阵, 返回 0。
#
#
#
# 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
#
#

from typing import List


# @lc code=start
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        if not grid:
            return 0

        m, n = len(grid), len(grid[0])
        res = 0

        def bfs(pos):
            x, y = pos
            fl = [[False] * n for _ in range(m)]
            fl[x][y] = True
            que = [pos]
            ils = 1

            while que:
                x, y = que.pop(0)
                for i, j in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                    if i >= 0 and i < m and j >= 0 and j < n \
                       and grid[i][j] and not fl[i][j]:
                        grid[i][j] = 0
                        que.append((i, j))
                        fl[i][j] = True
                        ils += 1

            nonlocal res
            res = max(res, ils)

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    bfs((i, j))
        return res


# @lc code=end
