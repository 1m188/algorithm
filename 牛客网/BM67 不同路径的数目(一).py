'''
描述
一个机器人在m×n大小的地图的左上角（起点）。
机器人每次可以向下或向右移动。机器人要到达地图的右下角（终点）。
可以有多少种不同的路径从起点走到终点？

备注：m和n小于等于100,并保证计算结果在int范围内

数据范围：0 < n,m \le 1000<n,m≤100，保证计算结果在32位整型范围内
要求：空间复杂度 O(nm)O(nm)，时间复杂度 O(nm)O(nm)
进阶：空间复杂度 O(1)O(1)，时间复杂度 O(min(n,m))O(min(n,m))
示例1
输入：
2,1
复制
返回值：
1
复制
示例2
输入：
2,2
复制
返回值：
2

'''


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param m int整型
# @param n int整型
# @return int整型
#
class Solution:

    def uniquePaths(self, m: int, n: int) -> int:
        # write code here

        dp = [[1 for _ in range(n)] for _ in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        return dp[m - 1][n - 1]
