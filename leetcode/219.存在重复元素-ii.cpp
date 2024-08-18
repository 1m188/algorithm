/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (33.86%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    34.2K
 * Total Submissions: 90.9K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j
 * 的差的绝对值最大为 k。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */

#include "vector"
#include "cmath"
#include "map"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        // AC
        auto m = map<int, vector<int>>();
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = m.find(nums[i]);
            if (it == m.end())
            {
                m[nums[i]] = vector<int>{i};
            }
            else
            {
                for (const int &index : it->second)
                {
                    if (abs(index - i) <= k)
                    {
                        return true;
                    }
                }
                it->second.push_back(i);
            }
        }
        return false;
    }
};
// @lc code=end
