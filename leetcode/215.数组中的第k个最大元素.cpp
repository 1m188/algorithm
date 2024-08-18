/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.69%)
 * Likes:    649
 * Dislikes: 0
 * Total Accepted:    183K
 * Total Submissions: 284.3K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    template <typename T>
    void adjust_heap(vector<T> &vec, int left, int right)
    {
        T tmp = vec[left];
        int m = left * 2 + 1;
        while (m <= right)
        {
            if (m + 1 <= right && vec[m + 1] > vec[m])
                m++;
            if (vec[m] > tmp)
            {
                vec[left] = vec[m];
                left = m;
                m = left * 2 + 1;
            }
            else
                break;
        }
        vec[left] = tmp;
    }

public:
    int findKthLargest(vector<int> &nums, int k)
    {
        for (int i = (nums.size() - 2) / 2; i >= 0; i--)
            adjust_heap(nums, i, nums.size() - 1);
        swap(nums.front(), nums.back());

        for (int i = 1; i < k; i++)
        {
            adjust_heap(nums, 0, nums.size() - 1 - i);
            swap(nums[0], nums[nums.size() - 1 - i]);
        }

        return nums[nums.size() - k];
    }
};
// @lc code=end
