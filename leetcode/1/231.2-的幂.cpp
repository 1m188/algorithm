/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (44.59%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    45.9K
 * Total Submissions: 96.3K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        else if (n == 1 || n == 2)
        {
            return true;
        }
        else
        {
            return n % 2 == 0 ? isPowerOfTwo(n / 2) : false;
        }
    }
};
// @lc code=end
