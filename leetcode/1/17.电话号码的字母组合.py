#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#
# https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
#
# algorithms
# Medium (57.72%)
# Likes:    1805
# Dislikes: 0
# Total Accepted:    446K
# Total Submissions: 772.6K
# Testcase Example:  '"23"'
#
# 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
#
# 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
#
#
#
#
#
# 示例 1：
#
#
# 输入：digits = "23"
# 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
#
#
# 示例 2：
#
#
# 输入：digits = ""
# 输出：[]
#
#
# 示例 3：
#
#
# 输入：digits = "2"
# 输出：["a","b","c"]
#
#
#
#
# 提示：
#
#
# 0 <= digits.length <= 4
# digits[i] 是范围 ['2', '9'] 的一个数字。
#
#
#

from typing import List


# @lc code=start
class Solution:

    def letterCombinations(self, digits: str) -> List[str]:

        if not digits:
            return []

        res = []

        self.dfs(digits, 0, res, '')

        return res

    def dfs(self, di: str, idi: int, res: List[str], s: str):

        if idi >= len(di):
            res.append(s)
            return

        if di[idi] == '2':
            ds = 'abc'
        elif di[idi] == '3':
            ds = 'def'
        elif di[idi] == '4':
            ds = 'ghi'
        elif di[idi] == '5':
            ds = 'jkl'
        elif di[idi] == '6':
            ds = 'mno'
        elif di[idi] == '7':
            ds = 'pqrs'
        elif di[idi] == '8':
            ds = 'tuv'
        else:
            ds = 'wxyz'

        for i in ds:
            self.dfs(di, idi + 1, res, s + i)


# @lc code=end
