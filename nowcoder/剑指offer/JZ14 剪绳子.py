# 描述
# 给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），
# 每段绳子的长度记为 k[1],...,k[m] 。请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？
# 例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。

# 数据范围： 2 \le n \le 602≤n≤60
# 进阶：空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n)
# 输入描述：
# 输入一个数n，意义见题面。
# 返回值描述：
# 输出答案。
# 示例1
# 输入：
# 8
# 复制
# 返回值：
# 18
# 复制
# 说明：
# 8 = 2 +3 +3 , 2*3*3=18
# 示例2
# 输入：
# 2
# 复制
# 返回值：
# 1
# 复制
# 说明：
# m>1，所以切成两段长度是1的绳子


#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param number int整型
# @return int整型
#
class Solution:

    def cutRope(self, number: int) -> int:
        # write code here

        if number <= 3: return number - 1

        dp = [0 for _ in range(number + 1)]
        dp[1] = 1
        dp[2] = 2
        dp[3] = 3

        for i in range(4, number + 1):
            for j in range(1, i):
                dp[i] = max(dp[i], j * dp[i - j])

        return dp[number]
