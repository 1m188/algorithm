#
# @lc app=leetcode.cn id=1886 lang=python3
#
# [1886] 判断矩阵经轮转后是否一致
#
# https://leetcode.cn/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
#
# algorithms
# Easy (59.68%)
# Likes:    32
# Dislikes: 0
# Total Accepted:    11.8K
# Total Submissions: 19.8K
# Testcase Example:  '[[0,1],[1,0]]\n[[1,0],[0,1]]'
#
# 给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，如果能够使 mat 与
# target 一致，返回 true ；否则，返回 false 。
#
#
#
# 示例 1：
#
#
# 输入：mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
# 输出：true
# 解释：顺时针轮转 90 度一次可以使 mat 和 target 一致。
#
#
# 示例 2：
#
#
# 输入：mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
# 输出：false
# 解释：无法通过轮转矩阵中的元素使 equal 与 target 一致。
#
#
# 示例 3：
#
#
# 输入：mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
# 输出：true
# 解释：顺时针轮转 90 度两次可以使 mat 和 target 一致。
#
#
#
#
# 提示：
#
#
# n == mat.length == target.length
# n == mat[i].length == target[i].length
# 1
# mat[i][j] 和 target[i][j] 不是 0 就是 1
#
#
#

from typing import List


# @lc code=start
class Solution:

    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:

        def rot(mat: list[list[int]]):
            n = len(mat)

            left = 0
            right = n - 1
            up = 0
            bottom = n - 1

            for _ in range(n // 2):
                for _ in range(right - left):
                    i, j = left, up
                    tmp = mat[i][j]
                    while j < right:
                        mat[i][j + 1], tmp = tmp, mat[i][j + 1]
                        j += 1
                    while i < bottom:
                        mat[i + 1][j], tmp = tmp, mat[i + 1][j]
                        i += 1
                    while j > left:
                        mat[i][j - 1], tmp = tmp, mat[i][j - 1]
                        j -= 1
                    while i > up:
                        mat[i - 1][j], tmp = tmp, mat[i - 1][j]
                        i -= 1

                left += 1
                right -= 1
                up += 1
                bottom -= 1

        if mat == target: return True
        for _ in range(3):
            rot(mat)
            if mat == target: return True
        return False


# @lc code=end
