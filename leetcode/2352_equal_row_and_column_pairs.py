#
# @lc app=leetcode.cn id=2352 lang=python3
# @lcpr version=30204
#
# [2352] 相等行列对
#
# https://leetcode.cn/problems/equal-row-and-column-pairs/description/
#
# algorithms
# Medium (73.37%)
# Likes:    104
# Dislikes: 0
# Total Accepted:    58.4K
# Total Submissions: 79.6K
# Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
#
# 给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。
#
# 如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。
#
#
#
# 示例 1：
#
#
#
# 输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
# 输出：1
# 解释：存在一对相等行列对：
# - (第 2 行，第 1 列)：[2,7,7]
#
#
# 示例 2：
#
#
#
# 输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
# 输出：3
# 解释：存在三对相等行列对：
# - (第 0 行，第 0 列)：[3,1,2,2]
# - (第 2 行, 第 2 列)：[2,4,2,2]
# - (第 3 行, 第 2 列)：[2,4,2,2]
#
#
#
#
# 提示：
#
#
# n == grid.length == grid[i].length
# 1 <= n <= 200
# 1 <= grid[i][j] <= 10^5
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:

        n = len(grid)
        ans = 0

        hash_r, hash_c = [], []
        for i in range(n):
            hash_r.append(tuple(grid[i]).__hash__())
            hash_c.append(tuple(grid[j][i] for j in range(n)).__hash__())
        hash_r.sort()
        hash_c.sort()

        for i in range(n):
            for j in range(n):
                if hash_r[i] == hash_c[j]:
                    ans += 1
                elif hash_r[i] < hash_c[j]:
                    break
        return ans


# @lc code=end


#
# @lcpr case=start
# [[3,2,1],[1,7,6],[2,7,7]]\n
# @lcpr case=end

# @lcpr case=start
# [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]\n
# @lcpr case=end

#
