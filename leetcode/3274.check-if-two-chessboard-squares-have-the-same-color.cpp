/*
 * @lc app=leetcode.cn id=3274 lang=cpp
 * @lcpr version=30204
 *
 * [3274] 检查棋盘方格颜色是否相同
 *
 * https://leetcode.cn/problems/check-if-two-chessboard-squares-have-the-same-color/description/
 *
 * algorithms
 * Easy (75.10%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 7K
 * Testcase Example:  '"a1"\n"c3"'
 *
 * 给你两个字符串 coordinate1 和 coordinate2，代表 8 x 8 国际象棋棋盘上的两个方格的坐标。
 *
 * 以下是棋盘的参考图。
 *
 *
 *
 * 如果这两个方格颜色相同，返回 true，否则返回 false。
 *
 * 坐标总是表示有效的棋盘方格。坐标的格式总是先字母（表示列），再数字（表示行）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： coordinate1 = "a1", coordinate2 = "c3"
 *
 * 输出： true
 *
 * 解释：
 *
 * 两个方格均为黑色。
 *
 *
 * 示例 2：
 *
 *
 * 输入： coordinate1 = "a1", coordinate2 = "h3"
 *
 * 输出： false
 *
 * 解释：
 *
 * 方格 "a1" 是黑色，而 "h3" 是白色。
 *
 *
 *
 *
 * 提示：
 *
 *
 * coordinate1.length == coordinate2.length == 2
 * 'a' <= coordinate1[0], coordinate2[0] <= 'h'
 * '1' <= coordinate1[1], coordinate2[1] <= '8'
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
    bool checkTwoChessboards(string coordinate1, string coordinate2) {

        vector<vector<bool>> arr(8, vector<bool>(8, false));
        for (int i = 0; i < 8; i++) {
            for (int j = i & 0x1; j < 8; j += 2) {
                arr[i][j] = true;
            }
        }

        return arr[coordinate1[0] - 'a'][coordinate1[1] - '1'] == arr[coordinate2[0] - 'a'][coordinate2[1] - '1'];
    }
};
// @lc code=end

/*
// @lcpr case=start
// "a1"\n"c3"\n
// @lcpr case=end

// @lcpr case=start
// "a1"\n"h3"\n
// @lcpr case=end

 */
