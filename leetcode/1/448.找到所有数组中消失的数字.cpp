/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 *
 * https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *
 * algorithms
 * Easy (56.45%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 48.1K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
 * 
 * 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
 * 
 * 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [5,6]
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
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        if (!nums.size())
        {
            return vector<int>();
        }

        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = 0;
        for (auto cit = nums.cbegin(); cit < nums.cend();)
        {
            if (*cit == n + 1)
            {
                n++;
                cit++;
            }
            else if (*cit == n)
            {
                cit++;
            }
            else
            {
                n++;
                res.push_back(n);
            }
        }
        while (++n <= nums.size())
        {
            res.push_back(n);
        }
        return res;
    }
};
// @lc code=end
