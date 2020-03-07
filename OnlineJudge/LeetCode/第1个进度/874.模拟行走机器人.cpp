/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 *
 * https://leetcode-cn.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (32.47%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 18.3K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
 * 
 * 
 * -2：向左转 90 度
 * -1：向右转 90 度
 * 1 <= x <= 9：向前移动 x 个单位长度
 * 
 * 
 * 在网格上有一些格子被视为障碍物。
 * 
 * 第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
 * 
 * 如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
 * 
 * 返回从原点到机器人的最大欧式距离的平方。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: commands = [4,-1,3], obstacles = []
 * 输出: 25
 * 解释: 机器人将会到达 (3, 4)
 * 
 * 
 * 示例 2：
 * 
 * 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * 输出: 65
 * 解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= commands.length <= 10000
 * 0 <= obstacles.length <= 10000
 * -30000 <= obstacle[i][0] <= 30000
 * -30000 <= obstacle[i][1] <= 30000
 * 答案保证小于 2 ^ 31
 * 
 * 
 */

#include "vector"
#include "cmath"
#include "algorithm"
#include "set"
using namespace std;

// @lc code=start
class Solution
{
private:
    const double pi = atan(1) * 4;
    pair<int, int> move = {0, 1};
    double dir = pi / 2;
    void turn(const int &d)
    {
        // printf("%f ", dir);
        // printf("%d/%d ", move.first, move.second);
        switch (d)
        {
        case -2:
            dir += pi / 2;
            break;
        case -1:
            dir -= pi / 2;
            break;
        }
        // printf("%f ", dir);
        move.first = cos(dir);
        move.second = sin(dir);
        // printf("%d/%d\n", move.first, move.second);
    }

public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        set<pair<int, int>> s;
        for (const auto &ob : obstacles)
        {
            s.insert({ob[0], ob[1]});
        }

        int distance = 0;
        pair<int, int> pos = {0, 0};
        for (const int &cmd : commands)
        {
            if (cmd < 0)
            {
                turn(cmd);
                continue;
            }

            int x = cmd;
            while (x--)
            {
                pos.first += move.first;
                pos.second += move.second;
                if (s.find(pos) != s.end())
                {
                    pos.first -= move.first;
                    pos.second -= move.second;
                    break;
                }
            }

            distance = max(distance, pos.first * pos.first + pos.second * pos.second);
        }
        return distance;
    }
};
// @lc code=end
