#
# @lc app=leetcode.cn id=1447 lang=python3
#
# [1447] 最简分数
#
# https://leetcode-cn.com/problems/simplified-fractions/description/
#
# algorithms
# Medium (60.82%)
# Likes:    7
# Dislikes: 0
# Total Accepted:    3.7K
# Total Submissions: 6.1K
# Testcase Example:  '2'
#
# 给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。
#
#
#
# 示例 1：
#
# 输入：n = 2
# 输出：["1/2"]
# 解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
#
# 示例 2：
#
# 输入：n = 3
# 输出：["1/2","1/3","2/3"]
#
#
# 示例 3：
#
# 输入：n = 4
# 输出：["1/2","1/3","1/4","2/3","3/4"]
# 解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
#
# 示例 4：
#
# 输入：n = 1
# 输出：[]
#
#
#
#
# 提示：
#
#
# 1 <= n <= 100
#
#
#

from typing import List


# @lc code=start
class Solution:
    def simplifiedFractions(self, n: int) -> List[str]:
        def gcd(x, y):
            return x if not y else gcd(y, x % y)

        def simple(x, y):
            n = gcd(x, y)
            return str(x // n) + '/' + str(y // n)

        res = set()
        for i in range(1, n + 1):
            for j in range(1, i):
                res.add(simple(j, i))
        return list(res)


# @lc code=end
