'''
描述
给定一个长度为 n 的数组，请你编写一个函数，返回该数组按升序排序后的结果。

数据范围： 0 \le n \le 1\times10^30≤n≤1×10 
3
 ，数组中每个元素都满足 0 \le val \le 10^90≤val≤10 
9
 
要求：时间复杂度 O(n^2)O(n 
2
 )，空间复杂度 O(n)O(n)
进阶：时间复杂度 O(nlogn)O(nlogn)，空间复杂度 O(n)O(n)

注：本题数据范围允许绝大部分排序算法，请尝试多种排序算法的实现。
示例1
输入：
[5,2,3,1,4]
复制
返回值：
[1,2,3,4,5]
复制
示例2
输入：
[5,1,6,2,5]
复制
返回值：
[1,2,5,5,6]
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 将给定数组排序
# @param arr int整型一维数组 待排序的数组
# @return int整型一维数组
#
class Solution:

    def MySort(self, arr: List[int]) -> List[int]:
        # write code here

        # return sorted(arr)

        n = len(arr)
        for r in range(n - 1, -1, -1):
            f = False
            for i in range(r):
                if arr[i] > arr[i + 1]:
                    arr[i], arr[i + 1] = arr[i + 1], arr[i]
                    f = True
            if not f: break
        return arr
