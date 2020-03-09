/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 *
 * https://leetcode-cn.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (53.24%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 17.8K
 * Testcase Example:  '"ab-cd"'
 *
 * 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 示例 2：
 * 
 * 输入："a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 示例 3：
 * 
 * 输入："Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S 中不包含 \ or "
 * 
 * 
 */

#include "string"
#include "cctype"
using namespace std;

// @lc code=start
class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        if (S.size() > 0)
        {
            int start = 0, end = S.size() - 1;
            while (end > start)
            {
                if (isalpha(S[start]) && isalpha(S[end]))
                {
                    swap(S[start], S[end]);
                    start++;
                    end--;
                }
                else
                {
                    if (!isalpha(S[start]))
                    {
                        start++;
                    }
                    if (!isalpha(S[end]))
                    {
                        end--;
                    }
                }
            }
        }
        return S;
    }
};
// @lc code=end
