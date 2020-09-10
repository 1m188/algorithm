#
# @lc app=leetcode.cn id=200 lang=python3
#
# [200] 岛屿数量
#
# https://leetcode-cn.com/problems/number-of-islands/description/
#
# algorithms
# Medium (50.00%)
# Likes:    710
# Dislikes: 0
# Total Accepted:    143.3K
# Total Submissions: 286.3K
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],
# ["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
#
# 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
#
# 此外，你可以假设该网格的四条边均被水包围。
#
#
#
# 示例 1:
#
# 输入:
# [
# ['1','1','1','1','0'],
# ['1','1','0','1','0'],
# ['1','1','0','0','0'],
# ['0','0','0','0','0']
# ]
# 输出: 1
#
#
# 示例 2:
#
# 输入:
# [
# ['1','1','0','0','0'],
# ['1','1','0','0','0'],
# ['0','0','1','0','0'],
# ['0','0','0','1','1']
# ]
# 输出: 3
# 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
#
#
#

from typing import List


# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        m, n = len(grid), len(grid[0])
        fl = [[False] * n for _ in range(m)]
        res = 0

        def bfs(pos):
            x, y = pos
            fl[x][y] = True
            nonlocal res
            res += 1

            que = [pos]
            while que:
                x, y = que.pop(0)
                for i, j in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                    if i >= 0 and i < m and j >= 0 and j < n \
                       and grid[i][j] == '1' and not fl[i][j]:
                        fl[i][j] = True
                        que.append((i, j))

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not fl[i][j]:
                    bfs((i, j))
        return res


# @lc code=end
