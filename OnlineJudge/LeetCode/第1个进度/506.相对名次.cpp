/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (53.49%)
 * Likes:    39
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 14K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */

#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<pair<int, string>> vec;
        for (const int &n : nums)
        {
            vec.push_back({n, ""});
        }
        sort(vec.begin(), vec.end(), [](const pair<int, string> &p1, const pair<int, string> &p2) { return p1.first > p2.first; });
        for (int i = 0; i < vec.size(); i++)
        {
            switch (i)
            {
            case 0:
                vec[i].second = "Gold Medal";
                break;
            case 1:
                vec[i].second = "Silver Medal";
                break;
            case 2:
                vec[i].second = "Bronze Medal";
                break;
            default:
                vec[i].second = to_string(i + 1);
            }
        }
        unordered_map<int, string> um(vec.begin(), vec.end());
        vector<string> res;
        for (const int &num : nums)
        {
            res.push_back(um[num]);
        }
        return res;
    }
};
// @lc code=end
