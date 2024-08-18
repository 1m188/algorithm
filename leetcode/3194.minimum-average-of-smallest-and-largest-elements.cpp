/*
 * @lc app=leetcode.cn id=3194 lang=cpp
 * @lcpr version=30204
 *
 * [3194] 最小元素和最大元素的最小平均值
 *
 * https://leetcode.cn/problems/minimum-average-of-smallest-and-largest-elements/description/
 *
 * algorithms
 * Easy (84.68%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 7.6K
 * Testcase Example:  '[7,8,3,4,15,13,4,1]'
 *
 * 你有一个初始为空的浮点数数组 averages。另给你一个包含 n 个整数的数组 nums，其中 n 为偶数。
 *
 * 你需要重复以下步骤 n / 2 次：
 *
 *
 * 从 nums 中移除 最小 的元素 minElement 和 最大 的元素 maxElement。
 * 将 (minElement + maxElement) / 2 加入到 averages 中。
 *
 *
 * 返回 averages 中的 最小 元素。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： nums = [7,8,3,4,15,13,4,1]
 *
 * 输出： 5.5
 *
 * 解释：
 *
 *
 *
 *
 * 步骤
 * nums
 * averages
 *
 *
 * 0
 * [7,8,3,4,15,13,4,1]
 * []
 *
 *
 * 1
 * [7,8,3,4,13,4]
 * [8]
 *
 *
 * 2
 * [7,8,4,4]
 * [8,8]
 *
 *
 * 3
 * [7,4]
 * [8,8,6]
 *
 *
 * 4
 * []
 * [8,8,6,5.5]
 *
 *
 *
 * 返回 averages 中最小的元素，即 5.5。
 *
 * 示例 2：
 *
 *
 * 输入： nums = [1,9,8,3,10,5]
 *
 * 输出： 5.5
 *
 * 解释：
 *
 *
 *
 *
 * 步骤
 * nums
 * averages
 *
 *
 * 0
 * [1,9,8,3,10,5]
 * []
 *
 *
 * 1
 * [9,8,3,5]
 * [5.5]
 *
 *
 * 2
 * [8,5]
 * [5.5,6]
 *
 *
 * 3
 * []
 * [5.5,6,6.5]
 *
 *
 *
 *
 *
 * 示例 3：
 *
 *
 * 输入： nums = [1,2,3,7,8,9]
 *
 * 输出： 5.0
 *
 * 解释：
 *
 *
 *
 *
 * 步骤
 * nums
 * averages
 *
 *
 * 0
 * [1,2,3,7,8,9]
 * []
 *
 *
 * 1
 * [2,3,7,8]
 * [5]
 *
 *
 * 2
 * [3,7]
 * [5,5]
 *
 *
 * 3
 * []
 * [5,5,5]
 *
 *
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= n == nums.length <= 50
 * n 为偶数。
 * 1 <= nums[i] <= 50
 *
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
    double minimumAverage(vector<int> &nums) {

        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        double res = 100;
        while (n--) {
            double a = nums[0], b = nums.back();
            nums.pop_back();
            nums.erase(nums.begin());
            res = min(res, (a + b) / 2);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [7,8,3,4,15,13,4,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,9,8,3,10,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,7,8,9]\n
// @lcpr case=end

 */
