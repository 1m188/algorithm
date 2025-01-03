/*
 * @lc app=leetcode.cn id=面试题 17.16 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.16] 按摩师
 *
 * https://leetcode.cn/problems/the-masseuse-lcci/description/
 *
 * LCCI
 * Easy (51.55%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    86.7K
 * Total Submissions: 168.1K
 * Testcase Example:  '[1,2,3,1]'
 *
 *
 * 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
 *
 * 注意：本题相对原题稍作改动
 *
 *
 *
 * 示例 1：
 *
 * 输入： [1,2,3,1]
 * 输出： 4
 * 解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
 *
 *
 * 示例 2：
 *
 * 输入： [2,7,9,3,1]
 * 输出： 12
 * 解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
 *
 *
 * 示例 3：
 *
 * 输入： [2,1,4,5,3,1,1,3]
 * 输出： 12
 * 解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。
 *
 *
 */
#include <vector>
using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int massage(vector<int> &nums) {
        if (nums.empty()) return 0;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = nums[0];

        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,7,9,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,4,5,3,1,1,3]\n
// @lcpr case=end

 */
