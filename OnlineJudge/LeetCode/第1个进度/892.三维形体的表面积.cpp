/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (55.83%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    5.5K
 * Total Submissions: 9.9K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
 * 
 * 请你返回最终形体的表面积。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[2]]
 * 输出：10
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2],[3,4]]
 * 输出：34
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,0],[0,2]]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 * 
 * 
 * 示例 5：
 * 
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 */

// 方法：分块累加
// 思路
// 让我们试着计算 v = grid[i][j] 所贡献的表面积。
// 当 v > 0 时，顶面和底面的面积之和为 2。
// 然后，对于列 grid[i][j] 的每一侧（西，北，东，南），值为 nv 的相邻单元意味着这些方块贡献了 max(v - nv, 0) 的面积。
// 例如，对于 grid = [[1, 5]]，grid[0][1] 贡献的表面积是 2 + 5 + 5 + 5 + 4。其中 2 来自顶部和底部；5 来自北、东、南三面；4 来自西面，其中 1 个单位被邻列覆盖。
// 算法
// 对于每个 v = grid[r][c] > 0，计算 ans += 2，对于 grid[r][c] 附近的每个相邻值 nv 还要加上 ans += max(v - nv, 0)。

#include "vector"
#include "numeric"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        const pair<int, int> pos[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] > 0)
                {
                    res += 2;
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + pos[k].first;
                        int nj = j + pos[k].second;
                        if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid.size())
                        {
                            res += max(grid[i][j] - grid[ni][nj], 0);
                        }
                        else
                        {
                            res += grid[i][j];
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
