/*
 * @lc app=leetcode.cn id=面试题 05.07 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 05.07] 配对交换
 *
 * https://leetcode.cn/problems/exchange-lcci/description/
 *
 * LCCI
 * Easy (70.99%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 29.6K
 * Testcase Example:  '3'
 *
 * 配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。
 *
 * ⁠示例1:
 *
 * ⁠输入：num = 2（或者0b10）
 * ⁠输出 1 (或者 0b01)
 *
 *
 * ⁠示例2:
 *
 * ⁠输入：num = 3
 * ⁠输出：3
 *
 *
 * ⁠提示:
 *
 *
 * num的范围在[0, 2^30 - 1]之间，不会发生整数溢出。
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
    int exchangeBits(int num) {
        uint32_t x = num;
        uint32_t x1 = 0b01010101010101010101010101010101;
        uint32_t x2 = 0b10101010101010101010101010101010;
        return ((x1 & x) << 1) | ((x2 & x) >> 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

 */
