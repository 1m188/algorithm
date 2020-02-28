/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 *
 * https://leetcode-cn.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.79%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    14.8K
 * Total Submissions: 45.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c。
 * 
 * 示例1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * 示例2:
 * 
 * 
 * 输入: 3
 * 输出: False
 * 
 * 
 */

#include "cmath"

// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int sqc = sqrt(c);
        for (int i = 0; i <= sqc; i++)
        {
            int p = i * i;
            int sq = sqrt(c - p);
            if (sq * sq + p == c)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
