/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (33.91%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 37.3K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    int countSegments(string s)
    {
        int num = 0;
        bool isStr = false;
        for (const char &c : s)
        {
            if (!isStr && c != ' ')
            {
                num++;
                isStr = true;
            }
            else if (c == ' ')
            {
                isStr = false;
            }
        }
        return num;
    }
};
// @lc code=end
