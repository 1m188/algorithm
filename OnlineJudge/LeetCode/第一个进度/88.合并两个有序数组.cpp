/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (42.83%)
 * Total Accepted:    29.7K
 * Total Submissions: 69.3K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */
class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = 0;
        for (int i = 0; i < m && j < n; i++)
        {
            if (nums2[j] <= nums1[i])
            {
                for (int k = m - 1; k >= i; k--)
                {
                    nums1[k + 1] = nums1[k];
                }
                nums1[i] = nums2[j];
                j++, m++;
            }
        }
        while (j < n)
        {
            nums1[m] = nums2[j];
            j++, m++;
        }
    }
};

#include "vector"
using namespace std;
