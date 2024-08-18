/*
 * @lc app=leetcode.cn id=3174 lang=cpp
 *
 * [3174] 清除数字
 *
 * https://leetcode.cn/problems/clear-digits/description/
 *
 * algorithms
 * Easy (78.23%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    3.4K
 * Total Submissions: 4.3K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s 。
 *
 * 你的任务是重复以下操作删除 所有 数字字符：
 *
 *
 * 删除 第一个数字字符 以及它左边 最近 的 非数字 字符。
 *
 *
 * 请你返回删除所有数字字符以后剩下的字符串。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "abc"
 *
 * 输出："abc"
 *
 * 解释：
 *
 * 字符串中没有数字。
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cb34"
 *
 * 输出：""
 *
 * 解释：
 *
 * 一开始，我们对 s[2] 执行操作，s 变为 "c4" 。
 *
 * 然后对 s[1] 执行操作，s 变为 "" 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 100
 * s 只包含小写英文字母和数字字符。
 * 输入保证所有数字都可以按以上操作被删除。
 *
 *
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string clearDigits(string s) {

        auto ISDIGIT = [=](char ch) { return ch >= '0' && ch <= '9'; };

        int i = 0;
        while (i < s.size()) {
            if (!ISDIGIT(s[i])) {
                i++;
                continue;
            }

            s.erase(s.begin() + i);
            int j = i - 1;
            if (j < 0) continue;
            s.erase(s.begin() + j);
            i = j;
        }

        return std::move(s);
    }
};
// @lc code=end
