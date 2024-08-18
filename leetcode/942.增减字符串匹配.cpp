/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (71.19%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 17.4K
 * Testcase Example:  '"IDID"'
 *
 * 给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
 * 
 * 返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：
 * 
 * 
 * 如果 S[i] == "I"，那么 A[i] < A[i+1]
 * 如果 S[i] == "D"，那么 A[i] > A[i+1]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出："IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 输出："III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 输出："DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 1000
 * S 只包含字符 "I" 或 "D"。
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
    vector<int> diStringMatch(string S)
    {
        vector<int> res;
        int maxNum = S.size(), minNum = 0;
        for (const char &s : S)
        {
            if (s == 'I')
            {
                res.push_back(minNum++);
            }
            else
            {
                res.push_back(maxNum--);
            }
        }
        res.push_back(minNum);
        return res;
    }
};
// @lc code=end
