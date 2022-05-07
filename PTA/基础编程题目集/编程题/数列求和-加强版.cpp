/*
7-38 数列求和-加强版 （20 分）
给定某数字A（1≤A≤9）以及非负整数N（0≤N≤100000），求数列之和S=A+AA+AAA+⋯+AA⋯A（N个A）。例如A=1, N=3时，S=1+11+111=123。

输入格式：

输入数字A与非负整数N。

输出格式：

输出其N项数列之和S的值。

输入样例：

1 3
输出样例：

123
*/

//此题思路是逐个计算每个位上加起来的结果，之后依次进位，直到每个位上只有一位数字为止，最后的最高位之后一位的数字为0，从后往前输出即可

#include "iostream"

int arr[200000];

int main()
{
    int A = 0, N = 0;
    std::cin >> A >> N;

    if (N == 0)
    {
        std::cout << 0;
    }
    else
    {
        //把每个位上应该有的和加起来
        for (int i = 0; i < N; i++)
        {
            arr[i] = (N - i) * A;
        }

        //进位计算
        int index = 0;
        while (arr[index])
        {
            int t = arr[index];
            arr[index] = t % 10;
            arr[index + 1] += t / 10;
            index++;
        }

        //倒序输出
        for (int i = index - 1; i >= 0; i--)
        {
            std::cout << arr[i];
        }
    }

    return 0;
}