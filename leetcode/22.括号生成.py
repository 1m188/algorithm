#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#
# https://leetcode-cn.com/problems/generate-parentheses/description/
#
# algorithms
# Medium (77.37%)
# Likes:    2497
# Dislikes: 0
# Total Accepted:    464.6K
# Total Submissions: 600.5K
# Testcase Example:  '3'
#
# 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
#
#
#
# 示例 1：
#
#
# 输入：n = 3
# 输出：["((()))","(()())","(())()","()(())","()()()"]
#
#
# 示例 2：
#
#
# 输入：n = 1
# 输出：["()"]
#
#
#
#
# 提示：
#
#
# 1 <= n <= 8
#
#
#

from typing import List


# @lc code=start
class Solution:

    def generateParenthesis(self, n: int) -> List[str]:

        res = []

        self.dfs(n, n, res, '')

        return res

    def dfs(self, left: int, right: int, res: List[str], s: str):

        if left <= 0:
            for _ in range(right):
                s += ')'
            res.append(s)
            return

        self.dfs(left - 1, right, res, s + '(')
        if right - 1 >= left:
            self.dfs(left, right - 1, res, s + ')')


# @lc code=end
