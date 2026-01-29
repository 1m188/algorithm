'''
描述
农场里有一群牛，每头牛都有一个编号。农场主想要根据牛的编号对牛群进行升序排序。给定一个代表每头牛编号的整数数组，请你将该数组升序排列。不允许调用库函数。

示例1
输入：
[3, 2, 1]
复制
返回值：
[1,2,3]
复制
示例2
输入：
[1, 1, 1, 1, 1]
复制
返回值：
[1,1,1,1,1]
复制
备注：
1 <= nums.length <= 2 * 10^5
0 <= nums[i] <= 2 * 10^5
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

    def sortCows(self, nums: List[int]) -> List[int]:
        # write code here

        n = len(nums)
        for i in range(n - 1, -1, -1):
            f = False
            for j in range(i):
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
                    f = True
            if not f: break

        return nums
