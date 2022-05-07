/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (34.34%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 57.7K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */

#include "vector"
#include "limits"
using namespace std;

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN;
        for (const int &n : nums)
        {
            if (n == first || n == second || n == third)
            {
                continue;
            }
            if (n > first)
            {
                swap(second, third);
                swap(first, second);
                first = n;
            }
            else if (n > second)
            {
                swap(second, third);
                second = n;
            }
            else if (n > third)
            {
                third = n;
            }
        }
        return third == LLONG_MIN ? first : third;
    }
};
// @lc code=end
