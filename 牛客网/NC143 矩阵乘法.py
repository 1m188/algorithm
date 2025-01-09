'''
描述
给定两个 n*n 的矩阵 A 和 B ，求 A*B 。

数据范围：
1
≤
n
≤
100
1≤n≤100，
−
100
≤
M
a
t
r
i
x
i
,
j
≤
100
−100≤Matrix 
i,j
​
 ≤100

要求：空间复杂度 
O
(
n
2
)
O(n 
2
 ) ， 时间复杂度 
O
(
n
3
)
O(n 
3
 )
进阶：本题也有空间复杂度 
O
(
n
2
)
O(n 
2
 )，时间复杂度 
O
(
n
l
o
g
7
)
O(n 
log7
 )的解法
PS：更优时间复杂度的算法这里并不考察
示例1
输入：
[[1,2],[3,2]],[[3,4],[2,1]]
复制
返回值：
[[7,6],[13,14]]
复制
示例2
输入：
[[1]],[[1]]
复制
返回值：
[[1]]
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param a int整型二维数组 第一个矩阵
# @param b int整型二维数组 第二个矩阵
# @return int整型二维数组
#
class Solution:

    def solve(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        # write code here

        n = len(a)

        res = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n):
            for j in range(n):
                res[i][j] = sum([a[i][k] * b[k][j] for k in range(n)])

        return res
