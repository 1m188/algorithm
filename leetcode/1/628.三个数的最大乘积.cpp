/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (49.11%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 30.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3]
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,3,4]
 * 输出: 24
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的整型数组长度范围是[3,10^4]，数组中所有的元素范围是[-1000, 1000]。
 * 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
 * 
 * 
 */

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int res1 = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int res2 = nums[0] * nums[1] * nums[size - 1];
        return max(res1, res2);
    }
};
// @lc code=end
