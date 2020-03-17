/*
 * @lc app=leetcode.cn id=1078 lang=cpp
 *
 * [1078] Bigram 分词
 *
 * https://leetcode-cn.com/problems/occurrences-after-bigram/description/
 *
 * algorithms
 * Easy (60.53%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 8.6K
 * Testcase Example:  '"alice is a good girl she is a good student"\n"a"\n"good"'
 *
 * 给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中
 * second 紧随 first 出现，third 紧随 second 出现。
 * 
 * 对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：text = "alice is a good girl she is a good student", first = "a", second
 * = "good"
 * 输出：["girl","student"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：text = "we will we will rock you", first = "we", second = "will"
 * 输出：["we","rock"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 1000
 * text 由一些用空格分隔的单词组成，每个单词都由小写英文字母组成
 * 1 <= first.length, second.length <= 10
 * first 和 second 由小写英文字母组成
 * 
 * 
 */

#include "vector"
#include "string"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> findOcurrences(string text, string first, string second)
    {
        vector<string> res, words;
        text.push_back(' ');
        string str;
        for (const char &c : text)
        {
            if (c != ' ')
            {
                str.push_back(c);
            }
            else
            {
                words.push_back(str);
                str.clear();
            }
        }
        for (int i = 0; i < words.size() - 2; i++)
        {
            if (words[i] == first && words[i + 1] == second)
            {
                res.push_back(words[i + 2]);
            }
        }
        return res;
    }
};
// @lc code=end
