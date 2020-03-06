/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 *
 * https://leetcode-cn.com/problems/binary-gap/description/
 *
 * algorithms
 * Easy (60.05%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 13.4K
 * Testcase Example:  '22'
 *
 * 给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。 
 * 
 * 如果没有两个连续的 1，返回 0 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：22
 * 输出：2
 * 解释：
 * 22 的二进制是 0b10110 。
 * 在 22 的二进制表示中，有三个 1，组成两对连续的 1 。
 * 第一对连续的 1 中，两个 1 之间的距离为 2 。
 * 第二对连续的 1 中，两个 1 之间的距离为 1 。
 * 答案取两个距离之中最大的，也就是 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：5
 * 输出：2
 * 解释：
 * 5 的二进制是 0b101 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：6
 * 输出：1
 * 解释：
 * 6 的二进制是 0b110 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：8
 * 输出：0
 * 解释：
 * 8 的二进制是 0b1000 。
 * 在 8 的二进制表示中没有连续的 1，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 */

#include "string"
#include "algorithm"
using namespace std;

// @lc code=start
class Solution
{
public:
    int binaryGap(int N)
    {
        // AC 模拟成字符串然后在字符串里面算距离
        // string s;
        // while (N)
        // {
        //     s.push_back(N % 2 + '0');
        //     N /= 2;
        // }
        // int index = s.find('1');
        // int dis = 0;
        // for (int i = index + 1; i < s.size(); i++)
        // {
        //     if (s[i] == '1')
        //     {
        //         dis = max(dis, i - index);
        //         index = i;
        //     }
        // }
        // return dis;

        // AC 通过不断的求二进制数的每个位上的数，求了几次就是索引，据此获取距离，不用转string，比上面的快
        int index = 0;
        int cursor = 0;
        int dis = 0;
        int remain = 0;
        while ((remain = N % 2) != 1)
        {
            N /= 2;
            index++;
        }
        cursor = index;
        while (N)
        {
            if (N % 2 == 1)
            {
                dis = max(dis, cursor - index);
                index = cursor;
            }
            N /= 2;
            cursor++;
        }
        return dis;
    }
};
// @lc code=end
