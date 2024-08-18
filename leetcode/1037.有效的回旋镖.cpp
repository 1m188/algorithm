/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 *
 * https://leetcode-cn.com/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (40.90%)
 * Likes:    12
 * Dislikes: 0
 * Total Accepted:    3.8K
 * Total Submissions: 9.2K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * 回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
 * 
 * 给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,1],[2,3],[3,2]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,1],[2,2],[3,3]]
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * points.length == 3
 * points[i].length == 2
 * 0 <= points[i][j] <= 100
 * 
 * 
 */

#include "vector"
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &points)
    {
        auto &a = points[0], &b = points[1], &c = points[2];
        bool flagSame = a != b && a != c && b != c;
        bool flagLine = false;
        if (a[0] == b[0] || a[0] == c[0] || b[0] == c[0])
        {
            flagLine = a[0] != b[0] || a[0] != c[0] || b[0] != c[0];
        }
        else
        {
            double k = (static_cast<double>(b[1]) - a[1]) / (b[0] - a[0]);
            double bb = a[1] - k * a[0];
            double y = k * c[0] + bb;
            flagLine = y != c[1];
        }
        return flagSame && flagLine;
    }
};
// @lc code=end
