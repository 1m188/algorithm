/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 *
 * https://leetcode-cn.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (66.44%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 15.6K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
 * 
 * 示例 1:
 * 
 * 
 * 输入: S = "loveleetcode", C = 'e'
 * 输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 说明:
 * 
 * 
 * 字符串 S 的长度范围为 [1, 10000]。
 * C 是一个单字符，且保证是字符串 S 里的字符。
 * S 和 C 中的所有字母均为小写字母。
 * 
 * 
 */

#include "vector"
#include "string"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> vec;
        for (int i = 0; i < S.size(); i++)
        {
            int distr = -1, distl = -1;
            for (int j = i; j < S.size(); j++)
            {
                if (S[j] == C)
                {
                    distr = j - i;
                    break;
                }
            }
            for (int j = i; j >= 0; j--)
            {
                if (S[j] == C)
                {
                    distl = i - j;
                    break;
                }
            }
            if (distr == -1 || distl == -1)
            {
                vec.push_back(distr == -1 ? distl : distr);
            }
            else
            {
                vec.push_back(min(distr, distl));
            }
        }
        return vec;
    }
};
// @lc code=end
