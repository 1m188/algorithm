#
# @lc app=leetcode.cn id=3417 lang=python3
# @lcpr version=30204
#
# [3417] 跳过交替单元格的之字形遍历
#
# https://leetcode.cn/problems/zigzag-grid-traversal-with-skip/description/
#
# algorithms
# Easy (76.79%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    3.5K
# Total Submissions: 4.5K
# Testcase Example:  '[[1,2],[3,4]]'
#
# 给你一个 m x n 的二维数组 grid，数组由 正整数 组成。
#
# 你的任务是以 之字形 遍历 grid，同时跳过每个 交替 的单元格。
#
# 之字形遍历的定义如下：
#
#
# 从左上角的单元格 (0, 0) 开始。
# 在当前行中向 右 移动，直到到达该行的末尾。
# 下移到下一行，然后在该行中向 左 移动，直到到达该行的开头。
# 继续在行间交替向右和向左移动，直到所有行都被遍历完。
#
#
# 注意：在遍历过程中，必须跳过每个 交替 的单元格。
#
# 返回一个整数数组 result，其中包含按 顺序 记录的、且跳过交替单元格后的之字形遍历中访问到的单元格值。
#
#
#
# 示例 1：
#
#
# 输入： grid = [[1,2],[3,4]]
#
# 输出： [1,4]
#
# 解释：
#
#
#
#
# 示例 2：
#
#
# 输入： grid = [[2,1],[2,1],[2,1]]
#
# 输出： [2,1,2]
#
# 解释：
#
#
#
#
# 示例 3：
#
#
# 输入： grid = [[1,2,3],[4,5,6],[7,8,9]]
#
# 输出： [1,3,5,7,9]
#
# 解释：
#
#
#
#
#
#
# 提示：
#
#
# 2 <= n == grid.length <= 50
# 2 <= m == grid[i].length <= 50
# 1 <= grid[i][j] <= 2500
#
#
#

from typing import List

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def zigzagTraversal(self, grid: List[List[int]]) -> List[int]:
        n, m = len(grid), len(grid[0])
        res = []
        i, j = 0, 0
        f = True
        dx = 1
        while i < n and j < m:
            if f: res.append(grid[i][j])
            f = not f
            j += dx
            if j < 0 or j >= m:
                i += 1
                j -= dx
                dx = -dx
        return res


# @lc code=end

#
# @lcpr case=start
# [[1,2],[3,4]]\n
# @lcpr case=end

# @lcpr case=start
# [[2,1],[2,1],[2,1]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,2,3],[4,5,6],[7,8,9]]\n
# @lcpr case=end

#
