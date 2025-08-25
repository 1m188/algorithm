#
# @lc app=leetcode.cn id=498 lang=python3
# @lcpr version=30204
#
# [498] 对角线遍历
#
# https://leetcode.cn/problems/diagonal-traverse/description/
#
# algorithms
# Medium (56.37%)
# Likes:    527
# Dislikes: 0
# Total Accepted:    150.2K
# Total Submissions: 263.2K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# 给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
#
#
#
# 示例 1：
#
# 输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
# 输出：[1,2,4,7,5,3,6,8,9]
#
#
# 示例 2：
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

# @lcpr-template-start
from typing import List


# @lcpr-template-end
# @lc code=start
class Solution:

    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:

        res = []

        m, n = len(mat), len(mat[0])
        i, j = 0, 0
        ii, jj = 0, 0
        f = True
        ff = True
        while True:
            i, j = ii, jj
            f = ff
            res.append(mat[i][j])
            if f: ii, jj = i - 1, j + 1
            else: ii, jj = i + 1, j - 1
            if 0 <= ii < m and 0 <= jj < n: continue
            if f:
                ii, jj = i, j + 1
                ff = False
            else:
                ii, jj = i + 1, j
                ff = True
            if 0 <= ii < m and 0 <= jj < n: continue
            if f:
                ii, jj = i + 1, j
                ff = False
            else:
                ii, jj = i, j + 1
                ff = True
            if 0 <= ii < m and 0 <= jj < n: continue
            else: break

        return res


# @lc code=end

#
# @lcpr case=start
# [[1,2,3],[4,5,6],[7,8,9]]\n
# @lcpr case=end

# @lcpr case=start
# [[1,2],[3,4]]\n
# @lcpr case=end

#
