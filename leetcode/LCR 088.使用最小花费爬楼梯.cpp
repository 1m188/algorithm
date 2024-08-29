/*
 * @lc app=leetcode.cn id=LCR 088 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 088] 使用最小花费爬楼梯
 *
 * https://leetcode.cn/problems/GzCJIP/description/
 *
 * algorithms
 * Easy (71.13%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    49.6K
 * Total Submissions: 69.8K
 * Testcase Example:  '[10,15,20]'
 *
 * 数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
 *
 * 每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
 *
 * 请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
 *
 *
 *
 * 示例 1：
 *
 * 输入：cost = [10, 15, 20]
 * 输出：15
 * 解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
 *
 *
 * 示例 2：
 *
 * 输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * 输出：6
 * 解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 *
 *
 *
 *
 * 注意：本题与主站 746 题相同： https://leetcode-cn.com/problems/min-cost-climbing-stairs/
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        if (n == 2) return *min_element(cost.begin(), cost.end());

        vector<int> dp0(n + 1, 0), dp1(n + 1, 0);
        dp0[0] = 0;
        dp0[1] = dp0[2] = cost[0];
        for (int i = 3; i < dp0.size(); i++) {
            dp0[i] = min(dp0[i - 1] + cost[i - 1], dp0[i - 2] + cost[i - 2]);
        }
        dp1[0] = dp1[1] = 0;
        dp1[2] = dp1[3] = cost[1];
        for (int i = 4; i < dp1.size(); i++) {
            dp1[i] = min(dp1[i - 1] + cost[i - 1], dp1[i - 2] + cost[i - 2]);
        }
        return min(dp0.back(), dp1.back());
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10, 15, 20]\n
// @lcpr case=end

// @lcpr case=start
// [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]\n
// @lcpr case=end

 */
