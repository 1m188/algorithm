/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 *
 * https://leetcode-cn.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (51.79%)
 * Likes:    114
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 20.6K
 * Testcase Example:  '0'
 *
 * 二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。
 * 
 * 每个 LED 代表一个 0 或 1，最低位在右侧。
 * 
 * 
 * 
 * 例如，上面的二进制手表读取 “3:25”。
 * 
 * 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。
 * 
 * 案例:
 * 
 * 
 * 输入: n = 1
 * 返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16",
 * "0:32"]
 * 
 * 
 * 
 * 注意事项:
 * 
 * 
 * 输出的顺序没有要求。
 * 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
 * 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
 * 
 * 
 */

#include "vector"
#include "string"
#include "cmath"
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<bool> led = vector<bool>(10, false);

public:
    vector<string> readBinaryWatch(int num)
    {
        if (num > 0)
        {
            vector<string> res;
            int index = 0;
            for (int i = led.size() - 1; i >= 0; i--)
            {
                if (led[i])
                {
                    index = i + 1;
                    break;
                }
            }
            for (int i = index; i < led.size(); i++)
            {
                if (!led[i])
                {
                    led[i] = true;
                    vector<string> &&tmp = readBinaryWatch(num - 1);
                    for (const string &s : tmp)
                    {
                        res.push_back(s);
                    }
                    led[i] = false;
                }
            }
            return res;
        }
        else
        {
            int h = 0;
            for (int i = 0; i < 4; i++)
            {
                h += led[i] * pow(2, i);
            }
            if (h >= 12)
            {
                return vector<string>();
            }

            int m = 0;
            for (int i = 4; i < 10; i++)
            {
                m += led[i] * pow(2, i - 4);
            }
            if (m >= 60)
            {
                return vector<string>();
            }

            string res = to_string(h) + ":";
            if (m < 10)
            {
                res += "0" + to_string(m);
            }
            else
            {
                res += to_string(m);
            }
            return vector<string>{res};
        }
    }
};
// @lc code=end
