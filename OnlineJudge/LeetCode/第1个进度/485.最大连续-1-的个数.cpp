/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (55.74%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 52K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int calc = 0;
        for (const int &num : nums)
        {
            if (num)
            {
                calc++;
            }
            else
            {
                if (calc > res)
                {
                    res = calc;
                }
                calc = 0;
            }
        }
        if (calc > res)
        {
            res = calc;
        }
        return res;
    }
};
// @lc code=end
