'''
描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

数据范围：0 \leq n \leq 400≤n≤40
要求：时间复杂度：O(n)O(n) ，空间复杂度： O(1)O(1)
输入描述：
本题输入仅一行，即一个整数 n
输出描述：
输出跳上 n 级台阶有多少种跳法
示例1
输入：
2
复制
输出：
2
复制
说明：
青蛙要跳上两级台阶有两种跳法，分别是：先跳一级，再跳一级或者直接跳两级。因此答案为2        
示例2
输入：
7
复制
输出：
21
'''


def calc(n: int) -> int:
    if n <= 1: return 1
    # return calc(n - 1) + calc(n - 2)  # 递归
    dp = [0 for _ in range(n + 1)]  # 非递归 动态规划
    dp[1] = 1
    dp[2] = 2
    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    return dp[n]


n = int(input())
print(calc(n))
