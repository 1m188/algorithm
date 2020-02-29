/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (35.43%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 39K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
private:
    bool judge(string s, int start, int end)
    {
        while (end > start)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

public:
    bool validPalindrome(string s)
    {
        int start = 0, end = s.size() - 1;
        bool isDel = false;
        while (end > start)
        {
            if (s[start] != s[end])
            {
                isDel = true;
                return judge(s, start + 1, end) || judge(s, start, end - 1);
            }
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end
