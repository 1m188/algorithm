/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.81%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 19K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 
 * 注意:
 * n 是正数且在32为整形范围内 ( n < 2^31)。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 3
 * 
 * 输出:
 * 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 11
 * 
 * 输出:
 * 0
 * 
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
 * 
 * 
 */

#include "cmath"
#include "string"

// @lc code=start
class Solution
{
public:
    int findNthDigit(int n)
    {
        // 首先从1-9这个区间开始，判断n位数所在的数字区间
        long long numNum = 9; // 定义当前位数的最大的数字
        int bit = 1;          // 定义当前位数
        long long p = 0;      // 这里作为10的幂
        // 这里判断直到n落入某个数字区间中
        while (n > numNum * bit) // 如果n的位数大于当前位数的所有数字的位数之和的话
        {
            n -= numNum * bit; // 进入到下一个区间
            bit++;             // 进位
            numNum *= 10;      // 下一个区间的最大数字
            p++;               // 当前位数的最开始的数的幂
        }
        p = pow(10, p); // 获取当前数字区间的最开始的数字
        // 从开始的数字开始加上跳过多少个数字，这里n/bit获取的是包括第一个数字开始往后走多少个数字，本来
        // 应该是 p += n / bit - 1; 的，但是不-1的话，待会求余的结果就是当前数字的第几位，但如果求余结果
        // 为0的话，说明还不到下一个数字，因此为0应该为上一个数字的最后一位
        p += n / bit;
        int idx = n % bit; // 获取目标位是当前数字的第几位，索引+1
        // 判断给出结果
        if (idx != 0)
        {
            return std::to_string(p)[idx - 1] - '0';
        }
        else
        {
            return std::to_string(p - 1).back() - '0';
        }
    }
};
// @lc code=end
