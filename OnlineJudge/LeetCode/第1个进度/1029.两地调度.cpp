/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 *
 * https://leetcode-cn.com/problems/two-city-scheduling/description/
 *
 * algorithms
 * Easy (59.00%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 11K
 * Testcase Example:  '[[10,20],[30,200],[400,50],[30,20]]'
 *
 * 公司计划面试 2N 人。第 i 人飞往 A 市的费用为 costs[i][0]，飞往 B 市的费用为 costs[i][1]。
 * 
 * 返回将每个人都飞到某座城市的最低费用，要求每个城市都有 N 人抵达。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[[10,20],[30,200],[400,50],[30,20]]
 * 输出：110
 * 解释：
 * 第一个人去 A 市，费用为 10。
 * 第二个人去 A 市，费用为 30。
 * 第三个人去 B 市，费用为 50。
 * 第四个人去 B 市，费用为 20。
 * 
 * 最低总费用为 10 + 30 + 50 + 20 = 110，每个城市都有一半的人在面试。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= costs.length <= 100
 * costs.length 为偶数
 * 1 <= costs[i][0], costs[i][1] <= 1000
 * 
 * 
 */

// 方法：贪心
// 分析
// 我们这样来看这个问题，公司首先将这 2N 个人全都安排飞往 B 市，再选出 N 个人改变它们的行程，让他们飞往 A 市。如果选择改变一个人的行程，那么公司将会额外付出 price_A - price_B 的费用，这个费用可正可负。
// 因此最优的方案是，选出 price_A - price_B 最小的 N 个人，让他们飞往 A 市，其余人飞往 B 市。

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        sort(costs.begin(), costs.end(), [](const vector<int> &vec1, const vector<int> &vec2) { return vec1[0] - vec1[1] < vec2[0] - vec2[1]; });
        int res = 0;
        for (int i = 0; i < costs.size() / 2; i++)
        {
            res += costs[i][0];
        }
        for (int i = costs.size() / 2; i < costs.size(); i++)
        {
            res += costs[i][1];
        }
        return res;
    }
};
// @lc code=end
