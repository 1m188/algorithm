/*
问题描述
给出n个数，找出这n个数的最大值，最小值，和。

输入格式
第一行为整数n，表示数的个数。

第二行有n个数，为给定的n个数，每个数的绝对值都小于10000。

输出格式
输出三行，每行一个整数。第一行表示这些数中的最大值，第二行表示这些数中的最小值，第三行表示这些数的和。
样例输入
5
1 3 -2 4 5
样例输出
5
-2
11
数据规模与约定
1 <= n <= 10000。
*/

#include "iostream"

int main()
{
    int n = 0;
    std::cin >> n;

    int max = -10000, min = 10000, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        std::cin >> t;
        if (t > max)
        {
            max = t;
        }
        if (t < min)
        {
            min = t;
        }
        sum += t;
    }

    std::cout << max << std::endl
              << min << std::endl
              << sum;

    return 0;
}