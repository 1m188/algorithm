/**
 * @file FZ36 牛吃草捆的问题.cpp
 * @date 2024-11-22
 */

/*
描述
在动物牛国度的大草原上，牛牛每天都要吃草。一天中，牛牛可以选择吃一捆草或者两捆草。现在，请你编写一个函数，计算牛牛吃完 n 捆草有多少种不同的吃法数。

给定一个整数 n，表示草捆的数量，请你实现函数 int countDays(int n)，返回牛牛吃完 n 捆草的不同天数。答案需要取模 1e9+7（1000000007）。

示例1
输入：
2
复制
返回值：
2
复制
示例2
输入：
10
复制
返回值：
89
复制
备注：
0 <= n <= 1000
*/
#include <cstdint>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int countDays(int n) {
        // write code here

        constexpr uint64_t mod = 1000000007;

        if (n == 0 || n == 1) return 1;

        int dp[1000 + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;

        return dp[n];
    }
};