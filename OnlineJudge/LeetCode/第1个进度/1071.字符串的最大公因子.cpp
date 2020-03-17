/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 *
 * https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (49.79%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 40.4K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * 对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
 * 
 * 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：str1 = "ABCABC", str2 = "ABC"
 * 输出："ABC"
 * 
 * 
 * 示例 2：
 * 
 * 输入：str1 = "ABABAB", str2 = "ABAB"
 * 输出："AB"
 * 
 * 
 * 示例 3：
 * 
 * 输入：str1 = "LEET", str2 = "CODE"
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= str1.length <= 1000
 * 1 <= str2.length <= 1000
 * str1[i] 和 str2[i] 为大写英文字母
 * 
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
private:
    int gcd(int a, int b)
    {
        int c = a % b;
        while (c)
        {
            a = b;
            b = c;
            c = a % b;
        }
        return b;
    }

public:
    string gcdOfStrings(string str1, string str2)
    {
        string res;
        if (str1 + str2 == str2 + str1)
        {
            int size = gcd(str1.size(), str2.size());
            res = str1.substr(0, size);
        }
        return res;
    }
};
// @lc code=end
