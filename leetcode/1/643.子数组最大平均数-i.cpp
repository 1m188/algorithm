/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode-cn.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (37.78%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 29.9K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 * 
 * 示例 1:
 * 
 * 输入: [1,12,-5,-6,50,3], k = 4
 * 输出: 12.75
 * 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 1 <= k <= n <= 30,000。
 * 所给数据范围 [-10,000，10,000]。
 * 
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        if (nums.size() < k)
        {
            return 0;
        }

        double sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        int start = 0;
        double tmp = sum;
        while (start + k < nums.size())
        {
            tmp = tmp - nums[start] + nums[start + k];
            sum = max(sum, tmp);
            start++;
        }
        return sum / k;
    }
};
// @lc code=end
