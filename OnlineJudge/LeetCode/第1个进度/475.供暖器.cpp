/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 *
 * https://leetcode-cn.com/problems/heaters/description/
 *
 * algorithms
 * Easy (29.46%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 24.9K
 * Testcase Example:  '[1,2,3]\n[2]'
 *
 * 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
 * 
 * 现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
 * 
 * 所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
 * 
 * 说明:
 * 
 * 
 * 给出的房屋和供暖器的数目是非负数且不会超过 25000。
 * 给出的房屋和供暖器的位置均是非负数且不会超过10^9。
 * 只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
 * 所有供暖器都遵循你的半径标准，加热的半径也一样。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3],[2]
 * 输出: 1
 * 解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,3,4],[1,4]
 * 输出: 1
 * 解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
 * 
 * 
 */

// 思路：找到每个房屋离加热器的最短距离（即找出离房屋最近的加热器），然后在所有距离中选出最大的一个即为结果。

#include "vector"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        // 存放每个房屋与加热器的最短距离
        vector<int> res;

        // 排序
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        for (const int &ho : houses)
        {
            // 二分查找，在heaters中查找与房屋相隔最近的加热器
            int start = 0, end = heaters.size() - 1;
            while (end > start)
            {
                int mid = (start + end) / 2;
                if (heaters[mid] < ho)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid;
                }
            }
            // 若找到的值等于房屋的位置，则当前房屋距离加热器的最短距离为0
            if (heaters[start] == ho)
            {
                res.push_back(0);
            }
            // 如果该加热器的位置小于房屋的位置，则最小距离就是二者的距离
            else if (heaters[start] < ho)
            {
                res.push_back(ho - heaters[start]);
            }
            // 如果大于房屋的位置且此时start不为0，说明房屋的坐标应为start或者start-1，选二者中小的一个作为最小距离
            else if (start)
            {
                res.push_back(min(heaters[start] - ho, ho - heaters[start - 1]));
            }
            // 否则直接就是二者距离
            else
            {
                res.push_back(heaters[start] - ho);
            }
        }
        // 返回所有最小距离中最大的距离作为半径
        return *max_element(res.begin(), res.end());
    }
};
// @lc code=end
