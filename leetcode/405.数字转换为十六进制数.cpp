/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 *
 * https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (49.81%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 17.2K
 * Testcase Example:  '26'
 *
 * 给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。
 * 
 * 注意:
 * 
 * 
 * 十六进制中所有字母(a-f)都必须是小写。
 * 
 * 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，十六进制字符串中的第一个字符将不会是0字符。 
 * 给定的数确保在32位有符号整数范围内。
 * 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:
 * 26
 * 
 * 输出:
 * "1a"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入:
 * -1
 * 
 * 输出:
 * "ffffffff"
 * 
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        else
        {
            string alph = "0123456789abcdef";
            if (num < 0)
            {
                num = ~(-num) + 1;
            }
            unsigned int n = num;
            string res;
            while (n)
            {
                int x = n % 16;
                res.insert(res.begin(), alph[x]);
                n /= 16;
            }
            return res;
        }
    }
};
// @lc code=end
