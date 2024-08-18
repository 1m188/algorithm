/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 *
 * https://leetcode-cn.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (37.70%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    11.2K
 * Total Submissions: 29.8K
 * Testcase Example:  '28'
 *
 * 对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
 * 
 * 给定一个 整数 n， 如果他是完美数，返回 True，否则返回 False
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: 28
 * 输出: True
 * 解释: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 输入的数字 n 不会超过 100,000,000. (1e8)
 * 
 */

#include "cmath"

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int res = 1;
        int sq = sqrt(num);
        for (int i = 2; i <= sq; i++)
        {
            if (num % i == 0)
            {
                res += i + num / i;
            }
        }
        return num != 1 && res == num;
    }
};
// @lc code=end
