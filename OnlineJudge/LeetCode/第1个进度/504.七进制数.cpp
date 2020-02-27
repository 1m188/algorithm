/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (48.15%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    9.2K
 * Total Submissions: 19K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }

        unsigned n = num;
        if (num < 0)
        {
            n = ~(unsigned)num + 1;
        }
        string res;
        while (n)
        {
            res.insert(res.begin(), n % 7 + '0');
            n /= 7;
        }
        if (num < 0)
        {
            res.insert(res.begin(), '-');
        }
        return res;
    }
};
// @lc code=end
