#
# @lc app=leetcode.cn id=1854 lang=python3
#
# [1854] 人口最多的年份
#
# https://leetcode-cn.com/problems/maximum-population-year/description/
#
# algorithms
# Easy (76.10%)
# Likes:    41
# Dislikes: 0
# Total Accepted:    13.9K
# Total Submissions: 18.2K
# Testcase Example:  '[[1993,1999],[2000,2010]]'
#
# 给你一个二维整数数组 logs ，其中每个 logs[i] = [birthi, deathi] 表示第 i 个人的出生和死亡年份。
#
# 年份 x 的 人口 定义为这一年期间活着的人的数目。第 i 个人被计入年份 x 的人口需要满足：x 在闭区间 [birthi, deathi - 1]
# 内。注意，人不应当计入他们死亡当年的人口中。
#
# 返回 人口最多 且 最早 的年份。
#
#
#
# 示例 1：
#
# 输入：logs = [[1993,1999],[2000,2010]]
# 输出：1993
# 解释：人口最多为 1 ，而 1993 是人口为 1 的最早年份。
#
#
# 示例 2：
#
# 输入：logs = [[1950,1961],[1960,1971],[1970,1981]]
# 输出：1960
# 解释：
# 人口最多为 2 ，分别出现在 1960 和 1970 。
# 其中最早年份是 1960 。
#
#
#
# 提示：
#
#
# 1 <= logs.length <= 100
# 1950 <= birthi < deathi <= 2050
#
#
#

from typing import List


# @lc code=start
class Solution:

    def maximumPopulation(self, logs: List[List[int]]) -> int:

        li = [0 for _ in range(100)]

        for start, end in logs:
            for i in range(start, end):
                li[i - 1950] += 1

        t = 0
        for i in range(100):
            if li[i] > li[t]:
                t = i

        return 1950 + t


# @lc code=end
