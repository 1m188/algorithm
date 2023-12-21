#
# @lc app=leetcode.cn id=498 lang=python3
#
# [498] 对角线遍历
#
# https://leetcode.cn/problems/diagonal-traverse/description/
#
# algorithms
# Medium (55.79%)
# Likes:    472
# Dislikes: 0
# Total Accepted:    118.7K
# Total Submissions: 212.7K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
#
#
#
# 示例 1：
#
#
# 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
# 输出：[1,2,4,7,5,3,6,8,9]
#
#
# 示例 2：
#
#
# 输入：mat = [[1,2],[3,4]]
# 输出：[1,2,3,4]
#
#
#
#
# 提示：
#
#
# m == mat.length
# n == mat[i].length
# 1 <= m, n <= 10^4
# 1 <= m * n <= 10^4
# -10^5 <= mat[i][j] <= 10^5
#
#
#

from typing import List


# @lc code=start
class Solution:

    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:

        m, n = len(mat), len(mat[0])

        res = []
        i, j = 0, 0
        f = True

        while True:
            res.append(mat[i][j])

            if f:
                ii, jj = i - 1, j + 1
                if ii < 0 and jj < n:
                    ii = i
                    f = not f
                elif jj >= n:
                    ii = i + 1
                    jj = j
                    f = not f
            else:
                ii, jj = i + 1, j - 1
                if jj < 0 and ii < m:
                    jj = j
                    f = not f
                elif ii >= m:
                    jj = j + 1
                    ii = i
                    f = not f

            if ii < 0 or ii >= m or jj < 0 or jj >= n: break
            i, j = ii, jj

        return res


# @lc code=end
