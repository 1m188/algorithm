'''
描述
请实现无重复数字的升序数组的二分查找

给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1

数据范围：0 \le len(nums) \le 2\times10^50≤len(nums)≤2×10 
5
  ， 数组中任意值满足 |val| \le 10^9∣val∣≤10 
9
 
进阶：时间复杂度 O(\log n)O(logn) ，空间复杂度 O(1)O(1)

示例1
输入：
[-1,0,3,4,6,10,13,14],13
复制
返回值：
6
复制
说明：
13 出现在nums中并且下标为 6     
示例2
输入：
[],3
复制
返回值：
-1
复制
说明：
nums为空，返回-1     
示例3
输入：
[-1,0,3,4,6,10,13,14],2
复制
返回值：
-1
复制
说明：
2 不存在nums中因此返回 -1     
备注：
数组元素长度在[0,10000]之间
数组每个元素都在 [-9999, 9999]之间。
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @param target int整型
# @return int整型
#
class Solution:

    def search(self, nums: List[int], target: int) -> int:
        # write code here

        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target: return mid
            elif nums[mid] > target: right = mid - 1
            else: left = mid + 1
        return -1