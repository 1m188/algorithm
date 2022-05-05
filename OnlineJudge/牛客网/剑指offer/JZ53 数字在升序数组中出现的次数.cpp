/*

描述
给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数

数据范围：0≤n≤1000,0≤k≤100，数组中每个元素的值满足 0≤val≤100
要求：空间复杂度 O(1)，时间复杂度 O(logn)

示例1
输入：
[1,2,3,3,3,3,4,5],3

返回值：
4

示例2
输入：
[1,3,4,5],6

返回值：
0

*/

#include <vector>

using namespace std;

class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        // 目标数字在数组中的索引
        int index = bin_find(data, k, 0, data.size() - 1);

        if (index == -1) // 找不到直接返回0
            return 0;

        int ans = 1; // 找到则初始就有一个
        // 向右边查找
        for (int i = index + 1; i < data.size() && data[i] == k; i++)
            ans++;
        // 向左边查找
        for (int i = index - 1; i >= 0 && data[i] == k; i--)
            ans++;
        return ans;
    }

    // 二分查找
    int bin_find(const vector<int> &vec, int target, int start, int end)
    {
        int mid = 0;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (vec[mid] == target)
                return mid;
            else if (vec[mid] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};