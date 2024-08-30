/*
 * @lc app=leetcode.cn id=LCR 179 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 179] 查找总价格为目标值的两个商品
 *
 * https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/description/
 *
 * algorithms
 * Easy (67.82%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    296.4K
 * Total Submissions: 437K
 * Testcase Example:  '[3, 9, 12, 15]\n18'
 *
 * 购物车内的商品价格按照升序记录于数组 price。请在购物车中找到两个商品的价格总和刚好是 target。若存在多种情况，返回任一结果即可。
 *
 * 示例 1：
 *
 * 输入：price = [3, 9, 12, 15], target = 18
 * 输出：[3,15] 或者 [15,3]
 *
 *
 * 示例 2：
 *
 * 输入：price = [8, 21, 27, 34, 52, 66], target = 61
 * 输出：[27,34] 或者 [34,27]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= price.length <= 10^5
 * 1 <= price[i] <= 10^6
 * 1 <= target <= 2*10^6
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
    vector<int> twoSum(vector<int> &price, int target) {

        auto bsearch = [&](int left, int right, int target) {
            while (left <= right) {
                int mid = (left + right) / 2;
                if (price[mid] == target) return mid;
                if (price[mid] < target) left = mid + 1;
                if (price[mid] > target) right = mid - 1;
            }
            return -1;
        };

        for (int i = 0; i < price.size(); i++) {
            int j = bsearch(i + 1, price.size() - 1, target - price[i]);
            if (j == -1) continue;
            return {price[i], price[j]};
        }
        return {-1, -1};
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3, 9, 12, 15]\n18\n
// @lcpr case=end

// @lcpr case=start
// [8, 21, 27, 34, 52, 66]\n61\n
// @lcpr case=end

 */
