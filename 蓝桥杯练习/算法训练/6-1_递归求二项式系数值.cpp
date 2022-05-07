/*
问题描述

样例输入
一个满足题目要求的输入范例。
3 10
样例输出
与上面的样例输入对应的输出。

数据规模和约定
　　输入数据中每一个数的范围。
　　例：结果在int表示时不会溢出。
*/

#include "iostream"

int C(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    else
    {
        return C(n - 1, k) + C(n - 1, k - 1);
    }
}

int main()
{
    int n = 0, k = 0;
    std::cin >> k >> n;

    std::cout << C(n, k);

    return 0;
}