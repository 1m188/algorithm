/*
 * @lc app=leetcode.cn id=LCR 189 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 189] 设计机械累加器
 *
 * https://leetcode.cn/problems/qiu-12n-lcof/description/
 *
 * algorithms
 * Medium (85.63%)
 * Likes:    652
 * Dislikes: 0
 * Total Accepted:    260.1K
 * Total Submissions: 303.7K
 * Testcase Example:  '5'
 *
 * 请设计一个机械累加器，计算从 1、2... 一直累加到目标数值 target
 * 的总和。注意这是一个只能进行加法操作的程序，不具备乘除、if-else、switch-case、for 循环、while
 * 循环，及条件判断语句等高级功能。
 *
 *
 *
 * 示例 1：
 *
 * 输入: target = 5
 * 输出: 15
 *
 *
 * 示例 2：
 *
 * 输入: target = 7
 * 输出: 28
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target <= 10000
 *
 *
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
    int mechanicalAccumulator(int target) {

        return target <= 0 ? target : target + mechanicalAccumulator(target - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

 */
