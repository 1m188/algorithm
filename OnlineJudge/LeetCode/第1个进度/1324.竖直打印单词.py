#
# @lc app=leetcode.cn id=1324 lang=python3
#
# [1324] 竖直打印单词
#
# https://leetcode-cn.com/problems/print-words-vertically/description/
#
# algorithms
# Medium (57.11%)
# Likes:    23
# Dislikes: 0
# Total Accepted:    3.7K
# Total Submissions: 6.4K
# Testcase Example:  '"HOW ARE YOU"'
#
# 给你一个字符串 s。请你按照单词在 s 中的出现顺序将它们全部竖直返回。
# 单词应该以字符串列表的形式返回，必要时用空格补位，但输出尾部的空格需要删除（不允许尾随空格）。
# 每个单词只能放在一列上，每一列中也只能有一个单词。
#
#
#
# 示例 1：
#
# 输入：s = "HOW ARE YOU"
# 输出：["HAY","ORO","WEU"]
# 解释：每个单词都应该竖直打印。
# ⁠"HAY"
# "ORO"
# "WEU"
#
#
# 示例 2：
#
# 输入：s = "TO BE OR NOT TO BE"
# 输出：["TBONTB","OEROOE","   T"]
# 解释：题目允许使用空格补位，但不允许输出末尾出现空格。
# "TBONTB"
# "OEROOE"
# "   T"
#
#
# 示例 3：
#
# 输入：s = "CONTEST IS COMING"
# 输出：["CIC","OSO","N M","T I","E N","S G","T"]
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 200
# s 仅含大写英文字母。
# 题目数据保证两个单词之间只有一个空格。
#
#
#

from typing import List


# @lc code=start
class Solution:
    def printVertically(self, s: str) -> List[str]:
        sl = s.split(' ')
        maxlen = max((len(i) for i in sl))
        res = []

        for i in range(maxlen):
            wl = []
            for w in sl:
                wl.append(w[i] if i < len(w) else ' ')
            while wl[-1] == ' ':
                wl.pop()
            res.append(''.join(wl))

        return res


# @lc code=end
