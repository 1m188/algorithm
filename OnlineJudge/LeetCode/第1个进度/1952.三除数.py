#
# @lc app=leetcode.cn id=1952 lang=python3
#
# [1952] 三除数
#
# https://leetcode-cn.com/problems/three-divisors/description/
#
# algorithms
# Easy (54.44%)
# Likes:    15
# Dislikes: 0
# Total Accepted:    9.2K
# Total Submissions: 16.8K
# Testcase Example:  '2'
#
# 给你一个整数 n 。如果 n 恰好有三个正除数 ，返回 true ；否则，返回 false 。
#
# 如果存在整数 k ，满足 n = k * m ，那么整数 m 就是 n 的一个 除数 。
#
#
#
# 示例 1：
#
# 输入：n = 2
# 输出：false
# 解释：2 只有两个除数：1 和 2 。
#
# 示例 2：
#
# 输入：n = 4
# 输出：true
# 解释：4 有三个除数：1、2 和 4 。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 10^4
#
#
#


# @lc code=start
class Solution:

    def isThree(self, n: int) -> bool:

        num = 0
        for i in range(1, int(n**0.5) + 1):
            k = n // i
            if i * k == n:
                num += 2 if i != k else 1
        return num == 3


# @lc code=end
