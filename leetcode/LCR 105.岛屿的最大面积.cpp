/*
 * @lc app=leetcode.cn id=LCR 105 lang=cpp
 * @lcpr version=30204
 *
 * [LCR 105] 岛屿的最大面积
 *
 * https://leetcode.cn/problems/ZL6zAn/description/
 *
 * algorithms
 * Medium (68.64%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    41.3K
 * Total Submissions: 60.1K
 * Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的非空二维数组 grid ，用来表示海洋岛屿地图。
 *
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
 * 0（代表水）包围着。
 *
 * 找到给定的二维数组中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 * 输入: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 输出: 6
 * 解释: 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
 *
 * 示例 2:
 *
 * 输入: grid = [[0,0,0,0,0,0,0,0]]
 * 输出: 0
 *
 *
 *
 * 提示：
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1
 *
 *
 *
 *
 * 注意：本题与主站 695 题相同： https://leetcode-cn.com/problems/max-area-of-island/
 *
 */
#include <queue>
#include <vector>

using namespace std;

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> flags(m, vector<bool>(n, false));

        auto bfs = [&](int a, int b) -> int {
            queue<pair<int, int>> que;
            que.push({a, b});
            flags[a][b] = true;
            int res = 1;
            while (!que.empty()) {
                a = que.front().first, b = que.front().second;
                que.pop();
                if (a - 1 >= 0 && grid[a - 1][b] == 1 && !flags[a - 1][b]) {
                    flags[a - 1][b] = true;
                    que.push({a - 1, b});
                    res++;
                }
                if (a + 1 < m && grid[a + 1][b] == 1 && !flags[a + 1][b]) {
                    flags[a + 1][b] = true;
                    que.push({a + 1, b});
                    res++;
                }
                if (b - 1 >= 0 && grid[a][b - 1] == 1 && !flags[a][b - 1]) {
                    flags[a][b - 1] = true;
                    que.push({a, b - 1});
                    res++;
                }
                if (b + 1 < n && grid[a][b + 1] == 1 && !flags[a][b + 1]) {
                    flags[a][b + 1] = true;
                    que.push({a, b + 1});
                    res++;
                }
            }
            return res;
        };

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !flags[i][j]) {
                    int x = bfs(i, j);
                    res = max(res, x);
                }
            }
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,0,0,0,0,0,0,0]]\n
// @lcpr case=end

 */
