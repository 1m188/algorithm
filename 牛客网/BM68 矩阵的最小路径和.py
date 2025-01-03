'''
描述
给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。

数据范围: 
1
≤
n
,
m
≤
500
1≤n,m≤500，矩阵中任意值都满足 
0
≤
a
i
,
j
≤
100
0≤a 
i,j
​
 ≤100
要求：时间复杂度 
O
(
n
m
)
O(nm)

例如：当输入[[1,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,0]]时，对应的返回值为12，
所选择的最小累加和路径如下图所示：

示例1
输入：
[[1,3,5,9],[8,1,3,4],[5,0,6,1],[8,8,4,0]]
复制
返回值：
12
复制
示例2
输入：
[[1,2,3],[1,2,3]]
复制
返回值：
7
复制
备注：
1
≤
n
,
m
≤
2000
1≤n,m≤2000
1
≤
a
i
,
j
≤
100
1≤a 
i,j
​
 ≤100
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param matrix int整型二维数组 the matrix
# @return int整型
#
class Solution:

    def minPathSum(self, matrix: List[List[int]]) -> int:
        # write code here

        n, m = len(matrix), len(matrix[0])
        dp = [[0 for _ in range(m)] for _ in range(n)]
        dp[0][0] = matrix[0][0]

        for i in range(1, m):
            dp[0][i] = dp[0][i - 1] + matrix[0][i]
        for i in range(1, n):
            dp[i][0] = dp[i - 1][0] + matrix[i][0]

        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + matrix[i][j]

        return dp[n - 1][m - 1]
