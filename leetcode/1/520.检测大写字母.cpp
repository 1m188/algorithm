/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 *
 * https://leetcode-cn.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (54.55%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 28.1K
 * Testcase Example:  '"USA"'
 *
 * 给定一个单词，你需要判断单词的大写使用是否正确。
 * 
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如"USA"。
 * 单词中所有字母都不是大写，比如"leetcode"。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
 * 
 * 
 * 否则，我们定义这个单词没有正确使用大写字母。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "USA"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "FlaG"
 * 输出: False
 * 
 * 
 * 注意: 输入是由大写和小写拉丁字母组成的非空单词。
 * 
 */

#include "string"
#include "cctype"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() == 1)
        {
            return true;
        }

        if (islower(word[0]))
        {
            for (int i = 1; i < word.size(); i++)
            {
                if (isupper(word[i]))
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            if (isupper(word[1]))
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (islower(word[i]))
                    {
                        return false;
                    }
                }
                return true;
            }
            else
            {
                for (int i = 2; i < word.size(); i++)
                {
                    if (isupper(word[i]))
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
};
// @lc code=end
