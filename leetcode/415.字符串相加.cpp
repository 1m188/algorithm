/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.55%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 48.6K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string *longStr, *shortStr;
        if (num1.size() > num2.size())
        {
            longStr = &num1;
            shortStr = &num2;
        }
        else
        {
            longStr = &num2;
            shortStr = &num1;
        }

        auto lit = longStr->end() - 1;
        auto sit = shortStr->end() - 1;
        bool bit = false;
        string res;
        while (sit >= shortStr->begin())
        {
            int x = *sit - '0' + *lit - '0' + bit;
            bit = x >= 10;
            x %= 10;
            res.insert(res.begin(), x + '0');
            sit--;
            lit--;
        }
        while (lit >= longStr->begin())
        {
            int x = *lit - '0' + bit;
            bit = x >= 10;
            x %= 10;
            res.insert(res.begin(), x + '0');
            lit--;
        }
        if (bit)
        {
            res.insert(res.begin(), bit + '0');
        }
        return res;
    }
};
// @lc code=end
