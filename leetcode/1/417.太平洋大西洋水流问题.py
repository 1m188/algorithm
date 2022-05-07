#
# @lc app=leetcode.cn id=417 lang=python3
#
# [417] 太平洋大西洋水流问题
#
# https://leetcode-cn.com/problems/pacific-atlantic-water-flow/description/
#
# algorithms
# Medium (42.48%)
# Likes:    134
# Dislikes: 0
# Total Accepted:    10.6K
# Total Submissions: 25K
# Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],
# [5,1,1,2,4]]'
#
# 给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。
#
# 规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。
#
# 请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。
#
#
#
# 提示：
#
#
# 输出坐标的顺序不重要
# m 和 n 都小于150
#
#
#
#
# 示例：
#
#
#
#
# 给定下面的 5x5 矩阵:
#
# ⁠ 太平洋 ~   ~   ~   ~   ~
# ⁠      ~  1   2   2   3  (5) *
# ⁠      ~  3   2   3  (4) (4) *
# ⁠      ~  2   4  (5)  3   1  *
# ⁠      ~ (6) (7)  1   4   5  *
# ⁠      ~ (5)  1   1   2   4  *
# ⁠         *   *   *   *   * 大西洋
#
# 返回:
#
# [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).
#
#
#
#
#

from typing import List


# @lc code=start
class Solution:
    def pacificAtlantic(self, matrix: List[List[int]]) -> List[List[int]]:
        if not matrix:
            return []

        m, n = len(matrix), len(matrix[0])
        res = []

        def bfs(pos):
            x, y = pos

            f1, f2 = False, False
            fl = [[False] * n for _ in range(m)]
            fl[x][y] = True
            que = [pos]

            while que:
                x, y = que.pop(0)

                for i, j in ((x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)):

                    # 判定是否到太平洋或大西洋
                    if i >= 0 and i < m and j >= 0 and j < n:

                        # 判定是否可流
                        if not fl[i][j] and matrix[x][y] >= matrix[i][j]:
                            que.append([i, j])
                            fl[i][j] = True

                    elif i < 0 or j < 0:
                        f1 = True
                    elif i >= m or j >= n:
                        f2 = True

            if f1 and f2:
                res.append(pos)

        for i in range(m):
            for j in range(n):
                bfs([i, j])
        return res


# @lc code=end
