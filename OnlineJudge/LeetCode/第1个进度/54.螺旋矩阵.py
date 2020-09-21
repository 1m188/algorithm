#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#
# https://leetcode-cn.com/problems/spiral-matrix/description/
#
# algorithms
# Medium (40.89%)
# Likes:    461
# Dislikes: 0
# Total Accepted:    75.2K
# Total Submissions: 183.4K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
#
# 示例 1:
#
# 输入:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 4, 5, 6 ],
# ⁠[ 7, 8, 9 ]
# ]
# 输出: [1,2,3,6,9,8,7,4,5]
#
#
# 示例 2:
#
# 输入:
# [
# ⁠ [1, 2, 3, 4],
# ⁠ [5, 6, 7, 8],
# ⁠ [9,10,11,12]
# ]
# 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
#
#
#

from typing import List


# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        res = []

        while matrix:
            res.extend(matrix.pop(0))

            if matrix:
                for i in matrix:
                    res.append(i.pop())
                matrix = [i for i in matrix if i]

            if matrix:
                matrix[-1].reverse()
                res.extend(matrix.pop())

            if matrix:
                for i in range(len(matrix) - 1, -1, -1):
                    res.append(matrix[i].pop(0))
                matrix = [i for i in matrix if i]

        return res


# @lc code=end
