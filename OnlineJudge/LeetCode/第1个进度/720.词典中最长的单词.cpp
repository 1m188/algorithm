/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (44.97%)
 * Likes:    66
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 13.4K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 
 * 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
 * 
 * 若无答案，则返回空字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * words = ["w","wo","wor","worl", "world"]
 * 输出: "world"
 * 解释: 
 * 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出: "apple"
 * 解释: 
 * "apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
 * 
 * 
 * 注意:
 * 
 * 
 * 所有输入的字符串都只包含小写字母。
 * words数组长度范围为[1,1000]。
 * words[i]的长度范围为[1,30]。
 * 
 * 
 */

#include "vector"
#include "string"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string res;
        sort(words.begin(), words.end());
        for (const string &s : words)
        {
            string prefix;
            for (int i = 0; i < s.size(); i++)
            {
                prefix.push_back(s[i]);
                if (find(words.begin(), words.end(), prefix) == words.end())
                {
                    goto next;
                }
            }
            if (s.size() > res.size())
            {
                res = s;
            }
            else if (s.size() == res.size())
            {
                res = min(res, s);
            }
        next:;
        }
        return res;
    }
};
// @lc code=end
