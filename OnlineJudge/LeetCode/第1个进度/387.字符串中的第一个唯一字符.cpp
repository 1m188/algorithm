/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (37.03%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    61.3K
 * Total Submissions: 141.5K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */

#include "string"
#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        vector<pair<char, int>> vec;
        for (int i = 0; i < s.size(); i++)
        {
            auto it = find_if(vec.begin(), vec.end(), [&](const pair<char, int> &p) { return p.first == s[i]; });
            if (it == vec.end())
            {
                vec.push_back({s[i], i});
            }
            else
            {
                it->second = -1;
            }
        }
        int index = -1;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].second != -1)
            {
                index = vec[i].second;
                break;
            }
        }
        return index;
    }
};
// @lc code=end
