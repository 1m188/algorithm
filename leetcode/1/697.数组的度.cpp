/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (51.72%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 22.6K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1, 2, 2, 3, 1]
 * 输出: 2
 * 解释: 
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,2,3,1,4,2]
 * 输出: 6
 * 
 * 
 * 注意:
 * 
 * 
 * nums.length 在1到50,000区间范围内。
 * nums[i] 是一个在0到49,999范围内的整数。
 * 
 * 
 */

#include "vector"
#include "unordered_map"
#include "algorithm"
#include "limits"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> um;
        for (const int &n : nums)
        {
            if (um.find(n) == um.end())
            {
                um[n] = 1;
            }
            else
            {
                um[n]++;
            }
        }
        vector<pair<int, int>> vec(um.begin(), um.end());
        sort(vec.begin(), vec.end(), [](const auto &p1, const auto &p2) { return p1.second < p2.second; });
        for (auto it = vec.begin(); it < vec.end(); it++)
        {
            if (it->second != vec.back().second)
            {
                vec.erase(it);
                it--;
            }
        }
        int res = INT_MAX;
        for (const auto &p : vec)
        {
            int target = p.first;
            int freq = p.second;
            int start = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == target)
                {
                    start = i;
                    freq--;
                    break;
                }
            }
            int end = start + 1;
            while (freq > 0)
            {
                if (nums[end] == target)
                {
                    freq--;
                }
                end++;
            }
            res = min(res, end - start);
        }
        return res;
    }
};
// @lc code=end
