'''

描述
给定一个数组，请你实现将所有 0 移动到数组末尾并且不改变其他数字的相对顺序。

数据范围：数组长度满足 
1
≤
�
≤
1000
 
1≤n≤1000 ，数组中的元素满足 
1
≤
�
�
�
≤
1000
 
1≤val≤1000 
示例1
输入：
[1,2,0,3]
复制
返回值：
[1,2,3,0]
复制
示例2
输入：
[1,2,3]
复制
返回值：
[1,2,3]
复制
示例3
输入：
[0,0]
复制
返回值：
[0,0]

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

    def moveZeroes(self, nums: List[int]) -> List[int]:
        # write code here

        p = len(nums)
        i = 0
        while i < p:
            if nums[i] != 0:
                i += 1
                continue
            for j in range(i + 1, p):
                nums[j - 1], nums[j] = nums[j], nums[j - 1]
            p -= 1

        return nums
