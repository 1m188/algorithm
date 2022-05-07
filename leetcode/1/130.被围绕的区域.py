#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#
# https://leetcode-cn.com/problems/surrounded-regions/description/
#
# algorithms
# Medium (42.12%)
# Likes:    353
# Dislikes: 0
# Total Accepted:    67.5K
# Total Submissions: 160.1K
# Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],
# ["X","O","X","X"]]'
#
# 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
#
# 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
#
# 示例:
#
# X X X X
# X O O X
# X X O X
# X O X X
#
#
# 运行你的函数后，矩阵变为：
#
# X X X X
# X X X X
# X X X X
# X O X X
#
#
# 解释:
#
# 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
# 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
#
#

from typing import List


# @lc code=start
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return

        m, n = len(board), len(board[0])

        def jud(pos):
            x, y = pos
            return x == m - 1 or x == 0 or y == n - 1 or y == 0

        def bfs(pos):
            if jud(pos):
                return

            x, y = pos
            li = [pos]
            que = [pos]
            fl = [[False] * n for _ in range(m)]
            fl[x][y] = True

            while que:
                x, y = que.pop(0)
                for i, j in ((x + 1, y), (x - 1, y), (x, y + 1), (x, y - 1)):
                    if i >= 0 and i < m and j >= 0 and j < n \
                       and not fl[i][j] and board[i][j] == 'O':
                        if jud((i, j)):
                            return
                        li.append((i, j))
                        que.append((i, j))
                        fl[i][j] = True

            for i, j in li:
                board[i][j] = 'X'

        for i in range(m):
            for j in range(n):
                if (board[i][j] == 'O'):
                    bfs((i, j))


# @lc code=end
