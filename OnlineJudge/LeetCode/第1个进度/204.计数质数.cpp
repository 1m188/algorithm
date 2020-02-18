/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.94%)
 * Likes:    273
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 131.5K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */

#include "cmath"

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
        {
            return 0;
        }

        int num = 1;
        for (int i = 3; i < n; i++)
        {
            int sqi = sqrt(i);
            for (int j = 2; j <= sqi; j++)
            {
                if (i % j == 0)
                {
                    goto next;
                }
            }
            num++;
        next:;
        }
        return num;
    }
};
// @lc code=end
