/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 * @lcpr version=30204
 *
 * [3222] 求出硬币游戏的赢家
 *
 * https://leetcode.cn/problems/find-the-winning-player-in-coin-game/description/
 *
 * algorithms
 * Easy (64.92%)
 * Likes:    0
 * Dislikes: 0
 * Total Accepted:    4.2K
 * Total Submissions: 6.6K
 * Testcase Example:  '2\n7'
 *
 * 给你两个 正 整数 x 和 y ，分别表示价值为 75 和 10 的硬币的数目。
 *
 * Alice 和 Bob 正在玩一个游戏。每一轮中，Alice 先进行操作，Bob 后操作。每次操作中，玩家需要拿出价值 总和 为 115
 * 的硬币。如果一名玩家无法执行此操作，那么这名玩家 输掉 游戏。
 *
 * 两名玩家都采取 最优 策略，请你返回游戏的赢家。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：x = 2, y = 7
 *
 * 输出："Alice"
 *
 * 解释：
 *
 * 游戏一次操作后结束：
 *
 *
 * Alice 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：x = 4, y = 11
 *
 * 输出："Bob"
 *
 * 解释：
 *
 * 游戏 2 次操作后结束：
 *
 *
 * Alice 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。
 * Bob 拿走 1 枚价值为 75 的硬币和 4 枚价值为 10 的硬币。
 *
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= x, y <= 100
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
    string losingPlayer(int x, int y) {
        bool Alice = true;
        while (x >= 1 && y >= 4) {
            x -= 1;
            y -= 4;
            Alice = !Alice;
        }
        return Alice ? "Bob" : "Alice";
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n7\n
// @lcpr case=end

// @lcpr case=start
// 4\n11\n
// @lcpr case=end

 */
