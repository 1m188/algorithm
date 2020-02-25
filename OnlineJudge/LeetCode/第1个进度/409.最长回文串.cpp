/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (52.04%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 30.9K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

#include "string"
#include "map"
using namespace std;

// @lc code=start
class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> m;
        for (const char &c : s)
        {
            if (m.find(c) == m.end())
            {
                m[c] = 1;
            }
            else
            {
                m[c]++;
            }
        }
        int len = 0;
        bool isOne = false;
        for (const auto &p : m)
        {
            len += p.second / 2 * 2;
            if (!isOne && p.second % 2 == 1)
            {
                len += 1;
                isOne = true;
            }
        }
        return len;
    }
};
// @lc code=end
