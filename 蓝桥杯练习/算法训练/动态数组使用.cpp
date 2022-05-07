/*
从键盘读入n个整数，使用动态数组存储所读入的整数，并计算它们的和与平均值分别输出。要求尽可能使用函数实现程序代码。平均值为小数的只保留其整数部分。
样例输入: 
5 
3 4 0 0 2
样例输出:
9  1
样例输入: 
7
3 2 7 5 2 9 1
样例输出:
29  4
*/

#include "iostream"

int main()
{
    int n = 0;
    std::cin >> n;

    int sum = 0;
    int *vec = new int[n]{0};
    for (int i = 0; i < n; i++)
    {
        std::cin >> vec[i];
        sum += vec[i];
    }
    delete[] vec;

    std::cout << sum << ' ' << sum / n;

    return 0;
}