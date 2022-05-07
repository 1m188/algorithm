/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (44.83%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    19.1K
 * Total Submissions: 39.8K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0)
        {
            return false;
        }
        else if (num == 1)
        {
            return true;
        }
        else
        {
            return num % 4 == 0 ? isPowerOfFour(num / 4) : false;
        }
    }
};
// @lc code=end
