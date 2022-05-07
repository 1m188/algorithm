/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (33.46%)
 * Likes:    3332
 * Dislikes: 0
 * Total Accepted:    396.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */

#include "string"
#include "unordered_set"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0, i = 0, j = 0, n = s.size();
        unordered_set<char> us;
        while (i < n && j < n)
        {
            if (us.find(s[j]) == us.end())
            {
                us.insert(s[j++]);
                res = max(res, j - i);
            }
            else
            {
                us.erase(s[i++]);
            }
        }
        return res;
    }
};
// @lc code=end
