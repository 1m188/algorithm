/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (40.12%)
 * Likes:    554
 * Dislikes: 0
 * Total Accepted:    122.3K
 * Total Submissions: 304.5K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    int bs(const vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return mid;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!nums.empty())
        {
            int idx = bs(nums, target);
            if (nums[idx] == target)
            {
                int left = idx, right = idx;
                while (left >= 0 && nums[left] == target)
                    left--;
                while (right < nums.size() && nums[right] == target)
                    right++;
                return {left + 1, right - 1};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
