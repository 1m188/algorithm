/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.71%)
 * Likes:    705
 * Dislikes: 0
 * Total Accepted:    119.1K
 * Total Submissions: 153.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

#include "stack"
#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> each;
    void rec(int n, const vector<int> &nums, int idx)
    {
        while (idx <= nums.size() - n && n > 0)
        {
            each.push_back(nums[idx]);
            rec(n - 1, nums, idx + 1);
            each.pop_back();
            idx++;
        }

        if (!n)
            res.push_back(each);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        for (int i = 0; i <= nums.size(); i++)
            rec(i, nums, 0);
        return res;
    }
};
// @lc code=end
