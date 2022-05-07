/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (53.86%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 42K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// 1.不考虑进位对每一位相加。0加0、1加1结果都是0,0加1、1加0结果都是1。这和异或运算一样；
// 2.考虑进位，0加0、0加1、1加0都不产生进位，只有1加1向前产生一个进位。可看成是先做位与运算，然后向左移动一位；
// 3.相加过程重复前两步，直到不产生进位为止。
// 注意移位的时候的补码的问题
// leetcode的C++编译器似乎不允许有符号整数的负极限往左移位，我在msvc2017上面试了是可以的，但是leetcode的C++编译器会报错

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        else
        {
            return getSum(a ^ b, unsigned(a & b) << 1);
        }
    }
};
// @lc code=end
