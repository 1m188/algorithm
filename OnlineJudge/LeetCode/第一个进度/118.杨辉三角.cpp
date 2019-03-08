/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (60.11%)
 * Total Accepted:    17.1K
 * Total Submissions: 28.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vec(numRows);
        for (int i = 0; i < numRows; i++)
        {
            vec[i].resize(i + 1, 1);
            if (i + 1 >= 3)
            {
                for (int j = 1; j < i; j++)
                {
                    vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
                }
            }
        }
        return vec;
    }
};

#include "vector"
using namespace std;
