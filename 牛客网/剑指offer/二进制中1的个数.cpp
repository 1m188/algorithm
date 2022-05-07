/*
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
*/

//和1按位与获取最低位数字即可，注意有负数，因此不能够用n是否为0作为判断条件，负数右移左边补符号位1，因此需要获取int的长度

class Solution
{
  public:
    int NumberOf1(int n)
    {
        int num = 0;
        for (int i = 0; i < sizeof(int) * 8; i++)
        {
            num += n & 0x01;
            n >>= 1;
        }
        return num;
    }
};