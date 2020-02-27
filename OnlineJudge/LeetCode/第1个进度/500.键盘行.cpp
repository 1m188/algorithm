/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (68.25%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 21.2K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */

#include "vector"
#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> res;
        const vector<string> keyboard = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        for (const string &word : words)
        {
            string s;
            for (int i = 0; i < keyboard.size(); i++)
            {
                if (keyboard[i].find(word[0]) != string::npos)
                {
                    s = keyboard[i];
                    break;
                }
            }
            for (int i = 1; i < word.size(); i++)
            {
                if (s.find(word[i]) == string::npos)
                {
                    goto next;
                }
            }
            res.push_back(word);
        next:;
        }
        return res;
    }
};
// @lc code=end
