"""
描述
给定一个m x n大小的矩阵（m行，n列），按螺旋的顺序返回矩阵中的所有元素。

数据范围：
0
≤
n
,
m
≤
10
0≤n,m≤10，矩阵中任意元素都满足
∣
v
a
l
∣
≤
100
∣val∣≤100
要求：空间复杂度
O
(
n
m
)
O(nm) ，时间复杂度
O
(
n
m
)
O(nm)
示例1
输入：
[[1,2,3],[4,5,6],[7,8,9]]
复制
返回值：
[1,2,3,6,9,8,7,4,5]
复制
示例2
输入：
[]
复制
返回值：
[]
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param matrix int整型二维数组
# @return int整型一维数组
#
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # write code here

        if not matrix:
            return []

        m, n = len(matrix), len(matrix[0])
        res = []

        left, right, top, bottom = 0, n - 1, 0, m - 1
        i, j = 0, 0
        di, dj = 0, 1
        while top <= i <= bottom and left <= j <= right:
            res.append(matrix[i][j])

            if not (top <= i + di <= bottom and left <= j + dj <= right):
                if (di, dj) == (0, 1):
                    di, dj = 1, 0
                    top += 1
                elif (di, dj) == (1, 0):
                    di, dj = 0, -1
                    right -= 1
                elif (di, dj) == (0, -1):
                    di, dj = -1, 0
                    bottom -= 1
                elif (di, dj) == (-1, 0):
                    di, dj = 0, 1
                    left += 1

            i += di
            j += dj

        return res
