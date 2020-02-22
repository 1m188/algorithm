/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (40.07%)
 * Likes:    235
 * Dislikes: 0
 * Total Accepted:    67.2K
 * Total Submissions: 144K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [4,9]
 * 
 * 说明：
 * 
 * 
 * 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 * 进阶:
 * 
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 * 
 * 
 */

// 给定数组排好序，个人想法是使用二分查找代替find
// nums1更小的话，应该是排好序的方法更优
// 从磁盘中不断加载部分数据，然后不断和nums1进行比较。或者用数据:次数这种方式加载存储

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        for (const int &num : nums1)
        {
            auto it = find(nums2.begin(), nums2.end(), num);
            if (it != nums2.end())
            {
                res.push_back(num);
                nums2.erase(it);
            }
        }
        return res;
    }
};
// @lc code=end
