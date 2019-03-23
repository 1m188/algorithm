/*
问题描述
　　编写一函数lcm，求两个正整数的最小公倍数。
样例输入
一个满足题目要求的输入范例。
例：

3 5
样例输出
与上面的样例输入对应的输出。
例：

数据规模和约定
　　输入数据中每一个数的范围。
　　例：两个数都小于65536。
*/

#include "iostream"

int lcm(int a, int b)
{
    int max = a > b ? a : b;
    int min = a < b ? a : b;

    int res = 0;
    for (int i = 1; i <= min; i++)
    {
        if (i * max % min == 0)
        {
            res = i * max;
            break;
        }
    }
    return res;
}

int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    std::cout << lcm(a, b);

    return 0;
}