/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 *
 * https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (32.92%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 28.6K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * 给定一副牌，每张牌上都写着一个整数。
 * 
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 
 * 
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * 
 * 
 * 仅当你可选的 X >= 2 时返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4,4,3,2,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,1,1,2,2,2,3,3]
 * 输出：false
 * 解释：没有满足要求的分组。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1]
 * 输出：false
 * 解释：没有满足要求的分组。
 * 
 * 
 * 示例 4：
 * 
 * 输入：[1,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]
 * 
 * 
 * 示例 5：
 * 
 * 输入：[1,1,2,2,2,2]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[2,2]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= deck.length <= 10000
 * 0 <= deck[i] < 10000
 * 
 * 
 * 
 * 
 */

#include "vector"
#include "unordered_map"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        if (deck.size() < 2)
        {
            return false;
        }

        unordered_map<int, int> um;
        for (const int &d : deck)
        {
            um[d]++;
        }

        vector<pair<int, int>> vec(um.begin(), um.end());
        sort(vec.begin(), vec.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) { return p1.second < p2.second; });
        if (vec[0].second < 2)
        {
            return false;
        }

        for (int i = 2; i <= vec[0].second; i++)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (vec[j].second % i != 0)
                {
                    goto next;
                }
            }
            return true;
        next:;
        }
        return false;
    }
};
// @lc code=end
