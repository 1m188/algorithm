#
# @lc app=leetcode.cn id=224 lang=python3
#
# [224] 基本计算器
#
# https://leetcode-cn.com/problems/basic-calculator/description/
#
# algorithms
# Hard (38.19%)
# Likes:    240
# Dislikes: 0
# Total Accepted:    17.7K
# Total Submissions: 46.2K
# Testcase Example:  '"1 + 1"'
#
# 实现一个基本的计算器来计算一个简单的字符串表达式的值。
#
# 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
#
# 示例 1:
#
# 输入: "1 + 1"
# 输出: 2
#
#
# 示例 2:
#
# 输入: " 2-1 + 2 "
# 输出: 3
#
# 示例 3:
#
# 输入: "(1+(4+5+2)-3)+(6+8)"
# 输出: 23
#
# 说明：
#
#
# 你可以假设所给定的表达式都是有效的。
# 请不要使用内置的库函数 eval。
#
#
#


# @lc code=start
class Solution:
    def clc(self, exp: list) -> int:
        st = []
        for e in exp:
            if type(e) == int:
                st.append(e)
            else:
                x = st.pop()
                y = st.pop()
                st.append(y + x if e == '+' else y - x)
        return st[0]

    def hs(self, s: str) -> list:
        ns = s.replace(' ', '')

        sv = []
        exp = ""
        for c in ns:
            if c.isdigit():
                exp += c
            else:
                if len(exp):
                    sv.append(int(exp))
                    exp = ""
                sv.append(c)
        if len(exp):
            sv.append(int(exp))

        return sv

    def calculate(self, s: str) -> int:
        exp, st = [], []
        for e in self.hs(s):
            if type(e) == int:
                exp.append(e)
            elif e == ')':
                while st[-1] != '(':
                    exp.append(st.pop())
                st.pop()
            elif e == '+' or e == '-':
                while len(st) and st[-1] != '(':
                    exp.append(st.pop())
                st.append(e)
            else:
                st.append(e)
        while len(st):
            exp.append(st.pop())

        return self.clc(exp)


# @lc code=end
