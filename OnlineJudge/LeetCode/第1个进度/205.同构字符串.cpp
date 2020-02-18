/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (43.24%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 58.9K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */

#include "string"
#include "map"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // AC
        auto map1 = map<char, char>();
        auto map2 = map<char, char>();
        for (int i = 0; i < s.size(); i++)
        {
            auto it1 = map1.find(s[i]);
            auto it2 = map2.find(t[i]);
            if (it1 == map1.end() && it2 == map2.end())
            {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else
            {
                if (it1->second != t[i] || it2->second != s[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
