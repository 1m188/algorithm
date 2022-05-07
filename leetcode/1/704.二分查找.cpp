/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 *
 * https://leetcode-cn.com/problems/binary-search/description/
 *
 * algorithms
 * Easy (52.47%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 59.8K
 * Testcase Example:  '[-1,0,3,5,9,12]\n9'
 *
 * 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的
 * target，如果目标值存在返回下标，否则返回 -1。
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [-1,0,3,5,9,12], target = 9
 * 输出: 4
 * 解释: 9 出现在 nums 中并且下标为 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [-1,0,3,5,9,12], target = 2
 * 输出: -1
 * 解释: 2 不存在 nums 中因此返回 -1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 nums 中的所有元素是不重复的。
 * n 将在 [1, 10000]之间。
 * nums 的每个元素都将在 [-9999, 9999]之间。
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size();
        while (end > start)
        {
            int mid = (start + end) / 2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                break;
            }
        }
        int mid = (start + end) / 2;
        if (mid < 0 || mid >= nums.size())
        {
            return -1;
        }
        else
        {
            return nums[mid] == target ? mid : -1;
        }
    }
};
// @lc code=end
