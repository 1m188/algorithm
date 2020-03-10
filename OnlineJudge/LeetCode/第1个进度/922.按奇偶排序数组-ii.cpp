/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (67.08%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 36.9K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 * 
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
 * 
 * 你可以返回任何满足上述条件的数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        vector<int> res(A.size(), 0);
        int evenIndex = 0, oddIndex = 1;
        for (const int &a : A)
        {
            if (a % 2 == 0)
            {
                res[evenIndex] = a;
                evenIndex += 2;
            }
            else
            {
                res[oddIndex] = a;
                oddIndex += 2;
            }
        }
        return res;
    }
};
// @lc code=end
