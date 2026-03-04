#
# @lc app=leetcode.cn id=1582 lang=python3
# @lcpr version=30204
#
# [1582] 二进制矩阵中的特殊位置
#
# https://leetcode.cn/problems/special-positions-in-a-binary-matrix/description/
#
# algorithms
# Easy (69.32%)
# Likes:    112
# Dislikes: 0
# Total Accepted:    47.6K
# Total Submissions: 68.3K
# Testcase Example:  '[[1,0,0],[0,0,1],[1,0,0]]'
#
# 给定一个 m x n 的二进制矩阵 mat，返回矩阵 mat 中特殊位置的数量。
#
# 如果位置 (i, j) 满足 mat[i][j] == 1 并且行 i 与列 j 中的所有其他元素都是 0（行和列的下标从 0 开始计数），那么它被称为
# 特殊 位置。
#
#
#
# 示例 1：
#
# 输入：mat = [[1,0,0],[0,0,1],[1,0,0]]
# 输出：1
# 解释：位置 (1, 2) 是一个特殊位置，因为 mat[1][2] == 1 且第 1 行和第 2 列的其他所有元素都是 0。
#
#
# 示例 2：
#
# 输入：mat = [[1,0,0],[0,1,0],[0,0,1]]
# 输出：3
# 解释：位置 (0, 0)，(1, 1) 和 (2, 2) 都是特殊位置。
#
#
#
#
# 提示：
#
#
# m == mat.length
# n == mat[i].length
# 1 <= m, n <= 100
# mat[i][j] 是 0 或 1。
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        ans = 0
        for i in range(m):
            for j in range(n):
                if (
                    mat[i][j] == 1
                    and sum(mat[i]) == 1
                    and sum(mat[k][j] for k in range(m)) == 1
                ):
                    ans += 1
        return ans


# @lc code=end


#
# @lcpr case=start
# [[1,0,0],[0,0,1],[1,0,0]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,0,0],[0,1,0],[0,0,1]]\n
# @lcpr case=end

#
