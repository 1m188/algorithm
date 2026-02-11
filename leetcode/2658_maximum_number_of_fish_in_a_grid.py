#
# @lc app=leetcode.cn id=2658 lang=python3
# @lcpr version=30204
#
# [2658] 网格图中鱼的最大数目
#
# https://leetcode.cn/problems/maximum-number-of-fish-in-a-grid/description/
#
# algorithms
# Medium (70.47%)
# Likes:    32
# Dislikes: 0
# Total Accepted:    12.7K
# Total Submissions: 17.9K
# Testcase Example:  '[[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]'
#
# 给你一个下标从 0 开始大小为 m x n 的二维整数数组 grid ，其中下标在 (r, c) 处的整数表示：
#
#
# 如果 grid[r][c] = 0 ，那么它是一块 陆地 。
# 如果 grid[r][c] > 0 ，那么它是一块 水域 ，且包含 grid[r][c] 条鱼。
#
#
# 一位渔夫可以从任意 水域 格子 (r, c) 出发，然后执行以下操作任意次：
#
#
# 捕捞格子 (r, c) 处所有的鱼，或者
# 移动到相邻的 水域 格子。
#
#
# 请你返回渔夫最优策略下， 最多 可以捕捞多少条鱼。如果没有水域格子，请你返回 0 。
#
# 格子 (r, c) 相邻 的格子为 (r, c + 1) ，(r, c - 1) ，(r + 1, c) 和 (r - 1, c)
# ，前提是相邻格子在网格图内。
#
#
#
# 示例 1：
#
#
#
# 输入：grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
# 输出：7
# 解释：渔夫可以从格子 (1,3) 出发，捕捞 3 条鱼，然后移动到格子 (2,3) ，捕捞 4 条鱼。
#
#
# 示例 2：
#
#
#
# 输入：grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
# 输出：1
# 解释：渔夫可以从格子 (0,0) 或者 (3,3) ，捕捞 1 条鱼。
#
#
#
#
# 提示：
#
#
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 10
# 0 <= grid[i][j] <= 10
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        flags = [[False for _ in range(n)] for _ in range(m)]

        def bfs(r: int, c: int) -> int:
            nonlocal flags
            queue = [[r, c]]
            flags[r][c] = True
            cnt = 0
            while queue:
                r, c = queue.pop(0)
                cnt += grid[r][c]
                for nr, nc in [[r - 1, c], [r + 1, c], [r, c - 1], [r, c + 1]]:
                    if (
                        0 <= nr < m
                        and 0 <= nc < n
                        and grid[nr][nc] > 0
                        and not flags[nr][nc]
                    ):
                        flags[nr][nc] = True
                        queue.append([nr, nc])
            return cnt

        ans = 0
        for r in range(m):
            for c in range(n):
                if grid[r][c] > 0 and not flags[r][c]:
                    ans = max(ans, bfs(r, c))
        return ans


# @lc code=end


#
# @lcpr case=start
# [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]\n
# @lcpr case=end

#
