/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (39.58%)
 * Likes:    638
 * Dislikes: 0
 * Total Accepted:    74.4K
 * Total Submissions: 173.3K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 2:
 * 
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
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
    int rob(vector<int> &nums)
    {
        // 超时递归
        // if (nums.size() <= 1)
        // {
        //     return nums.size() == 0 ? 0 : nums[0];
        // }
        // else
        // {
        //     int num = 0;
        //     for (auto cit = nums.cbegin(); cit < nums.cend(); cit++)
        //     {
        //         std::vector<int> x;
        //         for (auto xcit = cit + 2; xcit < nums.cend(); xcit++)
        //         {
        //             x.push_back(*xcit);
        //         }
        //         num = max(num, *cit + rob(x));
        //     }
        //     return num;
        // }

        // 递推
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int t = b;
            b = max(a + nums[i], b);
            a = t;
        }
        return b;
    }
};
// @lc code=end
