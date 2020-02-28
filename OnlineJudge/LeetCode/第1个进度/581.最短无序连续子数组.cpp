/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (34.04%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    18.9K
 * Total Submissions: 55.5K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */

#include "vector"
#include "algorithm"
#include "limits"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        // left和right分别代表最短子数组的左边界索引和有边界索引
        int left = 0, right = 0;
        // 首先将左右两边按照升序找出最长的排列，更新索引
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                left = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] < nums[i - 1])
            {
                right = i;
                break;
            }
        }
        // 已经排好序
        if (left >= right)
        {
            return 0;
        }

        // 获取子数组中的最大值和最小值，并且对其进行左更新和右更新
        bool lu = true, lr = true;
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for (int i = left; i <= right; i++)
        {
            minval = min(nums[i], minval);
            maxval = max(nums[i], maxval);
        }
        // 一旦更新了左边或者右边相应的最大值和最小值就会改变，因此一旦更新一边另一边也需要判断更新
        while (lu || lr)
        {
            lu = false, lr = false;

            // 判断左边的最大值是否小于等于子数组中的最小值
            if (left > 0 && nums[left - 1] > minval)
            {
                left--;
                minval = min(minval, nums[left]);
                lu = true;
            }

            // 判断右边的最小值是否大于等于子数组的最大值
            if (right < nums.size() - 1 && nums[right + 1] < maxval)
            {
                right++;
                maxval = max(maxval, nums[right]);
                lr = true;
            }
        }

        return right - left + 1;
    }
};
// @lc code=end
