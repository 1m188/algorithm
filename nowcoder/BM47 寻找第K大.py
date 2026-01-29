'''
描述
有一个整数数组，请你根据快速排序的思路，找出数组中第 k 大的数。

给定一个整数数组 a ,同时给定它的大小n和要找的 k ，请返回第 k 大的数(包括重复的元素，不用去重)，保证答案存在。
要求：时间复杂度 O(nlogn)O(nlogn)，空间复杂度 O(1)O(1)
数据范围：0\le n \le 10000≤n≤1000， 1 \le K \le n1≤K≤n，数组中每个元素满足 0 \le val \le 100000000≤val≤10000000
示例1
输入：
[1,3,5,2,2],5,3
复制
返回值：
2
复制
示例2
输入：
[10,10,9,9,8,7,5,6,4,3,4,2],12,3
复制
返回值：
9
复制
说明：
去重后的第3大是8，但本题要求包含重复的元素，不用去重，所以输出9 
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param a int整型一维数组
# @param n int整型
# @param K int整型
# @return int整型
#
class Solution:

    def findKth(self, a: List[int], n: int, K: int) -> int:
        # write code here

        self.quick_sort(a, 0, n - 1)
        return a[K - 1]

    def quick_sort(self, li: List[int], left: int, right: int):
        if left >= right: return
        tmp = li[left]
        l, r = left, right
        while l < r:
            while l < r and li[r] <= tmp:
                r -= 1
            if l < r:
                li[l] = li[r]
                l += 1
            while l < r and li[l] >= tmp:
                l += 1
            if l < r:
                li[r] = li[l]
                r -= 1
        li[l] = tmp
        self.quick_sort(li, left, l - 1)
        self.quick_sort(li, l + 1, right)
