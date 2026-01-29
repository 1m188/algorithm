'''
描述
给定一个长度为N的正整数数组nums，其中nums[i]的值都在区间[1,n]中，请你找出nums数组在[1,n]范围里面没有出现过的数字，并将它们放在数组里面返回(在数组里面的顺序可以不唯一)

注:本题有时间复杂度为O(n)，空间复杂度为O(1)的解法，返回的数组不计入空间复杂度计算

数据范围:
1
≤
n
≤
1
0
5
1≤n≤10 
5
 
1
≤
n
u
m
s
[
i
]
≤
n
1≤nums[i]≤n
示例1
输入：
[2,1,4,5,1,2]
复制
返回值：
[3,6]
复制
说明：
数组长度为6，那么范围为[1,6]，其中3和6没有在数组里面出现，返回[3,6]  
示例2
输入：
[1,1]
复制
返回值：
[2]
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @return int整型一维数组
#
class Solution:

    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # write code here
        n = len(nums)
        li = [False for _ in range(n + 1)]
        for i in nums:
            li[i] = True
        res = [i for i in range(1, n + 1) if not li[i]]
        return res
