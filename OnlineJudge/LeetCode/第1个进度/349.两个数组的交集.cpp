/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (61.13%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    51.7K
 * Total Submissions: 75.7K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */

#include "vector"
#include "set"
#include "algorithm"
#include "iterator"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        // AC
        // 在两个数组中找相同的数据然后放入集合中，自动去重
        // set<int> res;
        // for (const int &num : nums1)
        // {
        //     if (find(nums2.begin(), nums2.end(), num) != nums2.end())
        //     {
        //         res.insert(num);
        //     }
        // }
        // return vector<int>(res.begin(), res.end());

        // AC
        // 直接使用STL提供的集合运算，将交集结果放入vector中
        set<int> n1(nums1.begin(), nums1.end());
        set<int> n2(nums2.begin(), nums2.end());
        vector<int> res;
        set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), insert_iterator<vector<int>>(res, res.begin()));
        return res;
    }
};
// @lc code=end
