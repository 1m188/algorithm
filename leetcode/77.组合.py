#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#
# https://leetcode-cn.com/problems/combinations/description/
#
# algorithms
# Medium (77.00%)
# Likes:    922
# Dislikes: 0
# Total Accepted:    313.5K
# Total Submissions: 407.1K
# Testcase Example:  '4\n2'
#
# 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
#
# 你可以按 任何顺序 返回答案。
#
#
#
# 示例 1：
#
#
# 输入：n = 4, k = 2
# 输出：
# [
# ⁠ [2,4],
# ⁠ [3,4],
# ⁠ [2,3],
# ⁠ [1,2],
# ⁠ [1,3],
# ⁠ [1,4],
# ]
#
# 示例 2：
#
#
# 输入：n = 1, k = 1
# 输出：[[1]]
#
#
#
# 提示：
#
#
# 1 <= n <= 20
# 1 <= k <= n
#
#
#

from typing import List


# @lc code=start
class Solution:

    def combine(self, n: int, k: int) -> List[List[int]]:

        self.k = k
        self.res = []
        self.fl = [False for _ in range(n)]

        self.dfs([], 0, 0)

        return self.res

    def dfs(self, li: List[int], num: int, idx: int):

        if num >= self.k:
            self.res.append(li.copy())
            return

        for i in range(idx, len(self.fl)):
            if not self.fl[i]:
                self.fl[i] = True
                li.append(i + 1)
                self.dfs(li, num + 1, i + 1)
                li.pop()
                self.fl[i] = False


# @lc code=end
