'''
描述
请实现有重复数字的升序数组的二分查找
给定一个 元素有序的（升序）长度为n的整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的第一个出现的target，如果目标值存在返回下标，否则返回 -1

数据范围：
0
≤
n
≤
100000
 
0≤n≤100000 
进阶：时间复杂度
O
(
l
o
g
n
)
 
O(logn) ，空间复杂度
O
(
n
)
 
O(n) 
示例1
输入：
[1,2,4,4,5],4
复制
返回值：
2
复制
说明：
从左到右，查找到第1个为4的，下标为2，返回2    
示例2
输入：
[1,2,4,4,5],3
复制
返回值：
-1
复制
示例3
输入：
[1,1,1,1,1],1
复制
返回值：
0
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 如果目标值存在返回下标，否则返回 -1
# @param nums int整型一维数组
# @param target int整型
# @return int整型
#
class Solution:

    def search(self, nums: List[int], target: int) -> int:
        # write code here

        n = len(nums)
        if n == 0: return -1
        left, right = 0, n - 1
        mid = 0
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target: break
            elif nums[mid] < target: left = mid + 1
            else: right = mid - 1

        if nums[mid] != target: return -1
        while mid >= 0 and nums[mid] == target:
            mid -= 1
        return mid + 1
