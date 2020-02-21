/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 *
 * https://leetcode-cn.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (62.72%)
 * Likes:    211
 * Dislikes: 0
 * Total Accepted:    31.1K
 * Total Submissions: 47.4K
 * Testcase Example:  '38'
 *
 * 给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。
 * 
 * 示例:
 * 
 * 输入: 38
 * 输出: 2 
 * 解释: 各位相加的过程为：3 + 8 = 11, 1 + 1 = 2。 由于 2 是一位数，所以返回 2。
 * 
 * 
 * 进阶:
 * 你可以不使用循环或者递归，且在 O(1) 时间复杂度内解决这个问题吗？
 * 
 */

#include "string"

// @lc code=start
class Solution
{
public:
    int addDigits(int num)
    {
        // AC
        // 按题意每位反复相加直到为1
        // while (num >= 10)
        // {
        //     int tmp = 0;
        //     while (num)
        //     {
        //         tmp += num % 10;
        //         num /= 10;
        //     }
        //     num = tmp;
        // }
        // return num;

        // AC
        // 将数字转换为字符串，然后逐位相加，一旦和为两位数则将其相加重回一位
        // 因为两个单位数相加最多为18（9+9），因此如果相加后为两位数只需再相加一次即可重回一位数
        // auto ns = std::to_string(num);
        // num = 0;
        // for (const char &c : ns)
        // {
        //     num += c - '0';
        //     if (num >= 10)
        //     {
        //         num = num % 10 + num / 10;
        //     }
        // }
        // return num;

        // AC
        // 数根
        return (num - 1) % 9 + 1;
    }
};
// @lc code=end
