/*
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

/*
每一次sum=a^b，则sum是a+b减去进位的值，carry=(a&b)<<1，carry是减去的那个进位的值，a和b真正的和为sum+carry，但是由于不能使用加号，
因此把a=sum和b=carry继续以上操作，直到carry=1,那么这个时候sum就是最终的结果，可以证明，这个算法一定可以在某一步得到结果，并不会无限循环
*/

class Solution
{
  public:
    int Add(int num1, int num2)
    {
        return num2 ? Add(num1 ^ num2, (num1 & num2) << 1) : num1;
    }
};