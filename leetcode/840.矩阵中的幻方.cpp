/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 *
 * https://leetcode-cn.com/problems/magic-squares-in-grid/description/
 *
 * algorithms
 * Easy (33.61%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 13.8K
 * Testcase Example:  '[[4,3,8,4],[9,5,1,9],[2,7,6,2]]'
 *
 * 3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。
 * 
 * 给定一个由整数组成的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: [[4,3,8,4],
 * ⁠     [9,5,1,9],
 * ⁠     [2,7,6,2]]
 * 输出: 1
 * 解释: 
 * 下面的子矩阵是一个 3 x 3 的幻方：
 * 438
 * 951
 * 276
 * 
 * 而这一个不是：
 * 384
 * 519
 * 762
 * 
 * 总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * 0 <= grid[i][j] <= 15
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
private:
    bool isDifferentAllNum(int rowStart, int colStart, vector<vector<int>> &grid)
    {
        vector<bool> vec(9, false);
        for (int i = rowStart; i < rowStart + 3; i++)
        {
            for (int j = colStart; j < colStart + 3; j++)
            {
                if (grid[i][j] < 1 || grid[i][j] > 9)
                {
                    return false;
                }
                else
                {
                    if (!vec[grid[i][j] - 1])
                    {
                        vec[grid[i][j] - 1] = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool judgeEqual(int rowStart, int colStart, vector<vector<int>> &grid)
    {
        int num = 0;
        for (int i = colStart; i < colStart + 3; i++)
        {
            num += grid[rowStart][i];
        }
        for (int i = rowStart + 1; i < rowStart + 3; i++)
        {
            int tmp = 0;
            for (int j = colStart; j < colStart + 3; j++)
            {
                tmp += grid[i][j];
            }
            if (tmp != num)
            {
                return false;
            }
        }
        for (int i = colStart; i < colStart + 3; i++)
        {
            int tmp = 0;
            for (int j = rowStart; j < rowStart + 3; j++)
            {
                tmp += grid[j][i];
            }
            if (tmp != num)
            {
                return false;
            }
        }
        int tmp = 0;
        tmp += grid[rowStart][colStart] + grid[rowStart + 1][colStart + 1] + grid[rowStart + 2][colStart + 2];
        if (tmp != num)
        {
            return false;
        }
        tmp = 0;
        tmp += grid[rowStart][colStart + 2] + grid[rowStart + 1][colStart + 1] + grid[rowStart + 2][colStart];
        if (tmp != num)
        {
            return false;
        }
        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        if (grid.size() < 3 || grid[0].size() < 3)
        {
            return 0;
        }
        else
        {
            int res = 0;
            for (int i = 0; i + 3 <= grid.size(); i++)
            {
                for (int j = 0; j + 3 <= grid[0].size(); j++)
                {
                    res += isDifferentAllNum(i, j, grid) && judgeEqual(i, j, grid);
                }
            }
            return res;
        }
    }
};
// @lc code=end
