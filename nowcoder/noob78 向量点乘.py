"""
描述
给定两个三维向量，你需要求出这两个向量的点乘的结果。

你需要实现一个函数，接受两个参数，均为由三个整数构成的向量。你需要计算出这两个向量点乘的结果，并将这个结果作为该函数的返回值。
示例1
输入：
[1,1,4],[5,1,4]
复制
返回值：
22
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
# 计算两个三维向量的点乘结果
# @param vector1 int整型一维数组 第一个向量
# @param vector2 int整型一维数组 第二个向量
# @return int整型
#
class Solution:
    def dotTime(self, vector1: List[int], vector2: List[int]) -> int:
        # write code here

        return sum(vector1[i] * vector2[i] for i in range(3))
