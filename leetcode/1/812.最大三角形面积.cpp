/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 *
 * https://leetcode-cn.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (59.73%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    5.1K
 * Total Submissions: 8.5K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
 * 
 * 
 * 示例:
 * 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * 输出: 2
 * 解释: 
 * 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
 * 
 * 
 * 
 * 
 * 注意: 
 * 
 * 
 * 3 <= points.length <= 50.
 * 不存在重复的点。
 * -50 <= points[i][j] <= 50.
 * 结果误差值在 10^-6 以内都认为是正确答案。
 * 
 * 
 */

#include "vector"
#include "cmath"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
private:
    double area(const double l1, const double l2, const double l3) const
    {
        double p = (l1 + l2 + l3) / 2;
        return pow(p * (p - l1) * (p - l2) * (p - l3), 0.5);
    }

    double distance(const vector<int> &p1, const vector<int> &p2) const
    {
        return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
    }

public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                for (int k = j + 1; k < points.size(); k++)
                {
                    double d1 = distance(points[i], points[j]);
                    double d2 = distance(points[i], points[k]);
                    double d3 = distance(points[j], points[k]);
                    double a = area(d1, d2, d3);
                    res = max(res, a);
                }
            }
        }
        return res;
    }
};
// @lc code=end
