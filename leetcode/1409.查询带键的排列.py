#
# @lc app=leetcode.cn id=1409 lang=python3
#
# [1409] 查询带键的排列
#
# https://leetcode-cn.com/problems/queries-on-a-permutation-with-key/description/
#
# algorithms
# Medium (79.99%)
# Likes:    13
# Dislikes: 0
# Total Accepted:    5.4K
# Total Submissions: 6.7K
# Testcase Example:  '[3,1,2,1]\n5'
#
# 给你一个待查数组 queries ，数组中的元素为 1 到 m 之间的正整数。 请你根据以下规则处理所有待查项 queries[i]（从 i=0 到
# i=queries.length-1）：
#
#
# 一开始，排列 P=[1,2,3,...,m]。
# 对于当前的 i ，请你找出待查项 queries[i] 在排列 P 中的位置（下标从 0 开始），然后将其从原位置移动到排列 P 的起始位置（即下标为 0
# 处）。注意， queries[i] 在 P 中的位置就是 queries[i] 的查询结果。
#
#
# 请你以数组形式返回待查数组  queries 的查询结果。
#
#
#
# 示例 1：
#
# 输入：queries = [3,1,2,1], m = 5
# 输出：[2,1,2,1]
# 解释：待查数组 queries 处理如下：
# 对于 i=0: queries[i]=3, P=[1,2,3,4,5], 3 在 P 中的位置是 2，接着我们把 3 移动到 P 的起始位置，得到
# P=[3,1,2,4,5] 。
# 对于 i=1: queries[i]=1, P=[3,1,2,4,5], 1 在 P 中的位置是 1，接着我们把 1 移动到 P 的起始位置，得到
# P=[1,3,2,4,5] 。
# 对于 i=2: queries[i]=2, P=[1,3,2,4,5], 2 在 P 中的位置是 2，接着我们把 2 移动到 P 的起始位置，得到
# P=[2,1,3,4,5] 。
# 对于 i=3: queries[i]=1, P=[2,1,3,4,5], 1 在 P 中的位置是 1，接着我们把 1 移动到 P 的起始位置，得到
# P=[1,2,3,4,5] 。
# 因此，返回的结果数组为 [2,1,2,1] 。
#
#
# 示例 2：
#
# 输入：queries = [4,1,2,2], m = 4
# 输出：[3,1,2,0]
#
#
# 示例 3：
#
# 输入：queries = [7,5,5,8,3], m = 8
# 输出：[6,5,0,7,5]
#
#
#
#
# 提示：
#
#
# 1 <= m <= 10^3
# 1 <= queries.length <= m
# 1 <= queries[i] <= m
#
#
#

from typing import List


# @lc code=start
class Solution:
    def processQueries(self, queries: List[int], m: int) -> List[int]:
        pl = [i for i in range(1, m + 1)]
        res = []
        for i in queries:
            pi = pl.index(i)
            res.append(pi)
            pl.insert(0, pl.pop(pi))
        return res


# @lc code=end
