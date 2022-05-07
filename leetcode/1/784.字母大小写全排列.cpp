/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 *
 * https://leetcode-cn.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (62.79%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 22.9K
 * Testcase Example:  '"a1b2"'
 *
 * 给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
 * 
 * 
 * 示例:
 * 输入: S = "a1b2"
 * 输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * 输入: S = "3z4"
 * 输出: ["3z4", "3Z4"]
 * 
 * 输入: S = "12345"
 * 输出: ["12345"]
 * 
 * 
 * 注意：
 * 
 * 
 * S 的长度不超过12。
 * S 仅由数字和字母组成。
 * 
 * 
 */

#include "vector"
#include "string"
#include "cctype"
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<string> vec;
    string str;
    void trans(int index = 0)
    {
        if (index >= str.size())
        {
            vec.push_back(str);
        }
        else
        {
            trans(index + 1);
            if (isalpha(str[index]))
            {
                if (isupper(str[index]))
                {
                    str[index] = tolower(str[index]);
                }
                else
                {
                    str[index] = toupper(str[index]);
                }
                trans(index + 1);
            }
        }
    }

public:
    vector<string> letterCasePermutation(string S)
    {
        if (S.size() == 0)
        {
            return vec;
        }

        str = S;
        trans();
        return vec;
    }
};
// @lc code=end
