#
# @lc app=leetcode.cn id=1556 lang=python3
#
# [1556] 千位分隔数
#
# https://leetcode-cn.com/problems/thousand-separator/description/
#
# algorithms
# Easy (56.99%)
# Likes:    19
# Dislikes: 0
# Total Accepted:    13.2K
# Total Submissions: 23.2K
# Testcase Example:  '987'
#
# 给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。
#
#
#
# 示例 1：
#
# 输入：n = 987
# 输出："987"
#
#
# 示例 2：
#
# 输入：n = 1234
# 输出："1.234"
#
#
# 示例 3：
#
# 输入：n = 123456789
# 输出："123.456.789"
#
#
# 示例 4：
#
# 输入：n = 0
# 输出："0"
#
#
#
#
# 提示：
#
#
# 0 <= n < 2^31
#
#
#


# @lc code=start
class Solution:

    def thousandSeparator(self, n: int) -> str:

        li = list(str(n))
        if len(li) <= 3:
            return str(n)

        tl = []
        while len(li) >= 3:
            tl.append(''.join(li[-3:]))
            for _ in range(3):
                li.pop()
        if li:
            tl.append(''.join(li))
        tl.reverse()

        return '.'.join(tl)


# @lc code=end
