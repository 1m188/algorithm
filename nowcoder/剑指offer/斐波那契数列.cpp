/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

//非递归求斐波那契数列即可

class Solution
{
  public:
    int Fibonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        else if (n == 2)
        {
            return 1;
        }
        else
        {
            int a = 1, b = 1;
            for (int i = 3; i <= n; i++)
            {
                int c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    }
};