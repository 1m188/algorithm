#
# @lc app=leetcode.cn id=2160 lang=python3
#
# [2160] 拆分数位后四位数字的最小和
#
# https://leetcode-cn.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/
#
# algorithms
# Easy (85.42%)
# Likes:    11
# Dislikes: 0
# Total Accepted:    7.3K
# Total Submissions: 8.6K
# Testcase Example:  '2932'
#
# 给你一个四位 正 整数 num 。请你使用 num 中的 数位 ，将 num 拆成两个新的整数 new1 和 new2 。new1 和 new2 中可以有
# 前导 0 ，且 num 中 所有 数位都必须使用。
#
#
# 比方说，给你 num = 2932 ，你拥有的数位包括：两个 2 ，一个 9 和一个 3 。一些可能的 [new1, new2] 数对为 [22,
# 93]，[23, 92]，[223, 9] 和 [2, 329] 。
#
#
# 请你返回可以得到的 new1 和 new2 的 最小 和。
#
#
#
# 示例 1：
#
# 输入：num = 2932
# 输出：52
# 解释：可行的 [new1, new2] 数对为 [29, 23] ，[223, 9] 等等。
# 最小和为数对 [29, 23] 的和：29 + 23 = 52 。
#
#
# 示例 2：
#
# 输入：num = 4009
# 输出：13
# 解释：可行的 [new1, new2] 数对为 [0, 49] ，[490, 0] 等等。
# 最小和为数对 [4, 9] 的和：4 + 9 = 13 。
#
#
#
#
# 提示：
#
#
# 1000 <= num <= 9999
#
#
#

# @lc code=start
from typing import List


class Solution:

    def minimumSum(self, num: int) -> int:

        nl = []
        while num:
            nl.append(num % 10)
            num //= 10

        ans = 10000

        for i in range(4):
            x = nl.pop(i)
            ans = min(ans, x + self.getmin(nl.copy()))
            nl.insert(i, x)

        for i in range(4):
            for j in range(4):
                if i != j:
                    x = [nl[i], nl[j]]
                    y = nl.copy()
                    y.remove(nl[i])
                    y.remove(nl[j])
                    ans = min(ans, self.getmin(x) + self.getmin(y))

        return ans

    def getmin(self, nl: List[int]) -> int:

        if len(nl) == 0: return 0
        if len(nl) == 1: return nl[0]

        nl.sort()
        ans = 0
        for i in nl:
            ans = ans * 10 + i
        return ans


# @lc code=end
