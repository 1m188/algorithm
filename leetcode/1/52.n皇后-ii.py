#
# @lc app=leetcode.cn id=52 lang=python3
#
# [52] N皇后 II
#
# https://leetcode-cn.com/problems/n-queens-ii/description/
#
# algorithms
# Hard (82.27%)
# Likes:    345
# Dislikes: 0
# Total Accepted:    87.6K
# Total Submissions: 106.4K
# Testcase Example:  '4'
#
# n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
#
# 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
#
#
#
#
#
# 示例 1：
#
#
# 输入：n = 4
# 输出：2
# 解释：如上图所示，4 皇后问题存在两个不同的解法。
#
#
# 示例 2：
#
#
# 输入：n = 1
# 输出：1
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


# @lc code=start
class Solution:

    def totalNQueens(self, n: int) -> int:

        self.res = 0
        self.n = n
        self.ch = [[False for _ in range(n)] for _ in range(n)]

        self.dfs()
        return self.res

    def dfs(self, ni: int = 0):

        if ni >= self.n:
            self.res += 1
            return

        for i in range(self.n):
            if not self.ch[ni][i] and self.judge(ni, i):
                self.ch[ni][i] = True
                self.dfs(ni + 1)
                self.ch[ni][i] = False

    def judge(self, x: int, y: int) -> bool:

        for i in range(x):
            if self.ch[i][y]:
                return False

        i, j = x - 1, y - 1
        while i >= 0 and j >= 0:
            if self.ch[i][j]:
                return False
            i -= 1
            j -= 1

        i, j = x - 1, y + 1
        while i >= 0 and j < self.n:
            if self.ch[i][j]:
                return False
            i -= 1
            j += 1

        return True


# @lc code=end
