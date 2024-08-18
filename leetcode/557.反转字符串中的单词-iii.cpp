/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (69.40%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    43.3K
 * Total Submissions: 62.3K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */

#include "string"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        auto startit = s.begin();
        auto endit = s.begin();
        while (endit < s.end())
        {
            if (*endit == ' ')
            {
                reverse(startit, endit);
                startit = endit + 1;
            }
            endit++;
        }
        reverse(startit, endit);
        return s;
    }
};
// @lc code=end
