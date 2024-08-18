/*
 * @lc app=leetcode.cn id=LCP 06 lang=cpp
 * @lcpr version=30204
 *
 * [LCP 06] 拿硬币
 *
 * https://leetcode.cn/problems/na-ying-bi/description/
 *
 * algorithms
 * Easy (84.94%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    97.7K
 * Total Submissions: 115.1K
 * Testcase Example:  '[4,2,1]'
 *
 * 桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。
 *
 * 示例 1：
 *
 *
 * 输入：[4,2,1]
 *
 * 输出：4
 *
 * 解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。
 *
 *
 * 示例 2：
 *
 *
 * 输入：[2,3,10]
 *
 * 输出：8
 *
 *
 * 限制：
 *
 *
 * 1 <= n <= 4
 * 1 <= coins[i] <= 10
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
    int minCount(vector<int> &coins) {

        int res = 0;
        for (const int &coin : coins) {
            res += (coin >> 1) + (coin & 1);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,10]\n
// @lcpr case=end

 */
