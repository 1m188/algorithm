/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词模式
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (37.94%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 42K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

#include "string"
#include "map"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        vector<string> vec{""};
        for (const char &c : str)
        {
            if (c == ' ')
            {
                vec.push_back("");
            }
            else
            {
                vec.back().push_back(c);
            }
        }

        if (vec.size() != pattern.size())
        {
            return false;
        }

        map<char, string> pvm;
        map<string, char> vpm;
        for (int i = 0; i < pattern.size(); i++)
        {
            char p = pattern[i];
            string s = vec[i];
            auto pvit = pvm.find(p);
            auto vpit = vpm.find(s);
            if (pvit == pvm.end() && vpit == vpm.end())
            {
                pvm[p] = s;
                vpm[s] = p;
            }
            else if (pvit != pvm.end() && vpit != vpm.end())
            {
                if (pvit->second != s || vpit->second != p)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
