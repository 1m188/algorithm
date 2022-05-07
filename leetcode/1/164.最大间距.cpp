/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode-cn.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (54.63%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 31.3K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
 * 
 * 如果数组元素个数小于 2，则返回 0。
 * 
 * 示例 1:
 * 
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 * 
 * 示例 2:
 * 
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
 * 
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

    template <typename T>
    void heapSort(vector<T> &vec)
    {
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            adjust_heap(vec, i, vec.size() - 1);
        for (int i = vec.size() - 1; i >= 1; i--)
            swap(vec[0], vec[i]), adjust_heap(vec, 0, i - 1);
    }

    template <typename T>
    void quickSort(vector<T> &vec, int left, int right)
    {
        if (left >= right)
            return;

        int low = left, high = right;
        T tmp = vec[low];
        while (low < high)
        {
            while (low < high && vec[high] >= tmp)
                high--;
            if (low < high)
                vec[low++] = vec[high];
            while (low < high && vec[low] <= tmp)
                low++;
            if (low < high)
                vec[high--] = vec[low];
        }
        vec[low] = tmp;
        quickSort(vec, left, low - 1);
        quickSort(vec, low + 1, right);
    }

public:
    int maximumGap(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        // heapSort(nums);
        quickSort(nums, 0, nums.size() - 1);

        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i + 1] - nums[i] > res)
                res = nums[i + 1] - nums[i];
        return res;
    }
};
// @lc code=end
