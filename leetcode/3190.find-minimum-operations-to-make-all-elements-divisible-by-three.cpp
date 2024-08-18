/*
 * @lc app=leetcode.cn id=3190 lang=cpp
 * @lcpr version=30204
 *
 * [3190] 使所有元素都可以被 3 整除的最少操作数
 *
 * https://leetcode.cn/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/
 *
 * algorithms
 * Easy (84.03%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给你一个整数数组 nums 。一次操作中，你可以将 nums 中的 任意 一个元素增加或者减少 1 。
 *
 * 请你返回将 nums 中所有元素都可以被 3 整除的 最少 操作次数。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,2,3,4]
 *
 * 输出：3
 *
 * 解释：
 *
 * 通过以下 3 个操作，数组中的所有元素都可以被 3 整除：
 *
 *
 * 将 1 减少 1 。
 * 将 2 增加 1 。
 * 将 4 减少 1 。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [3,6,9]
 *
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50
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
    int minimumOperations(vector<int> &nums) {

        int res = 0;
        for (const int &num : nums) {
            int n = num;
            int op1 = 0, op2 = 0;
            while (n % 3 != 0) {
                n--;
                op1++;
            }
            n = num;
            while (n % 3 != 0) {
                n++;
                op2++;
            }
            res += min(op1, op2);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,6,9]\n
// @lcpr case=end

 */
