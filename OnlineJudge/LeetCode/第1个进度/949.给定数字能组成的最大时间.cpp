/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 *
 * https://leetcode-cn.com/problems/largest-time-for-given-digits/description/
 *
 * algorithms
 * Easy (34.89%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 10.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。
 * 
 * 最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。
 * 
 * 以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4]
 * 输出："23:41"
 * 
 * 
 * 示例 2：
 * 
 * 输入：[5,5,5,5]
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length == 4
 * 0 <= A[i] <= 9
 * 
 * 
 */

#include "string"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    string res;
    string s;
    vector<bool> flag = vector<bool>(4, false);
    vector<int> tnum;
    bool judge(const string &s)
    {
        if (!(s[0] >= '0' && s[0] <= '2'))
        {
            return false;
        }
        if (!((s[0] == '2' && s[1] >= '0' && s[1] <= '3') || (s[0] != '2' && s[1] >= '0' && s[1] <= '9')))
        {
            return false;
        }
        if (!(s[2] >= '0' && s[2] <= '5' && s[3] >= '0' && s[3] <= '9'))
        {
            return false;
        }
        return true;
    }
    void buildTime()
    {
        if (s.size() == 4)
        {
            if (judge(s) && s > res)
            {
                res = s;
            }
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            if (!flag[i])
            {
                flag[i] = true;
                s.push_back(tnum[i] + '0');
                buildTime();
                s.pop_back();
                flag[i] = false;
            }
        }
    }

public:
    string largestTimeFromDigits(vector<int> &A)
    {
        tnum = A;
        buildTime();
        if (!res.empty())
        {
            res.insert(res.begin() + 2, ':');
        }
        return res;
    }
};
// @lc code=end
