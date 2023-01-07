'''
描述
给定一个无重复元素的整数数组nums，请你找出其中没有出现的最小的正整数

进阶： 空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)

数据范围:
-2^{31}\le nums[i] \le 2^{31}-1−2 
31
 ≤nums[i]≤2 
31
 −1
0\le len(nums)\le5*10^50≤len(nums)≤5∗10 
5
 
示例1
输入：
[1,0,2]
复制
返回值：
3
复制
示例2
输入：
[-2,3,4,1,5]
复制
返回值：
2
复制
示例3
输入：
[4,5,6,8,9]
复制
返回值：
1
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @return int整型
#
class Solution:

    def minNumberDisappeared(self, nums: List[int]) -> int:
        # write code here

        nums.sort()
        for i in range(len(nums)):
            if nums[i] > 0: break
        cnt = 1
        for j in range(i, len(nums)):
            if nums[j] != cnt: break
            cnt += 1
        return cnt
