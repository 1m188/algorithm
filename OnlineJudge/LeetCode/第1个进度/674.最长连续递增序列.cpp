/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (43.91%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    17.5K
 * Total Submissions: 39.8K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且连续的的递增序列。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 3
 * 解释: 最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 1
 * 解释: 最长连续递增序列是 [2], 长度为1。
 * 
 * 
 * 注意：数组长度不会超过10000。
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        else
        {
            int len = 0;
            int start = 0;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i] <= nums[i - 1])
                {
                    len = max(len, i - start);
                    start = i;
                }
            }
            len = max(len, static_cast<int>(nums.size() - start));
            return len;
        }
    }
};
// @lc code=end
