"""
描述
给定两个序列
n
u
m
s
1
nums1 和
n
u
m
s
2
nums2 ，返回它们的交集 。输出结果中的每个元素一定是唯一的，此外你还需要保证返回值需要按照升序排列。
示例1
输入：
[1,1,4],[5,1,4]
复制
返回值：
[1,4]
复制
备注：
1
≤
∣
n
u
m
s
1
∣
,
∣
n
u
m
s
2
∣
≤
1000
1≤∣nums1∣,∣nums2∣≤1000
0
≤
n
u
m
s
1
i
,
n
u
m
s
2
i
≤
1000
0≤nums1
i
​
 ,nums2
i
​
 ≤1000
"""

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums1 int整型一维数组
# @param nums2 int整型一维数组
# @return int整型一维数组
#
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        # write code here

        return sorted(list(set(nums1) & set(nums2)))
