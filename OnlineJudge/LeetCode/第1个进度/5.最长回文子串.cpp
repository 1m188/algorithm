/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.04%)
 * Likes:    1910
 * Dislikes: 0
 * Total Accepted:    216.1K
 * Total Submissions: 742.3K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

#include "string"
using namespace std;

// @lc code=start
class Solution
{
private:
    bool isRev(const string &str, int left, int right)
    {
        while (left < right)
        {
            if (str[left++] != str[right--])
            {
                return false;
            }
        }
        return true;
    }

public:
    string longestPalindrome(string s)
    {
        int start = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = s.size(); j > i; j--)
            {
                if (isRev(s, i, j - 1))
                {
                    if (len < j - i)
                    {
                        start = i, len = j - i;
                    }
                    break;
                }
            }
        }
        return s.substr(start, len);
    }
};
// @lc code=end
