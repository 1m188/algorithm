'''

描述
在一个农场里，有n头牛，每头牛的重量都不同。农场主人想计算一下，除了每头牛以及它前后两头牛的重量以外，其余牛的重量的乘积是多少。

你需要返回一个数组，其中数组的第i个元素表示除了第i头牛以及它前后两头牛的重量以外，其余牛的重量的乘积，首尾牛不用考虑三个相邻，只需要考虑两个。

注意：请不要使用除法，且在 O(n) 时间复杂度内完成此题。题目数据保证数组之中任意元素的全部前缀元素和后缀的乘积都在 32 位整数范围内。

示例1
输入：
[1,2,3,4,5]
复制
返回值：
[60,20,5,2,6]
复制
示例2
输入：
[2,3,4,5,6]
复制
返回值：
[120,30,12,6,24]
复制
备注：
4 <= n <= 10^5

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

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # write code here

        left, right = [], []

        x = 1
        for i in nums:
            x *= i
            left.append(x)
        x = 1
        for i in nums[::-1]:
            x *= i
            right.append(x)

        n = len(nums)
        res = []
        for i in range(n):

            l = i - 2
            if l < 0: l = 1
            else: l = left[l]

            r = n - (i + 2) - 1
            if r >= n or r < 0: r = 1
            else: r = right[r]

            res.append(l * r)

        return res
