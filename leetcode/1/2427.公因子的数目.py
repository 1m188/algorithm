#
# @lc app=leetcode.cn id=2427 lang=python3
#
# [2427] 公因子的数目
#
# https://leetcode.cn/problems/number-of-common-factors/description/
#
# algorithms
# Easy (81.91%)
# Likes:    6
# Dislikes: 0
# Total Accepted:    8.8K
# Total Submissions: 10.8K
# Testcase Example:  '12\n6'
#
# 给你两个正整数 a 和 b ，返回 a 和 b 的 公 因子的数目。
#
# 如果 x 可以同时整除 a 和 b ，则认为 x 是 a 和 b 的一个 公因子 。
#
#
#
# 示例 1：
#
# 输入：a = 12, b = 6
# 输出：4
# 解释：12 和 6 的公因子是 1、2、3、6 。
#
#
# 示例 2：
#
# 输入：a = 25, b = 30
# 输出：2
# 解释：25 和 30 的公因子是 1、5 。
#
#
#
# 提示：
#
#
# 1 <= a, b <= 1000
#
#
#


# @lc code=start
class Solution:

    def commonFactors(self, a: int, b: int) -> int:

        x = min(a, b)
        res = 0

        for i in range(1, x + 1):
            if a % i == 0 and b % i == 0: res += 1

        return res


# @lc code=end
