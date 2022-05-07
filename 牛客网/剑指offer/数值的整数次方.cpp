/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/

class Solution
{
  public:
    double Power(double base, int exponent)
    {
        double num = 1;
        if (exponent >= 0)
        {
            for (int i = 0; i < exponent; i++)
            {
                num *= base;
            }
            return num;
        }
        //注意次方小于0时候的情况
        else
        {
            for (int i = 0; i < -exponent; i++)
            {
                num *= base;
            }
            return 1 / num;
        }
    }
};