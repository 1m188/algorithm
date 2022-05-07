#
# @lc app=leetcode.cn id=79 lang=python3
#
# [79] 单词搜索
#
# https://leetcode-cn.com/problems/word-search/description/
#
# algorithms
# Medium (46.16%)
# Likes:    1244
# Dislikes: 0
# Total Accepted:    290.5K
# Total Submissions: 629.2K
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
#
# 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
#
#
#
# 示例 1：
#
#
# 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
# "ABCCED"
# 输出：true
#
#
# 示例 2：
#
#
# 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
# "SEE"
# 输出：true
#
#
# 示例 3：
#
#
# 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
# "ABCB"
# 输出：false
#
#
#
#
# 提示：
#
#
# m == board.length
# n = board[i].length
# 1 <= m, n <= 6
# 1 <= word.length <= 15
# board 和 word 仅由大小写英文字母组成
#
#
#
#
# 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
#
#

from typing import List, Tuple


# @lc code=start
class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:

        self.m, self.n = len(board), len(board[0])
        self.board = board
        self.word = word
        self.fl = [[False for _ in range(self.n)] for _ in range(self.m)]

        for i in range(self.m):
            for j in range(self.n):
                if self.board[i][j] == self.word[0]:
                    self.fl[i][j] = True
                    if self.dfs(0, (i, j)):
                        return True
                    self.fl[i][j] = False
        return False

    def dfs(self, wi: int, bi: Tuple[int, int]) -> bool:

        if wi >= len(self.word) - 1:
            return True

        m, n = bi

        if m - 1 >= 0 and not self.fl[m - 1][n] and self.board[m - 1][n] == self.word[wi + 1]:
            self.fl[m - 1][n] = True
            x = self.dfs(wi + 1, (m - 1, n))
            self.fl[m - 1][n] = False
            if x: return True

        if n - 1 >= 0 and not self.fl[m][n - 1] and self.board[m][n - 1] == self.word[wi + 1]:
            self.fl[m][n - 1] = True
            x = self.dfs(wi + 1, (m, n - 1))
            self.fl[m][n - 1] = False
            if x: return True

        if m + 1 < self.m and not self.fl[m + 1][n] and self.board[m + 1][n] == self.word[wi + 1]:
            self.fl[m + 1][n] = True
            x = self.dfs(wi + 1, (m + 1, n))
            self.fl[m + 1][n] = False
            if x: return True

        if n + 1 < self.n and not self.fl[m][n + 1] and self.board[m][n + 1] == self.word[wi + 1]:
            self.fl[m][n + 1] = True
            x = self.dfs(wi + 1, (m, n + 1))
            self.fl[m][n + 1] = False
            if x: return True

        return False


# @lc code=end
