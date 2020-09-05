#
# @lc app=leetcode.cn id=1219 lang=python3
#
# [1219] 黄金矿工
#
# https://leetcode-cn.com/problems/path-with-maximum-gold/description/
#
# algorithms
# Medium (61.19%)
# Likes:    51
# Dislikes: 0
# Total Accepted:    6.9K
# Total Submissions: 11.3K
# Testcase Example:  '[[0,6,0],[5,8,7],[0,9,0]]'
#
# 你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid
# 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。
#
# 为了使收益最大化，矿工需要按以下规则来开采黄金：
#
#
# 每当矿工进入一个单元，就会收集该单元格中的所有黄金。
# 矿工每次可以从当前位置向上下左右四个方向走。
# 每个单元格只能被开采（进入）一次。
# 不得开采（进入）黄金数目为 0 的单元格。
# 矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
#
#
#
#
# 示例 1：
#
# 输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
# 输出：24
# 解释：
# [[0,6,0],
# ⁠[5,8,7],
# ⁠[0,9,0]]
# 一种收集最多黄金的路线是：9 -> 8 -> 7。
#
#
# 示例 2：
#
# 输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
# 输出：28
# 解释：
# [[1,0,7],
# ⁠[2,0,6],
# ⁠[3,4,5],
# ⁠[0,3,0],
# ⁠[9,0,20]]
# 一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
#
#
#
#
# 提示：
#
#
# 1 <= grid.length, grid[i].length <= 15
# 0 <= grid[i][j] <= 100
# 最多 25 个单元格中有黄金。
#
#
#

from typing import List


# @lc code=start
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        fl = [[False] * n for _ in range(m)]
        res = 0

        def terminal(pos: (int, int)) -> bool:
            x, y = pos
            return (not x or not grid[x - 1][y] or fl[x - 1][y]) \
                and (x == m - 1 or not grid[x + 1][y] or fl[x + 1][y]) \
                and (not y or not grid[x][y - 1] or fl[x][y - 1]) \
                and (y == n - 1 or not grid[x][y + 1] or fl[x][y + 1])

        def dfs(pos: (int, int), ac: int = 0):
            x, y = pos
            fl[x][y] = True
            ac += grid[x][y]

            if terminal(pos):
                nonlocal res
                if ac > res:
                    res = ac
            else:
                for i, j in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):
                    if i >= 0 and i < m and j >= 0 and j < n \
                       and grid[i][j] and not fl[i][j]:
                        dfs((i, j), ac)

            fl[x][y] = False
            ac -= grid[x][y]

        for i in range(m):
            for j in range(n):
                if grid[i][j]:
                    dfs((i, j))
        return res


# @lc code=end
