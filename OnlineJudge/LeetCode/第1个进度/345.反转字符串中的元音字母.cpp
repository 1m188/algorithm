/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (46.17%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    25K
 * Total Submissions: 50.8K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

#include "string"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        string vow = "aeiouAEIOU";
        int start = 0, end = s.size() - 1;
        while (end > start)
        {
            if (find(vow.begin(), vow.end(), s[start]) == vow.end())
            {
                start++;
                continue;
            }
            if (find(vow.begin(), vow.end(), s[end]) == vow.end())
            {
                end--;
                continue;
            }
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};
// @lc code=end
