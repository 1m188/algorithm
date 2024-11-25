/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 * @lcpr version=30204
 *
 * [3195] 包含所有 1 的最小矩形面积 I
 *
 * https://leetcode.cn/problems/find-the-minimum-area-to-cover-all-ones-i/description/
 *
 * algorithms
 * Medium (78.89%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 7.9K
 * Testcase Example:  '[[0,1,0],[1,0,1]]'
 *
 * 给你一个二维 二进制 数组 grid。请你找出一个边在水平方向和竖直方向上、面积 最小 的矩形，并且满足 grid 中所有的 1 都在矩形的内部。
 *
 * 返回这个矩形可能的 最小 面积。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入： grid = [[0,1,0],[1,0,1]]
 *
 * 输出： 6
 *
 * 解释：
 *
 *
 *
 * 这个最小矩形的高度为 2，宽度为 3，因此面积为 2 * 3 = 6。
 *
 *
 * 示例 2：
 *
 *
 * 输入： grid = [[0,0],[1,0]]
 *
 * 输出： 1
 *
 * 解释：
 *
 *
 *
 * 这个最小矩形的高度和宽度都是 1，因此面积为 1 * 1 = 1。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length, grid[i].length <= 1000
 * grid[i][j] 是 0 或 1。
 * 输入保证 grid 中至少有一个 1 。
 *
 *
 */
#include <vector>
using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumArea(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int left = -1, right = -1, up = -1, bottom = -1;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 0) continue;
                if (left == -1) left = j;
                right = j;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (up == -1) up = i;
                bottom = i;
            }
        }

        return (right - left + 1) * (bottom - up + 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,0],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0],[1,0]]\n
// @lcpr case=end

 */
