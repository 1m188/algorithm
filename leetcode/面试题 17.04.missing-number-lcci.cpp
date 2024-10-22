/*
 * @lc app=leetcode.cn id=面试题 17.04 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 17.04] 消失的数字
 *
 * https://leetcode.cn/problems/missing-number-lcci/description/
 *
 * LCCI
 * Easy (58.34%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    67.7K
 * Total Submissions: 116K
 * Testcase Example:  '[3,0,1]'
 *
 * 数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
 *
 * 注意：本题相对书上原题稍作改动
 *
 * 示例 1：
 *
 * 输入：[3,0,1]
 * 输出：2
 *
 *
 *
 * 示例 2：
 *
 * 输入：[9,6,4,2,3,5,7,0,1]
 * 输出：8
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
#include <numeric>
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
    int missingNumber(vector<int> &nums) {
        int n = nums.size();
        int x = n * (n + 1) / 2;
        int y = accumulate(nums.begin(), nums.end(), 0);
        return x - y;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,0,1]\n
// @lcpr case=end

// @lcpr case=start
// [9,6,4,2,3,5,7,0,1]\n
// @lcpr case=end

 */
