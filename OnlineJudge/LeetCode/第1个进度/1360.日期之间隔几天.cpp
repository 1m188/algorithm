/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 *
 * https://leetcode-cn.com/problems/number-of-days-between-two-dates/description/
 *
 * algorithms
 * Easy (44.42%)
 * Likes:    13
 * Dislikes: 0
 * Total Accepted:    3.1K
 * Total Submissions: 7K
 * Testcase Example:  '"2019-06-29"\n"2019-06-30"'
 *
 * 请你编写一个程序来计算两个日期之间隔了多少天。
 * 
 * 日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date1 = "2019-06-29", date2 = "2019-06-30"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：date1 = "2020-01-15", date2 = "2019-12-31"
 * 输出：15
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的日期是 1971 年到 2100 年之间的有效日期。
 * 
 * 
 */

#include "string"
#include "cmath"
using namespace std;

// @lc code=start
class Solution
{
private:
    int toDay(const string &date)
    {
        int year = 0, month = 0, day = 0;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        if (month <= 2)
        {
            year--;
            month += 10;
        }
        else
        {
            month -= 2;
        }
        return 365 * year + year / 4 - year / 100 + year / 400 + 30 * month + (3 * month - 1) / 5 + day - 584418;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        return abs(toDay(date1) - toDay(date2));
    }
};
// @lc code=end
