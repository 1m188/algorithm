#
# @lc app=leetcode.cn id=2928 lang=python3
#
# [2928] 给小朋友们分糖果 I
#
# https://leetcode.cn/problems/distribute-candies-among-children-i/description/
#
# algorithms
# Easy (74.42%)
# Likes:    2
# Dislikes: 0
# Total Accepted:    3.1K
# Total Submissions: 4.2K
# Testcase Example:  '5\n2'
#
# 给你两个正整数 n 和 limit 。
#
# 请你将 n 颗糖果分给 3 位小朋友，确保没有任何小朋友得到超过 limit 颗糖果，请你返回满足此条件下的 总方案数 。
#
#
#
# 示例 1：
#
#
# 输入：n = 5, limit = 2
# 输出：3
# 解释：总共有 3 种方法分配 5 颗糖果，且每位小朋友的糖果数不超过 2 ：(1, 2, 2) ，(2, 1, 2) 和 (2, 2, 1) 。
#
#
# 示例 2：
#
#
# 输入：n = 3, limit = 3
# 输出：10
# 解释：总共有 10 种方法分配 3 颗糖果，且每位小朋友的糖果数不超过 3 ：(0, 0, 3) ，(0, 1, 2) ，(0, 2, 1) ，(0,
# 3, 0) ，(1, 0, 2) ，(1, 1, 1) ，(1, 2, 0) ，(2, 0, 1) ，(2, 1, 0) 和 (3, 0, 0)
# 。
#
#
#
#
# 提示：
#
#
# 1 <= n <= 50
# 1 <= limit <= 50
#
#
#

from typing import List


# @lc code=start
class Solution:

    def distributeCandies(self, n: int, limit: int) -> int:

        res = 0
        for i in range(limit + 1):
            if i > n: continue
            for j in range(limit + 1):
                if j > n or i + j > n: continue
                k = n - i - j
                if not 0 <= k <= limit: continue
                res += 1
        return res


# @lc code=end
