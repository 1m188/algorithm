'''
描述
给定两个递增数组arr1和arr2，已知两个数组的长度都为N，求两个数组中所有数的上中位数。
上中位数：假设递增序列长度为n，为第n/2个数

数据范围：
1
≤
n
≤
1
0
5
1≤n≤10 
5
 ， 
0
≤
a
r
r
1
,
a
r
r
2
≤
1
0
9
0≤arr 
1
​
 ,arr 
2
​
 ≤10 
9
 

要求：时间复杂度 
O
(
n
)
O(n)，空间复杂度 
O
(
1
)
O(1)
进阶：时间复杂度为
O
(
l
o
g
N
)
O(logN)，空间复杂度为
O
(
1
)
O(1)

示例1
输入：
[1,2,3,4],[3,4,5,6]
复制
返回值：
3
复制
说明：
总共有8个数，上中位数是第4小的数，所以返回3。   
示例2
输入：
[0,1,2],[3,4,5]
复制
返回值：
2
复制
说明：
总共有6个数，那么上中位数是第3小的数，所以返回2   
示例3
输入：
[1],[2]
复制
返回值：
1
复制
备注：
1
≤
N
≤
1
0
5
1≤N≤10 
5
 
0
≤
a
r
r
1
i
,
a
r
r
2
i
≤
1
0
9
0≤arr 
1i
​
 ,arr 
2i
​
 ≤10 
9
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# find median in two sorted array
# @param arr1 int整型一维数组 the array1
# @param arr2 int整型一维数组 the array2
# @return int整型
#
class Solution:

    def findMedianinTwoSortedAray(self, arr1: List[int], arr2: List[int]) -> int:
        # write code here

        n = len(arr1)
        index = n - 1

        i, j = 0, 0
        idx = -1
        res = -1
        while i < len(arr1) and j < len(arr2):
            idx += 1
            if arr1[i] > arr2[j]:
                res = arr2[j]
                j += 1
            else:
                res = arr1[i]
                i += 1
            if idx == index: break
        return res
