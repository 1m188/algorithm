'''
描述
给定一个整数数组 cost \cost  ，其中 cost[i]\cost[i]  是从楼梯第i \i 个台阶向上爬需要支付的费用，下标从0开始。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

数据范围：数组长度满足 1 \le n \le 10^5 \1≤n≤10 
5
   ，数组中的值满足 1 \le cost_i \le 10^4 \1≤cost 
i
​
 ≤10 
4
  
示例1
输入：
[2,5,20]
复制
返回值：
5
复制
说明：
你将从下标为1的台阶开始，支付5 ，向上爬两个台阶，到达楼梯顶部。总花费为5   
示例2
输入：
[1,100,1,1,1,90,1,1,80,1]
复制
返回值：
6
复制
说明：
你将从下标为 0 的台阶开始。
1.支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
2.支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
3.支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
4.支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
5.支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
6.支付 1 ，向上爬一个台阶，到达楼梯顶部。
总花费为 6 。    
'''

from typing import List


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param cost int整型一维数组
# @return int整型
#
class Solution:

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # write code here

        n = len(cost)
        dp = [[0 for _ in range(n + 1)] for _ in range(2)]

        dp[0][0] = 0
        dp[0][1] = cost[0]
        for i in range(2, n + 1):
            dp[0][i] = min(dp[0][i - 1] + cost[i - 1],
                           dp[0][i - 2] + cost[i - 2])

        if n == 1: return dp[0][n]

        dp[1][1] = 0
        dp[1][2] = cost[1]
        for i in range(3, n + 1):
            dp[1][i] = min(dp[1][i - 1] + cost[i - 1],
                           dp[1][i - 2] + cost[i - 2])

        return min(dp[0][n], dp[1][n])
