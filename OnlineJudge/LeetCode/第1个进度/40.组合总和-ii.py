#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#
# https://leetcode-cn.com/problems/combination-sum-ii/description/
#
# algorithms
# Medium (62.46%)
# Likes:    334
# Dislikes: 0
# Total Accepted:    76K
# Total Submissions: 121.6K
# Testcase Example:  '[10,1,2,7,6,1,5]\n8'
#
# 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
#
# candidates 中的每个数字在每个组合中只能使用一次。
#
# 说明：
#
#
# 所有数字（包括目标数）都是正整数。
# 解集不能包含重复的组合。
#
#
# 示例 1:
#
# 输入: candidates = [10,1,2,7,6,1,5], target = 8,
# 所求解集为:
# [
# ⁠ [1, 7],
# ⁠ [1, 2, 5],
# ⁠ [2, 6],
# ⁠ [1, 1, 6]
# ]
#
#
# 示例 2:
#
# 输入: candidates = [2,5,2,1,2], target = 5,
# 所求解集为:
# [
# [1,2,2],
# [5]
# ]
#
#

from typing import List


# @lc code=start
class Solution:
    def combinationSum2(self, candidates: List[int],
                        target: int) -> List[List[int]]:
        res = set()
        candidates.sort()

        def dfs(li=[], num=0, idx=0):
            if num == target:
                res.add(tuple(li))
            elif num < target:
                for i in range(idx, len(candidates)):
                    li.append(candidates[i])
                    dfs(li, num + candidates[i], i + 1)
                    li.pop()

        dfs()
        return [list(i) for i in res]


# @lc code=end
