/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 *
 * https://leetcode-cn.com/problems/bulls-and-cows/description/
 *
 * algorithms
 * Easy (46.95%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 18.8K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * 你正在和你的朋友玩 猜数字（Bulls and
 * Cows）游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了（称为“Bulls”,
 * 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。
 * 
 * 请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。
 * 
 * 请注意秘密数字和朋友的猜测数都可能含有重复数字。
 * 
 * 示例 1:
 * 
 * 输入: secret = "1807", guess = "7810"
 * 
 * 输出: "1A3B"
 * 
 * 解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
 * 
 * 示例 2:
 * 
 * 输入: secret = "1123", guess = "0111"
 * 
 * 输出: "1A1B"
 * 
 * 解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
 * 
 * 说明: 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。
 * 
 */

#include "string"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0, b = 0;
        auto sit = secret.begin();
        auto git = guess.begin();
        while (git < guess.end())
        {
            if (*sit == *git)
            {
                a++;
                sit = secret.erase(sit);
                git = guess.erase(git);
            }
            else
            {
                sit++;
                git++;
            }
        }
        git = guess.begin();
        while (git < guess.end())
        {
            auto it = find(secret.begin(), secret.end(), *git);
            if (it != secret.end())
            {
                b++;
                secret.erase(it);
            }
            git++;
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
// @lc code=end
