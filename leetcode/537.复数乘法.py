#
# @lc app=leetcode.cn id=537 lang=python3
#
# [537] 复数乘法
#
# https://leetcode-cn.com/problems/complex-number-multiplication/description/
#
# algorithms
# Medium (69.89%)
# Likes:    41
# Dislikes: 0
# Total Accepted:    7.3K
# Total Submissions: 10.4K
# Testcase Example:  '"1+1i"\n"1+1i"'
#
# 给定两个表示复数的字符串。
#
# 返回表示它们乘积的字符串。注意，根据定义 i^2 = -1 。
#
# 示例 1:
#
#
# 输入: "1+1i", "1+1i"
# 输出: "0+2i"
# 解释: (1 + i) * (1 + i) = 1 + i^2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
#
#
# 示例 2:
#
#
# 输入: "1+-1i", "1+-1i"
# 输出: "0+-2i"
# 解释: (1 - i) * (1 - i) = 1 + i^2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。
#
#
# 注意:
#
#
# 输入字符串不包含额外的空格。
# 输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
#
#
#


# @lc code=start
class Solution:
    def get(self, cp: str) -> (int, int):
        cp = cp.split('+')
        cp[1] = cp[1][:-1]
        return (int(cp[0]), int(cp[1]))

    def cc(self, a: str, b: str) -> str:
        '''
        调用复数类
        '''
        ap = self.get(a)
        bp = self.get(b)
        ac = complex(ap[0], ap[1])
        bc = complex(bp[0], bp[1])
        res = ac * bc
        return str(int(res.real)) + '+' + str(int(res.imag)) + 'i'

    def cl(self, a: str, b: str) -> str:
        '''
        直接计算
        '''
        ap = self.get(a)
        bp = self.get(b)
        r = ap[0] * bp[0] - ap[1] * bp[1]
        i = ap[0] * bp[1] + ap[1] * bp[0]
        return str(r) + '+' + str(i) + 'i'

    def complexNumberMultiply(self, a: str, b: str) -> str:
        # return self.cc(a, b)
        return self.cl(a, b)


# @lc code=end
