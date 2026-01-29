'''
描述
给一个01矩阵，1代表是陆地，0代表海洋， 如果两个1相邻，那么这两个1属于同一个岛。我们只考虑上下左右为相邻。
岛屿: 相邻陆地可以组成一个岛屿（相邻:上下左右） 判断岛屿个数。
例如：
输入
[
[1,1,0,0,0],
[0,1,0,1,1],
[0,0,0,1,1],
[0,0,0,0,0],
[0,0,1,1,1]
]
对应的输出为3
(注：存储的01数据其实是字符'0','1')
示例1
输入：
[[1,1,0,0,0],[0,1,0,1,1],[0,0,0,1,1],[0,0,0,0,0],[0,0,1,1,1]]
复制
返回值：
3
复制
示例2
输入：
[[0]]
复制
返回值：
0
复制
示例3
输入：
[[1,1],[1,1]]
复制
返回值：
1
复制
备注：
01矩阵范围<=200*200
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 判断岛屿数量
# @param grid char字符型二维数组
# @return int整型
#
class Solution:

    def solve(self, grid: List[List[str]]) -> int:
        # write code here

        m, n = len(grid), len(grid[0])
        res = 0
        flags = [[False for _ in range(n)] for _ in range(m)]

        def bfs(x: int, y: int):
            flags[x][y] = True
            que = [[x, y]]
            while que:
                x, y = que.pop(0)
                if x - 1 >= 0 and grid[x -
                                       1][y] == '1' and not flags[x - 1][y]:
                    que.append([x - 1, y])
                    flags[x - 1][y] = True
                if x + 1 < m and grid[x + 1][y] == '1' and not flags[x + 1][y]:
                    que.append([x + 1, y])
                    flags[x + 1][y] = True
                if y - 1 >= 0 and grid[x][y -
                                          1] == '1' and not flags[x][y - 1]:
                    que.append([x, y - 1])
                    flags[x][y - 1] = True
                if y + 1 < n and grid[x][y + 1] == '1' and not flags[x][y + 1]:
                    que.append([x, y + 1])
                    flags[x][y + 1] = True

        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not flags[i][j]:
                    res += 1
                    bfs(i, j)

        return res