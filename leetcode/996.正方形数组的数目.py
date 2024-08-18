#
# @lc app=leetcode.cn id=996 lang=python3
#
# [996] 正方形数组的数目
#
# https://leetcode-cn.com/problems/number-of-squareful-arrays/description/
#
# algorithms
# Hard (45.65%)
# Likes:    37
# Dislikes: 0
# Total Accepted:    2.4K
# Total Submissions: 5.2K
# Testcase Example:  '[1,17,8]'
#
# 给定一个非负整数数组 A，如果该数组每对相邻元素之和是一个完全平方数，则称这一数组为正方形数组。
#
# 返回 A 的正方形排列的数目。两个排列 A1 和 A2 不同的充要条件是存在某个索引 i，使得 A1[i] != A2[i]。
#
#
#
# 示例 1：
#
# 输入：[1,17,8]
# 输出：2
# 解释：
# [1,8,17] 和 [17,8,1] 都是有效的排列。
#
#
# 示例 2：
#
# 输入：[2,2,2]
# 输出：1
#
#
#
#
# 提示：
#
#
# 1 <= A.length <= 12
# 0 <= A[i] <= 1e9
#
#
#

from typing import List
from collections import Counter


# @lc code=start
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:

        # 构造一个图，然后深搜，图的节点边均为符合完全平方数的组合，
        # 节点数量用 len(A) 来控制，从每个节点开始深搜

        countera = Counter(A)
        graph = {x: [] for x in countera}
        for i in countera:
            for j in countera:
                if int((i + j)**0.5)**2 == i + j:
                    graph[i].append(j)

        res = 0

        def dfs(x, todo):
            if not todo:
                nonlocal res
                res += 1
                return

            for y in graph[x]:
                if countera[y]:
                    countera[y] -= 1
                    dfs(y, todo - 1)
                    countera[y] += 1

        for i in countera:
            countera[i] -= 1
            dfs(i, len(A) - 1)
            countera[i] += 1
        return res


# @lc code=end
