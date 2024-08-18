/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (54.69%)
 * Likes:    528
 * Dislikes: 0
 * Total Accepted:    103.9K
 * Total Submissions: 188K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;

        int low = left, high = right;
        int tmp = nums[low];

        while (low < high)
        {
            while (low < high && nums[high] >= tmp)
                high--;
            if (low < high)
                nums[low++] = nums[high];
            while (low < high && nums[low] <= tmp)
                low++;
            if (low < high)
                nums[high--] = nums[low];
        }
        nums[low] = tmp;
        quickSort(nums, left, low - 1);
        quickSort(nums, low + 1, right);
    }

    void adjust_heap(vector<int> &vec, int left, int right)
    {
        int tmp = vec[left];
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

    void heapSort(vector<int> &vec)
    {
        for (int i = (vec.size() - 2) / 2; i >= 0; i--)
            adjust_heap(vec, i, vec.size() - 1);
        for (int i = vec.size() - 1; i >= 1; i--)
            swap(vec[0], vec[i]), adjust_heap(vec, 0, i - 1);
    }

public:
    void sortColors(vector<int> &nums)
    {
        vector<vector<int>> vec(3);
        for (const int &e : nums)
            vec[e].push_back(e);
        nums.clear();
        for (int i = 0; i < 3; i++)
            for (const int &e : vec[i])
                nums.push_back(e);

        // quickSort(nums, 0, nums.size() - 1);

        // heapSort(nums);
    }
};
// @lc code=end
