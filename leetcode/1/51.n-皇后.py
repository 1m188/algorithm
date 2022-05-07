#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#
# https://leetcode-cn.com/problems/n-queens/description/
#
# algorithms
# Hard (73.85%)
# Likes:    1248
# Dislikes: 0
# Total Accepted:    197.9K
# Total Submissions: 267.8K
# Testcase Example:  '4'
#
# n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
#
# 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
#
#
#
# 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
#
#
#
# 示例 1：
#
#
# 输入：n = 4
# 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
# 解释：如上图所示，4 皇后问题存在两个不同的解法。
#
#
# 示例 2：
#
#
# 输入：n = 1
# 输出：[["Q"]]
#
#
#
#
# 提示：
#
#
# 1 <= n <= 9
#
#
#
#
#

from typing import List


# @lc code=start
class Solution:

    def solveNQueens(self, n: int) -> List[List[str]]:

        self.res = []
        li = [['.' for _ in range(n)] for _ in range(n)]
        self.dfs(li, n, 0)
        return self.res

    def dfs(self, li: List[List[str]], n: int, ni: int):

        if ni >= n:
            self.res.append([''.join(i) for i in li])
            return

        for i in range(n):
            if li[ni][i] == '.' and self.judge(li, ni, i):
                li[ni][i] = 'Q'
                self.dfs(li, n, ni + 1)
                li[ni][i] = '.'

    def judge(self, li: List[List[str]], x: int, y: int) -> bool:

        n = len(li)

        for i in range(x):
            if li[i][y] == 'Q':
                return False

        i, j = x - 1, y - 1
        while i >= 0 and j >= 0:
            if li[i][j] == 'Q':
                return False
            i -= 1
            j -= 1

        i, j = x - 1, y + 1
        while i >= 0 and j < n:
            if li[i][j] == 'Q':
                return False
            i -= 1
            j += 1

        return True


# @lc code=end
