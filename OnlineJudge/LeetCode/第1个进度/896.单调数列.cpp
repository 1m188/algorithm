/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 *
 * https://leetcode-cn.com/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (51.38%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    12.7K
 * Total Submissions: 24.6K
 * Testcase Example:  '[1,2,2,3]'
 *
 * 如果数组是单调递增或单调递减的，那么它是单调的。
 * 
 * 如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A
 * 是单调递减的。
 * 
 * 当给定的数组 A 是单调数组时返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,2,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：[6,5,4,4]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1,3,2]
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 输入：[1,2,4,5]
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：[1,1,1]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 50000
 * -100000 <= A[i] <= 100000
 * 
 * 
 */

#include "vector"
#include "cmath"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        if (A.size() > 1)
        {
            int diff = A[1] - A[0];
            for (int i = 2; i < A.size(); i++)
            {
                int ndiff = A[i] - A[i - 1];
                int num = diff * ndiff;
                if (num < 0)
                {
                    return false;
                }
                else if (ndiff == 0)
                {
                    ndiff = diff;
                }
                diff = ndiff;
            }
        }
        return true;
    }
};
// @lc code=end
