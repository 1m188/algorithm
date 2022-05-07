/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (56.99%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    9.5K
 * Total Submissions: 16.7K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k
 * 之间的距离相等（需要考虑元组的顺序）。
 * 
 * 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [[0,0],[1,0],[2,0]]
 * 
 * 输出:
 * 2
 * 
 * 解释:
 * 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 */

// 找了leetcode官网上面别人的解析，用表来做

// 题目中所谓的 "回旋镖" 就是指数组中存在两个点 B C 与点 A 的距离相等。 即 [A, B, C] 中 distance(A, B) == distance(A, C)， [A, B, C] 就是一个 "回旋镖"
// 题目中要求返回满足该条件的所有点的个数， 所以可以想到固定点 A， 并计算其它所有点到 A 的距离，并在字典 distNum 中记录（k 为距离， v 为是距离为 k 的点的数量）
// 然后再检查 distNum， 如果同一个距离有两个或以上的点， 就可以说明存在 "回旋镖".
// 并且通过简单的画图总结， 可以知道回旋镖的数量为 distNum[d] * (distNum[d] - 1) 即：
// .....
// 4 个与点 A 相同距离的点， 则有 4 * 3 个回旋镖
// 3 个与点 A 相同距离的点， 则有 3 * 2 个回旋镖
// 2 个与点 A 相同距离的点， 则有 2 * 1 个回旋镖

// 时间复杂度 O(n²)， 空间复杂度 O(n)

#include "vector"
#include "cmath"
#include "unordered_map"
using namespace std;

// @lc code=start
class Solution
{
private:
    double dis(const vector<int> &p1, const vector<int> &p2) const
    {
        return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
    }

public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        if (points.size() < 3)
        {
            return 0;
        }
        else
        {
            int res = 0;
            for (const auto &v : points)
            {
                unordered_map<double, int> um;
                for (const auto &vv : points)
                {
                    if (vv != v)
                    {
                        double &&d = dis(v, vv);
                        if (um.find(d) == um.end())
                        {
                            um[d] = 1;
                        }
                        else
                        {
                            um[d]++;
                        }
                    }
                }
                for (const auto &p : um)
                {
                    res += p.second * (p.second - 1);
                }
            }
            return res;
        }
    }
};
// @lc code=end
