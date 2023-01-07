'''
描述
N 皇后问题是指在 n * n 的棋盘上要摆 n 个皇后，
要求：任何两个皇后不同行，不同列也不在同一条斜线上，
求给一个整数 n ，返回 n 皇后的摆法数。

数据范围: 1 \le n \le 91≤n≤9
要求：空间复杂度 O(1)O(1) ，时间复杂度 O(n!)O(n!)

例如当输入4时，对应的返回值为2，
对应的两种四皇后摆位如下图所示：

示例1
输入：
1
复制
返回值：
1
复制
示例2
输入：
8
复制
返回值：
92
'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param n int整型 the n
# @return int整型
#
class Solution:

    def Nqueen(self, n: int) -> int:
        # write code here

        self.che = [[False for _ in range(n)] for _ in range(n)]
        self.res = 0
        self.dfs()
        return self.res

    def dfs(self, cnt: int = 0):
        if cnt == len(self.che):
            self.res += 1
            return
        for i in range(len(self.che)):
            self.che[cnt][i] = True
            if self.judge(cnt, i): self.dfs(cnt + 1)
            self.che[cnt][i] = False

    def judge(self, x: int, y: int) -> bool:
        n = len(self.che)
        for i in range(n):
            if i != x and self.che[i][y]: return False
            if i != y and self.che[x][i]: return False
        xt, yt = x - 1, y - 1
        while xt >= 0 and yt >= 0:
            if self.che[xt][yt]: return False
            xt -= 1
            yt -= 1
        xt, yt = x + 1, y + 1
        while xt < n and yt < n:
            if self.che[xt][yt]: return False
            xt += 1
            yt += 1
        xt, yt = x - 1, y + 1
        while xt >= 0 and yt < n:
            if self.che[xt][yt]: return False
            xt -= 1
            yt += 1
        xt, yt = x + 1, y - 1
        while xt < n and yt >= 0:
            if self.che[xt][yt]: return False
            xt += 1
            yt -= 1
        return True
