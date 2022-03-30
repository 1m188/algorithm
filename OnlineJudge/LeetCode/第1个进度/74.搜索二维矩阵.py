#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#
# https://leetcode-cn.com/problems/search-a-2d-matrix/description/
#
# algorithms
# Medium (47.02%)
# Likes:    611
# Dislikes: 0
# Total Accepted:    215.8K
# Total Submissions: 458.9K
# Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
#
# 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
#
#
# 每行中的整数从左到右按升序排列。
# 每行的第一个整数大于前一行的最后一个整数。
#
#
#
#
# 示例 1：
#
#
# 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
# 输出：true
#
#
# 示例 2：
#
#
# 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
# 输出：false
#
#
#
#
# 提示：
#
#
# m == matrix.length
# n == matrix[i].length
# 1 <= m, n <= 100
# (-10)^4 <= matrix[i][j], target <= 10^4
#
#
#

from typing import List


# @lc code=start
class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        f = True
        for i in matrix:
            if i[0] <= target <= i[-1]:
                f = False
                break

        if f:
            return False
        else:
            return False if self.bs(i, target) == -1 else True

    def bs(self, vec: List[int], target: int) -> int:

        start, end = 0, len(vec) - 1
        while start <= end:
            i = int((start + end) / 2)
            if vec[i] == target:
                return i
            elif vec[i] > target:
                end = i - 1
            else:
                start = i + 1
        return -1


# @lc code=end
