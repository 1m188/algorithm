/*
 * @lc app=leetcode.cn id=3114 lang=cpp
 *
 * [3114] 替换字符可以得到的最晚时间
 *
 * https://leetcode.cn/problems/latest-time-you-can-obtain-after-replacing-characters/description/
 *
 * algorithms
 * Easy (39.98%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 16K
 * Testcase Example:  '"1?:?4"'
 *
 * 给你一个字符串 s，表示一个 12 小时制的时间格式，其中一些数字（可能没有）被 "?" 替换。
 *
 * 12 小时制时间格式为 "HH:MM" ，其中 HH 的取值范围为 00 至 11，MM 的取值范围为 00 至 59。最早的时间为
 * 00:00，最晚的时间为 11:59。
 *
 * 你需要将 s 中的 所有 "?" 字符替换为数字，使得结果字符串代表的时间是一个 有效 的 12 小时制时间，并且是可能的 最晚 时间。
 *
 * 返回结果字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： s = "1?:?4"
 *
 * 输出： "11:54"
 *
 * 解释： 通过替换 "?" 字符，可以得到的最晚12小时制时间是 "11:54"。
 *
 *
 * 示例 2：
 *
 *
 * 输入： s = "0?:5?"
 *
 * 输出： "09:59"
 *
 * 解释： 通过替换 "?" 字符，可以得到的最晚12小时制时间是 "09:59"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * s.length == 5
 * s[2] 是字符 ":"
 * 除 s[2] 外，其他字符都是数字或 "?"
 * 输入保证在替换 "?" 字符后至少存在一个介于 "00:00" 和 "11:59" 之间的时间。
 *
 *
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string findLatestTime(string s) {

        string hh = s.substr(0, 2);
        string mm = s.substr(3, 2);

        if (hh == "??")
            hh = "11";
        else if (hh[1] == '?') {
            if (hh[0] == '0')
                hh[1] = '9';
            else if (hh[0] == '1')
                hh[1] = '1';
            else
                hh[1] = '0';
        } else if (hh[0] == '?') {
            if (hh[1] == '0' || hh[1] == '1')
                hh[0] = '1';
            else
                hh[0] = '0';
        }

        if (mm == "??")
            mm = "59";
        else if (mm[1] == '?') {
            mm[1] = '9';
        } else if (mm[0] == '?') {
            mm[0] = '5';
        }

        return hh + ':' + mm;
    }
};
// @lc code=end
