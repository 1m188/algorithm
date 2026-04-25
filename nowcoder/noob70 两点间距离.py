"""
描述
给定两个二维平面下的点，求这两个点之间的距离。
示例1
输入：
(1,1),(1,8)
复制
返回值：
7.000
"""


class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b


# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 计算A点与B点之间的距离
# @param point_A Point类 A点
# @param point_B Point类 B点
# @return double浮点型
#
class Solution:
    def calculateDistance(self, point_A: Point, point_B: Point) -> float:
        # write code here

        return ((point_A.x - point_B.x) ** 2 + (point_A.y - point_B.y) ** 2) ** 0.5
