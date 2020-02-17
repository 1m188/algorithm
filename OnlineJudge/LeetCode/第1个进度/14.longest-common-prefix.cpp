/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (31.70%)
 * Total Accepted:    49.5K
 * Total Submissions: 156.2K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }
        else
        {
            string s;
            int index = 0;
            while (true)
            {
                for (auto cit = strs.cbegin(); cit != strs.cend() - 1; cit++)
                {
                    if ((*cit)[index] != (*(cit + 1))[index])
                    {
                        goto outside;
                    }
                }
                s.push_back(strs[0][index]);
                index++;
                for (auto cit = strs.cbegin(); cit != strs.cend(); cit++)
                {
                    if (index >= cit->size())
                    {
                        goto outside;
                    }
                }
            }
        outside:
            return s;
        }
    }
};

// #include "vector"
// #include "string"
// using namespace std;
