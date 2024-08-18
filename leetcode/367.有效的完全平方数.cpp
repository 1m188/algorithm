/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.07%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 54.8K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        for (long long i = 1; i * i <= num; i++)
        {
            if (i * i == num)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
