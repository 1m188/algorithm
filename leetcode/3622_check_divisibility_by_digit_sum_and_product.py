#
# @lc app=leetcode.cn id=3622 lang=python3
# @lcpr version=30204
#
# [3622] 判断整除性
#
# https://leetcode.cn/problems/check-divisibility-by-digit-sum-and-product/description/
#
# algorithms
# Easy (65.68%)
# Likes:    0
# Dislikes: 0
# Total Accepted:    4.1K
# Total Submissions: 6.2K
# Testcase Example:  '99'
#
# 给你一个正整数 n。请判断 n 是否可以被以下两值之和 整除：
#
#
#
# n 的 数字和（即其各个位数之和）。
#
#
# n 的 数字积（即其各个位数之积）。
#
#
#
# 如果 n 能被该和整除，返回 true；否则，返回 false。
#
#
#
# 示例 1：
#
#
# 输入： n = 99
#
# 输出： true
#
# 解释：
#
# 因为 99 可以被其数字和 (9 + 9 = 18) 与数字积 (9 * 9 = 81) 之和 (18 + 81 = 99) 整除，因此输出为
# true。
#
#
# 示例 2：
#
#
# 输入： n = 23
#
# 输出： false
#
# 解释：
#
# 因为 23 无法被其数字和 (2 + 3 = 5) 与数字积 (2 * 3 = 6) 之和 (5 + 6 = 11) 整除，因此输出为
# false。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 10^6
#
#
#


# @lcpr-template-start


# @lcpr-template-end
# @lc code=start
class Solution:
    def checkDivisibility(self, n: int) -> bool:

        def get_sum(n: int) -> int:
            res = 0
            while n:
                res += n % 10
                n //= 10
            return res

        def get_product(n: int) -> int:
            res = 1
            while n:
                res *= n % 10
                n //= 10
            return res

        return n % (get_sum(n) + get_product(n)) == 0


# @lc code=end


#
# @lcpr case=start
# 99\n
# @lcpr case=end

# @lcpr case=start
# 23\n
# @lcpr case=end

#
