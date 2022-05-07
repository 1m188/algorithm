/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 *
 * https://leetcode-cn.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (63.14%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 12.8K
 * Testcase Example:  '"nlaebolko"'
 *
 * 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
 * 
 * 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：text = "nlaebolko"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：text = "loonbalxballpoon"
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：text = "leetcode"
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 10^4
 * text 全部由小写英文字母组成
 * 
 * 
 */

#include "string"
#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
private:
    const string target = "balloon";

public:
    int maxNumberOfBalloons(string text)
    {
        if (text.size() < target.size())
        {
            return 0;
        }

        vector<int> vec(26, 0);
        for (const char &c : text)
        {
            vec[c - 'a']++;
        }

        int num = 1e4 + 1;
        for (const char &c : target)
        {
            int n = vec[c - 'a'];
            if (c == 'l' || c == 'o')
            {
                n /= 2;
            }
            num = min(num, n);
        }
        return num;
    }
};
// @lc code=end
