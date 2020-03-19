/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 *
 * https://leetcode-cn.com/problems/day-of-the-year/description/
 *
 * algorithms
 * Easy (52.61%)
 * Likes:    16
 * Dislikes: 0
 * Total Accepted:    5.7K
 * Total Submissions: 10.8K
 * Testcase Example:  '"2019-01-09"\r'
 *
 * 给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。
 * 
 * 通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2
 * 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date = "2019-01-09"
 * 输出：9
 * 
 * 
 * 示例 2：
 * 
 * 输入：date = "2019-02-10"
 * 输出：41
 * 
 * 
 * 示例 3：
 * 
 * 输入：date = "2003-03-01"
 * 输出：60
 * 
 * 
 * 示例 4：
 * 
 * 输入：date = "2004-03-01"
 * 输出：61
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * date.length == 10
 * date[4] == date[7] == '-'，其他的 date[i] 都是数字。
 * date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。
 * 
 * 
 */

#include "string"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    int dayOfYear(string date)
    {
        vector<int> vec;
        string str;
        for (const char &c : date)
        {
            if (c != '-')
            {
                str.push_back(c);
            }
            else
            {
                vec.push_back(stoi(str));
                str.clear();
            }
        }
        vec.push_back(stoi(str));

        vector<int> mondays{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((vec[0] % 4 == 0 && vec[0] % 100 != 0) || vec[0] % 400 == 0)
        {
            mondays[1] = 29;
        }

        int res = 0;
        for (int i = 0; i < vec[1] - 1; i++)
        {
            res += mondays[i];
        }
        res += vec[2];
        return res;
    }
};
// @lc code=end
