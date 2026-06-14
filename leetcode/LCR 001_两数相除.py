#
# @lc app=leetcode.cn id=LCR 001 lang=python3
# @lcpr version=30204
#
# [LCR 001] 两数相除
#
# https://leetcode.cn/problems/xoh6Oh/description/
#
# algorithms
# Easy (21.30%)
# Likes:    307
# Dislikes: 0
# Total Accepted:    74.5K
# Total Submissions: 350K
# Testcase Example:  '15\n2'
#
# 给定两个整数 a 和 b ，求它们的除法的商 a/b ，要求不得使用乘号 '*'、除号 '/' 以及求余符号 '%' 。
#
#
#
# 注意：
#
#
# 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
# -2
# 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31, 2^31−1]。本题中，如果除法结果溢出，则返回 2^31 − 1
#
#
#
#
# 示例 1：
#
# 输入：a = 15, b = 2
# 输出：7
# 解释：15/2 = truncate(7.5) = 7
#
#
# 示例 2：
#
# 输入：a = 7, b = -3
# 输出：-2
# 解释：7/-3 = truncate(-2.33333..) = -2
#
# 示例 3：
#
# 输入：a = 0, b = 1
# 输出：0
#
# 示例 4：
#
# 输入：a = 1, b = 1
# 输出：1
#
#
#
# 提示:
#
#
# -2^31 <= a, b <= 2^31 - 1
# b != 0
#
#
#
#
# 注意：本题与主站 29 题相同：https://leetcode.cn/problems/divide-two-integers/
#
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def divide(self, a: int, b: int) -> int:
        # 处理溢出情况: INT_MIN / -1 结果会超过 INT_MAX
        if a == -(2**31) and b == -1:
            return 2**31 - 1

        # 确定结果的符号（同号为正，异号为负）
        sign = 1
        if (a > 0) != (b > 0):
            sign = -1

        # 取绝对值进行计算
        dividend = abs(a)
        divisor = abs(b)

        result = 0
        # 在被除数大于等于除数时，每次减去尽可能大的 divisor 的倍数
        while dividend >= divisor:
            temp = divisor
            multiple = 1
            # 通过左移找到最大的 temp = divisor * 2^k，使得 temp <= dividend
            while dividend >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            dividend -= temp
            result += multiple

        return sign * result


# @lc code=end


#
# @lcpr case=start
# 15\n2\n
# @lcpr case=end

# @lcpr case=start
# 7\n-3\n
# @lcpr case=end

# @lcpr case=start
# 0\n1\n
# @lcpr case=end

# @lcpr case=start
# 1\n1\n
# @lcpr case=end

#
