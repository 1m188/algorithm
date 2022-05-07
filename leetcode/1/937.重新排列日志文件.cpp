/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 *
 * https://leetcode-cn.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (52.07%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 7.1K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * 你有一个日志数组 logs。每条日志都是以空格分隔的字串。
 * 
 * 对于每条日志，其第一个字为字母数字标识符。然后，要么：
 * 
 * 
 * 标识符后面的每个字将仅由小写字母组成，或；
 * 标识符后面的每个字将仅由数字组成。
 * 
 * 
 * 我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。
 * 
 * 将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按内容字母顺序排序，忽略标识符；在内容相同时，按标识符排序。数字日志应该按原来的顺序排列。
 * 
 * 返回日志的最终顺序。
 * 
 * 
 * 
 * 示例 ：
 * 
 * 输入：["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
 * 输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] 保证有一个标识符，并且标识符后面有一个字。
 * 
 * 
 */

#include "vector"
#include "string"
#include "cctype"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        if (logs.empty())
        {
            return logs;
        }
        else
        {
            vector<string> alphaLogs, numLogs;
            for (const string &log : logs)
            {
                int index = log.find(' ');
                if (isalpha(log[index + 1]))
                {
                    alphaLogs.push_back(log);
                }
                else
                {
                    numLogs.push_back(log);
                }
            }
            sort(alphaLogs.begin(), alphaLogs.end(), [](const string &s1, const string &s2) {
                string &&sub1 = s1.substr(s1.find(' ') + 1);
                string &&sub2 = s2.substr(s2.find(' ') + 1);
                if (sub1 != sub2)
                {
                    return sub1 < sub2;
                }
                else
                {
                    sub1 = s1.substr(0, s1.find(' '));
                    sub2 = s2.substr(0, s2.find(' '));
                    return sub1 < sub2;
                }
            });
            for (const string numLog : numLogs)
            {
                alphaLogs.push_back(numLog);
            }
            return alphaLogs;
        }
    }
};
// @lc code=end
