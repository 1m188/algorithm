"""
描述
给定两个三维向量，你需要求出这两个向量的叉乘的结果。

你需要实现一个函数，接受两个参数，均为由三个整数构成的向量。你需要计算出这两个向量叉乘的结果，并将这个结果作为该函数的返回值。
示例1
输入：
[1,0,1],[0,1,0]
复制
返回值：
[-1,0,1]
复制
备注：
数据保证各个向量的坐标的绝对值均小于
1
0
4
10
4
 。
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 计算出这两个向量叉乘的结果
# @param vector1 int整型一维数组
# @param vector2 int整型一维数组
# @return int整型一维数组
#
class Solution:
    def crossTimes(self, vector1: List[int], vector2: List[int]) -> List[int]:
        # write code here

        return [
            vector1[1] * vector2[2] - vector1[2] * vector2[1],
            vector1[2] * vector2[0] - vector1[0] * vector2[2],
            vector1[0] * vector2[1] - vector1[1] * vector2[0],
        ]
