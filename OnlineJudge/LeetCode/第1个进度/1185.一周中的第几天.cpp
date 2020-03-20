/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 *
 * https://leetcode-cn.com/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (58.26%)
 * Likes:    17
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 8.1K
 * Testcase Example:  '31\n8\n2019'
 *
 * 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
 * 
 * 输入为三个整数：day、month 和 year，分别表示日、月、年。
 * 
 * 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
 * "Friday", "Saturday"}。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：day = 31, month = 8, year = 2019
 * 输出："Saturday"
 * 
 * 
 * 示例 2：
 * 
 * 输入：day = 18, month = 7, year = 1999
 * 输出："Sunday"
 * 
 * 
 * 示例 3：
 * 
 * 输入：day = 15, month = 8, year = 1993
 * 输出："Sunday"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给出的日期一定是在 1971 到 2100 年之间的有效日期。
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
    const vector<string> weekDays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const int startWeekDaysIndex = 4;
    const int startYear = 1971;
    const int startMonth = 1;
    const int startDay = 1;
    vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeapYear(const int year) const
    {
        if (year <= 0)
        {
            return false;
        }

        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int days = 0;
        for (int i = startYear; i < year; i++)
        {
            days += isLeapYear(i) ? 366 : 365;
        }
        monthDays[1] = isLeapYear(year) ? 29 : 28;
        for (int i = startMonth; i < month; i++)
        {
            days += monthDays[i - 1];
        }
        days += day - startDay;
        days %= 7;
        return weekDays[(days + startWeekDaysIndex) % 7];
    }
};
// @lc code=end
