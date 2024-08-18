/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 *
 * https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Easy (43.56%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    7.1K
 * Total Submissions: 16.2K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
 * 
 * 返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字  i < j 且有 (time[i] + time[j]) %
 * 60 == 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[30,20,150,100,40]
 * 输出：3
 * 解释：这三对的总持续时间可被 60 整数：
 * (time[0] = 30, time[2] = 150): 总持续时间 180
 * (time[1] = 20, time[3] = 100): 总持续时间 120
 * (time[1] = 20, time[4] = 40): 总持续时间 60
 * 
 * 
 * 示例 2：
 * 
 * 输入：[60,60,60]
 * 输出：3
 * 解释：所有三对的总持续时间都是 120，可以被 60 整数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 * 
 * 
 */

// 这题太折磨人了......我提交了好多遍都没过，其中有些还是提交不过测试过了的......
// 首先求每个元素的余数，记录其余数和个数的映射，然后0和0的组合，30和30的组合，剩下的和其对60的补数
// 组合，求出个数即可

#include "vector"
#include "unordered_map"
using namespace std;

// @lc code=start
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        if (time.size() == 1)
        {
            return 0;
        }

        unordered_map<int, int> um;
        for (const int &t : time)
        {
            um[t % 60]++;
        }

        int res = 0;
        if (um.find(0) != um.end())
        {
            res += (um[0] * (um[0] - 1)) / 2;
            um.erase(0);
        }
        if (um.find(30) != um.end())
        {
            res += (um[30] * (um[30] - 1)) / 2;
            um.erase(30);
        }
        for (auto it = um.begin(); it != um.end();)
        {
            int target = 60 - it->first;
            if (it->second > 0 && um[target] > 0)
            {
                res += it->second * um[target];
                um.erase(target);
                it = um.erase(it);
            }
            else
            {
                it++;
            }
        }
        return res;
    }
};
// @lc code=end