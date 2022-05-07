/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (45.39%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 17.7K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */

#include "vector"
#include "map"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int res = 0;
        map<int, int> m;
        for (const int &num : nums)
        {
            if (m.find(num) == m.end())
            {
                m[num] = 1;
            }
            else
            {
                m[num]++;
            }
        }
        auto cit = m.cbegin();
        auto citt = cit;
        citt++;
        while (citt != m.cend())
        {
            if (citt->first - cit->first == 1)
            {
                res = max(res, citt->second + cit->second);
            }
            cit++;
            citt++;
        }
        return res;
    }
};
// @lc code=end
