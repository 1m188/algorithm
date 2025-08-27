#
# @lc app=leetcode.cn id=3602 lang=python3
# @lcpr version=30204
#
# [3602] 十六进制和三十六进制转化
#
# https://leetcode.cn/problems/hexadecimal-and-hexatrigesimal-conversion/description/
#
# algorithms
# Easy (85.01%)
# Likes:    0
# Dislikes: 0
# Total Accepted:    1.9K
# Total Submissions: 2.3K
# Testcase Example:  '13'
#
# 给你一个整数 n。
#
# 返回 n^2 的 十六进制表示 和 n^3 的 三十六进制表示 拼接成的字符串。
#
# 十六进制 数定义为使用数字 0 – 9 和大写字母 A - F 表示 0 到 15 的值。
#
# 三十六进制 数定义为使用数字 0 – 9 和大写字母 A - Z 表示 0 到 35 的值。
#
#
#
# 示例 1：
#
#
# 输入：n = 13
#
# 输出： "A91P1"
#
# 解释：
#
#
# n^2 = 13 * 13 = 169。在十六进制中，它转换为 (10 * 16) + 9 = 169，对应于 "A9"。
# n^3 = 13 * 13 * 13 = 2197。在三十六进制中，它转换为 (1 * 36^2) + (25 * 36) + 1 = 2197，对应于
# "1P1"。
# 连接两个结果得到 "A9" + "1P1" = "A91P1"。
#
#
#
# 示例 2：
#
#
# 输入：n = 36
#
# 输出："5101000"
#
# 解释：
#
#
# n^2 = 36 * 36 = 1296。在十六进制中，它转换为 (5 * 16^2) + (1 * 16) + 0 = 1296，对应于
# "510"。
# n^3 = 36 * 36 * 36 = 46656。在三十六进制中，它转换为 (1 * 36^3) + (0 * 36^2) + (0 * 36) +
# 0 = 46656，对应于 "1000"。
# 连接两个结果得到 "510" + "1000" = "5101000"。
#
#
#
#
#
# 提示:
#
#
# 1 <= n <= 1000
#
#
#

# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:

    def concatHex36(self, n: int) -> str:

        def base_convert(number, from_base, to_base):
            """
            任意进制转换函数
            :param number: 要转换的数字（字符串形式）
            :param from_base: 原始进制（2-36）
            :param to_base: 目标进制（2-36）
            :return: 转换后的字符串
            """
            # 先转换为十进制
            decimal = int(number, from_base)

            # 十进制转目标进制
            if to_base == 10:
                return str(decimal)

            digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            result = []

            # 转换为目标进制
            while decimal > 0:
                decimal, rem = divmod(decimal, to_base)
                result.append(digits[rem])

            return ''.join(reversed(result))

        return hex(n**2)[2:].upper() + base_convert(str(n**3), 10, 36)


# @lc code=end

#
# @lcpr case=start
# 13\n
# @lcpr case=end

# @lcpr case=start
# 36\n
# @lcpr case=end

#
