'''

描述
在一个农场里，有n头牛，每头牛都有一个唯一的编号，编号从1到n。牛群被安排在一个n的方阵中，方阵的左上角是编号为1的牛，方阵的右下角是编号为n*n的牛。
农场的主人想改变牛群的排列顺序，他的规则是：每次将方阵中的每头牛同时向左一格和向上一格移动，如果已经在最左边的牛会移动到同一行的最右边，同时向上一格，如果已经在最上边的牛会移动到同一列的最下边，同时向左一格。当最左上的牛移动时，会循环到最右下。

现在农场主人想知道，经过k次移动后，方阵中的牛群的排列情况。由于牛群数量较多，农场主人难以计算，他需要你的帮忙。

示例1
输入：
3,1
复制
返回值：
[[5,6,4],[8,9,7],[2,3,1]]
复制
示例2
输入：
2,2
复制
返回值：
[[1,2],[3,4]]
复制
备注：
1<=n<=300
0<=k<=10^5

'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param n int整型
# @param k int整型
# @return int整型二维数组
#
class Solution:

    def rotateII(self, n: int, k: int) -> List[List[int]]:
        # write code here

        mat = [[i + j * n for i in range(1, n + 1)] for j in range(n)]

        k %= n
        if k == 0: return mat

        mat_new = [[0 for _ in range(n)] for _ in range(n)]

        for i in range(n):
            for j in range(n):
                a, b = i, j
                for _ in range(k):
                    if a == 0 and b == 0:
                        a = n - 1
                        b = n - 1
                        continue
                    b -= 1
                    if b < 0:
                        b = n - 1
                        a -= 1
                        if a < 0: a = n - 1
                    else:
                        a -= 1
                        if a < 0:
                            a = n - 1
                mat_new[a][b] = mat[i][j]
        return mat_new
