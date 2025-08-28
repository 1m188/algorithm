#
# @lc app=leetcode.cn id=3446 lang=python3
# @lcpr version=30204
#
# [3446] 按对角线进行矩阵排序
#
# https://leetcode.cn/problems/sort-matrix-by-diagonals/description/
#
# algorithms
# Medium (79.29%)
# Likes:    18
# Dislikes: 0
# Total Accepted:    9.5K
# Total Submissions: 11.1K
# Testcase Example:  '[[1,7,3],[9,8,2],[4,5,6]]'
#
# 给你一个大小为 n x n 的整数方阵 grid。返回一个经过如下调整的矩阵：
#
#
# 左下角三角形（包括中间对角线）的对角线按 非递增顺序 排序。
# 右上角三角形 的对角线按 非递减顺序 排序。
#
#
#
#
# 示例 1：
#
#
# 输入： grid = [[1,7,3],[9,8,2],[4,5,6]]
#
# 输出： [[8,2,3],[9,6,7],[4,5,1]]
#
# 解释：
#
#
#
# 标有黑色箭头的对角线（左下角三角形）应按非递增顺序排序：
#
#
# [1, 8, 6] 变为 [8, 6, 1]。
# [9, 5] 和 [4] 保持不变。
#
#
# 标有蓝色箭头的对角线（右上角三角形）应按非递减顺序排序：
#
#
# [7, 2] 变为 [2, 7]。
# [3] 保持不变。
#
#
#
# 示例 2：
#
#
# 输入： grid = [[0,1],[1,2]]
#
# 输出： [[2,1],[1,0]]
#
# 解释：
#
#
#
# 标有黑色箭头的对角线必须按非递增顺序排序，因此 [0, 2] 变为 [2, 0]。其他对角线已经符合要求。
#
#
# 示例 3：
#
#
# 输入： grid = [[1]]
#
# 输出： [[1]]
#
# 解释：
#
# 只有一个元素的对角线已经符合要求，因此无需修改。
#
#
#
#
# 提示：
#
#
# grid.length == grid[i].length == n
# 1 <= n <= 10
# -10^5 <= grid[i][j] <= 10^5
#
#
#

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:

    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:

        n = len(grid)

        for i in range(n):
            ii, jj = i, 0
            li = []
            while ii < n and jj < n:
                li.append(grid[ii][jj])
                ii += 1
                jj += 1
            li.sort(reverse=True)

            ii, jj = i, 0
            for v in li:
                grid[ii][jj] = v
                ii += 1
                jj += 1

        for j in range(1, n):
            ii, jj = 0, j
            li = []
            while ii < n and jj < n:
                li.append(grid[ii][jj])
                ii += 1
                jj += 1
            li.sort()

            ii, jj = 0, j
            for v in li:
                grid[ii][jj] = v
                ii += 1
                jj += 1

        return grid


# @lc code=end

#
# @lcpr case=start
# [[1,7,3],[9,8,2],[4,5,6]]\n
# @lcpr case=end

# @lcpr case=start
# [[0,1],[1,2]]\n
# @lcpr case=end

# @lcpr case=start
# [[1]]\n
# @lcpr case=end

#
