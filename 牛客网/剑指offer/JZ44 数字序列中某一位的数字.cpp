/**
 * @file JZ44 数字序列中某一位的数字.cpp
 * @date 2022-05-12
 */

/*
描述
数字以 0123456789101112131415... 的格式作为一个字符序列，
在这个序列中第 2 位（从下标 0 开始计算）是 2 ，第 10 位是 1 ，第 13 位是 1 ，
以此类题，请你输出第 n 位对应的数字。

数据范围： 0≤n≤10^9
  
示例1
输入：
0

返回值：
0

示例2
输入：
2

返回值：
2

示例3
输入：
10

返回值：
1

示例4
输入：
13

返回值：
1
*/

/* 不得不说这题挺绕的，先把多余的部分的区间去掉，然后在目标区间中找到具体的数字，
再在具体的数字中找到具体的位数，最后把低位多余的丢掉，返回最后一位数 */

class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return int整型
     */
    int findNthDigit(int n) {
        // write code here

        if (n >= 0 && n <= 9) // 当作特殊情况
            return n;

        int start = 1, end = 9, bit_num = 1, total_bitn = (end - start + 1) * bit_num;

        while (n - total_bitn > 0) { // 减去多余位数
            n -= total_bitn;
            start *= 10;
            end = end * 10 + 9;
            bit_num++;
            total_bitn = (end - start + 1) * bit_num;
        }

        int res = start + (n - 1) / bit_num;         // 找到具体数字
        int x = bit_num - 1 - (n - 1) % bit_num - 1; // 从右往左数（从低位到高位），需要干掉几位数
        while (x--)                                  // 干掉低位多余的位数
            res /= 10;
        return res % 10; // 返回最低位即最终结果
    }
};