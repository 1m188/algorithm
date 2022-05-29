#
# @lc app=leetcode.cn id=120 lang=python3
#
# [120] 三角形最小路径和
#
# https://leetcode.cn/problems/triangle/description/
#
# algorithms
# Medium (68.59%)
# Likes:    1041
# Dislikes: 0
# Total Accepted:    236.2K
# Total Submissions: 344.4K
# Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
#
# 给定一个三角形 triangle ，找出自顶向下的最小路径和。
#
# 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1
# 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
#
#
#
# 示例 1：
#
#
# 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
# 输出：11
# 解释：如下面简图所示：
# ⁠  2
# ⁠ 3 4
# ⁠6 5 7
# 4 1 8 3
# 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
#
#
# 示例 2：
#
#
# 输入：triangle = [[-10]]
# 输出：-10
#
#
#
#
# 提示：
#
#
# 1 <= triangle.length <= 200
# triangle[0].length == 1
# triangle[i].length == triangle[i - 1].length + 1
# -10^4 <= triangle[i][j] <= 10^4
#
#
#
#
# 进阶：
#
#
# 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
#
#
#
'''
动态规划

对于triangle，考虑同样尺寸的dp，
对于dp[i][j]，其代表以该点为终点的路径的最小值，
即 dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1])

注意i-1时候的j索引和j-1索引可能不存在的情况，此时应该就只是另一个
'''

from typing import List


# @lc code=start
class Solution:

    def minimumTotal(self, triangle: List[List[int]]) -> int:

        dp = [[0 for _ in range(len(i))] for i in triangle]

        dp[0][0] = triangle[0][0]

        for i in range(1, len(dp)):
            for j in range(len(dp[i])):

                if j - 1 >= 0:
                    x = dp[i - 1][j - 1]
                else:
                    x = float("inf")

                if j < len(dp[i - 1]):
                    y = dp[i - 1][j]
                else:
                    y = float("inf")

                dp[i][j] = min(x, y) + triangle[i][j]

        return min(dp[-1])


# @lc code=end
