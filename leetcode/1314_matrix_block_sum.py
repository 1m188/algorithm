#
# @lc app=leetcode.cn id=1314 lang=python3
# @lcpr version=30204
#
# [1314] 矩阵区域和
#
# https://leetcode.cn/problems/matrix-block-sum/description/
#
# algorithms
# Medium (73.50%)
# Likes:    234
# Dislikes: 0
# Total Accepted:    38.9K
# Total Submissions: 53K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]\n1'
#
# 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素
# mat[r][c] 的和：
#
#
# i - k <= r <= i + k,
# j - k <= c <= j + k 且
# (r, c) 在矩阵内。
#
#
#
#
# 示例 1：
#
# 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
# 输出：[[12,21,16],[27,45,33],[24,39,28]]
#
#
# 示例 2：
#
# 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
# 输出：[[45,45,45],[45,45,45],[45,45,45]]
#
#
#
#
# 提示：
#
#
# m == mat.length
# n == mat[i].length
# 1 <= m, n, k <= 100
# 1 <= mat[i][j] <= 100
#
#
#


# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        # 构建二维前缀和数组，pref[i+1][j+1] 表示 mat[0..i][0..j] 的和
        pref = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m):
            row_sum = 0
            for j in range(n):
                row_sum += mat[i][j]
                pref[i + 1][j + 1] = pref[i][j + 1] + row_sum

        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            r1 = max(0, i - k)
            r2 = min(m - 1, i + k)
            for j in range(n):
                c1 = max(0, j - k)
                c2 = min(n - 1, j + k)
                ans[i][j] = (
                    pref[r2 + 1][c2 + 1]
                    - pref[r1][c2 + 1]
                    - pref[r2 + 1][c1]
                    + pref[r1][c1]
                )
        return ans


# @lc code=end


#
# @lcpr case=start
# [[1,2,3],[4,5,6],[7,8,9]]\n1\n
# @lcpr case=end

# @lcpr case=start
# [[1,2,3],[4,5,6],[7,8,9]]\n2\n
# @lcpr case=end

#
