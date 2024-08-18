/*
 * @lc app=leetcode.cn id=3248 lang=cpp
 * @lcpr version=30204
 *
 * [3248] 矩阵中的蛇
 *
 * https://leetcode.cn/problems/snake-in-matrix/description/
 *
 * algorithms
 * Easy (87.03%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 5.5K
 * Testcase Example:  '2\n["RIGHT","DOWN"]'
 *
 * 大小为 n x n 的矩阵 grid 中有一条蛇。蛇可以朝 四个可能的方向 移动。矩阵中的每个单元格都使用位置进行标识： grid[i][j] = (i
 * * n) + j。
 *
 * 蛇从单元格 0 开始，并遵循一系列命令移动。
 *
 * 给你一个整数 n 表示 grid 的大小，另给你一个字符串数组 commands，其中包括 "UP"、"RIGHT"、"DOWN" 和
 * "LEFT"。题目测评数据保证蛇在整个移动过程中将始终位于 grid 边界内。
 *
 * 返回执行 commands 后蛇所停留的最终单元格的位置。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 2, commands = ["RIGHT","DOWN"]
 *
 * 输出：3
 *
 * 解释：
 *
 *
 *
 *
 *
 * 0
 * 1
 *
 *
 * 2
 * 3
 *
 *
 *
 *
 *
 *
 *
 * 0
 * 1
 *
 *
 * 2
 * 3
 *
 *
 *
 *
 *
 *
 *
 * 0
 * 1
 *
 *
 * 2
 * 3
 *
 *
 *
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 3, commands = ["DOWN","RIGHT","UP"]
 *
 * 输出：1
 *
 * 解释：
 *
 *
 *
 *
 *
 * 0
 * 1
 * 2
 *
 *
 * 3
 * 4
 * 5
 *
 *
 * 6
 * 7
 * 8
 *
 *
 *
 *
 *
 *
 *
 * 0
 * 1
 * 2
 *
 *
 * 3
 * 4
 * 5
 *
 *
 * 6
 * 7
 * 8
 *
 *
 *
 *
 *
 *
 *
 * 0
 * 1
 * 2
 *
 *
 * 3
 * 4
 * 5
 *
 *
 * 6
 * 7
 * 8
 *
 *
 *
 *
 *
 *
 *
 * 0
 * 1
 * 2
 *
 *
 * 3
 * 4
 * 5
 *
 *
 * 6
 * 7
 * 8
 *
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
 * 2 <= n <= 10
 * 1 <= commands.length <= 100
 * commands 仅由 "UP"、"RIGHT"、"DOWN" 和 "LEFT" 组成。
 * 生成的测评数据确保蛇不会移动到矩阵的边界外。
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
    int finalPositionOfSnake(int n, vector<string> &commands) {

        int i = 0, j = 0;
        for (const string &cmd : commands) {
            if (cmd == "RIGHT")
                i++;
            else if (cmd == "LEFT")
                i--;
            else if (cmd == "DOWN")
                j++;
            else
                j--;
        }
        return (j * n) + i;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n["RIGHT","DOWN"]\n
// @lcpr case=end

// @lcpr case=start
// 3\n["DOWN","RIGHT","UP"]\n
// @lcpr case=end

 */
