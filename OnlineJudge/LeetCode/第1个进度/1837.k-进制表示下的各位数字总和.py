#
# @lc app=leetcode.cn id=1837 lang=python3
#
# [1837] K 进制表示下的各位数字总和
#
# https://leetcode-cn.com/problems/sum-of-digits-in-base-k/description/
#
# algorithms
# Easy (79.80%)
# Likes:    18
# Dislikes: 0
# Total Accepted:    9.9K
# Total Submissions: 12.4K
# Testcase Example:  '34\n6'
#
# 给你一个整数 n（10 进制）和一个基数 k ，请你将 n 从 10 进制表示转换为 k 进制表示，计算并返回转换后各位数字的 总和 。
#
# 转换后，各位数字应当视作是 10 进制数字，且它们的总和也应当按 10 进制表示返回。
#
#
#
# 示例 1：
#
#
# 输入：n = 34, k = 6
# 输出：9
# 解释：34 (10 进制) 在 6 进制下表示为 54 。5 + 4 = 9 。
#
#
# 示例 2：
#
#
# 输入：n = 10, k = 10
# 输出：1
# 解释：n 本身就是 10 进制。 1 + 0 = 1 。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 100
# 2 <= k <= 10
#
#
#


# @lc code=start
class Solution:

    def sumBase(self, n: int, k: int) -> int:

        res = 0
        while n:
            res += n % k
            n = int(n / k)
        res += n

        return res


# @lc code=end
