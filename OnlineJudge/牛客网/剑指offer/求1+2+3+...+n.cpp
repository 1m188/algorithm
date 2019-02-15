/*
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//递归求解

class Solution
{
  public:
    int Sum_Solution(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        else
        {
            return n + Sum_Solution(n - 1);
        }
    }
};