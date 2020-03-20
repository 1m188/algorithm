/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 *
 * https://leetcode-cn.com/problems/prime-arrangements/description/
 *
 * algorithms
 * Easy (46.40%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 6.6K
 * Testcase Example:  '5'
 *
 * 请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。
 * 
 * 让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。
 * 
 * 由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 5
 * 输出：12
 * 解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1
 * 的位置上。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 100
 * 输出：682289015
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 
 * 
 */

#include "cmath"

// @lc code=start
class Solution
{
private:
    const int mod = 1e9 + 7;
    bool isPrime(int n)
    {
        if (n <= 1)
        {
            return false;
        }
        else if (n == 2)
        {
            return true;
        }
        else
        {
            int sq = sqrt(n);
            for (int i = 2; i <= sq; i++)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }

    long long arrange(int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        long long res = 1;
        for (int i = 1; i <= n; i++)
        {
            res *= i;
            if (res >= mod)
            {
                res %= mod;
            }
        }
        return res;
    }

public:
    int numPrimeArrangements(int n)
    {
        int primeNum = 0, normalNum = 0;
        for (int i = 1; i <= n; i++)
        {
            primeNum += isPrime(i);
        }
        normalNum = n - primeNum;
        if (primeNum == 0)
        {
            return arrange(normalNum) % mod;
        }
        else if (normalNum == 0)
        {
            return arrange(primeNum) % mod;
        }
        else
        {
            return arrange(primeNum) * arrange(normalNum) % mod;
        }
    }
};
// @lc code=end
