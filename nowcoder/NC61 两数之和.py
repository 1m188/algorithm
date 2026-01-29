'''
描述
给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。
（注：返回的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）

数据范围：2\leq len(numbers) \leq 10^52≤len(numbers)≤10 
5
 ，-10 \leq numbers_i \leq 10^9−10≤numbers 
i
​
 ≤10 
9
 ，0 \leq target \leq 10^90≤target≤10 
9
 
要求：空间复杂度 O(n)O(n)，时间复杂度 O(nlogn)O(nlogn)
示例1
输入：
[3,2,4],6
复制
返回值：
[2,3]
复制
说明：
因为 2+4=6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2,3]            
示例2
输入：
[20,70,110,150],90
复制
返回值：
[1,2]
复制
说明：
20+70=90     
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param numbers int整型一维数组
# @param target int整型
# @return int整型一维数组
#
class Solution:

    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # write code here

        nums = [[v, i + 1] for i, v in enumerate(numbers)]
        nums.sort(key=lambda x: x[0])
        a, b = 0, len(nums) - 1
        while a < b:
            if nums[a][0] + nums[b][0] == target:
                return sorted([nums[a][1], nums[b][1]])
            elif nums[a][0] + nums[b][0] < target:
                a += 1
            else:
                b -= 1
