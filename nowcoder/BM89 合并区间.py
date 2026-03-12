"""
描述
给出一组区间，请合并所有重叠的区间。
请保证合并后的区间按区间起点升序排列。
//"区间"定义
class Interval {
   int start; //起点
   int end;   //终点
}

数据范围：区间组数
0
≤
n
≤
2
×
1
0
5
0≤n≤2×10
5
 ，区间内 的值都满足
0
≤
v
a
l
≤
2
×
1
0
5
0≤val≤2×10
5

要求：空间复杂度
O
(
n
)
O(n)，时间复杂度
O
(
n
l
o
g
n
)
O(nlogn)
进阶：空间复杂度
O
(
v
a
l
)
O(val)，时间复杂度
O
(
v
a
l
)
O(val)
示例1
输入：
[[10,30],[20,60],[80,100],[150,180]]
复制
返回值：
[[10,60],[80,100],[150,180]]
复制
示例2
输入：
[[0,10],[10,20]]
复制
返回值：
[[0,20]]
"""

from typing import List


class Interval:
    def __init__(self, a=0, b=0):
        self.start = a
        self.end = b


# class Interval:
#     def __init__(self, a=0, b=0):
#         self.start = a
#         self.end = b
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param intervals Interval类一维数组
# @return Interval类一维数组
#
class Solution:
    def merge(self, intervals: List[Interval]) -> List[Interval]:
        # write code here

        intervals.sort(key=lambda x: x.start)
        li = []
        for interval in intervals:
            if not li:
                li.append(interval)
            else:
                last = li[-1]
                if interval.start <= last.end:
                    last.end = max(last.end, interval.end)
                else:
                    li.append(interval)
        return li
