/**
 * @file JZ47 礼物的最大价值.cpp
 * @date 2022-05-23
 */

/*
描述
在一个m\times nm×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
如输入这样的一个二维数组，
[
[1,3,1],
[1,5,1],
[4,2,1]
]
那么路径 1→3→5→2→1 可以拿到最多价值的礼物，价值为12
示例1
输入：
[[1,3,1],[1,5,1],[4,2,1]]
复制
返回值：
12
复制
备注：
\bullet\ 0 < \text{grid.length} \le 200∙ 0<grid.length≤200 
\bullet\ 0 < \text{grid[0].length} \le 200∙ 0<grid[0].length≤200
*/

#include <vector>
using namespace std;

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int>> &grid) {
        // write code here

        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = j - 1 >= 0 ? dp[i][j - 1] : 0;
                int y = i - 1 >= 0 ? dp[i - 1][j] : 0;
                dp[i][j] = grid[i][j] + max(x, y);
            }
        }

        return dp[m - 1][n - 1];
    }
};