/*
Description
读入两个小于10000的正整数A和B，计算A+B。需要注意的是：如果A和B的末尾K（不超过8）位数字相同，请直接输出-1。

Input
测试输入包含若干测试用例，每个测试用例占一行，格式为"A B K"，相邻两数字有一个空格间隔。当A和B同时为0时输入结束，相应的结果不要输出。

Output
对每个测试用例输出1行，即A+B的值或者是-1。

Sample Input
1 2 1
11 21 1
108 8 2
36 64 3
0 0 1

Sample Output
3
-1
-1
100
*/

#include "iostream"
#include "vector"
#include "tuple"
int main() //AC.
{
    std::vector<std::tuple<int, int, int>> test{};
    int A = 0, B = 0, K = 0;
    std::cin >> A >> B >> K;
    while (A && B)
    {
        test.push_back(std::tuple<int, int, int>(A, B, K));
        std::cin >> A >> B >> K;
    }

    for (std::vector<std::tuple<int, int, int>>::iterator it = test.begin(); it != test.end(); it++)
    {
        int a = std::get<0>(*it), b = std::get<1>(*it), k = std::get<2>(*it);
        while (k)
        {
            if (a % 10 != b % 10)
            {
                break;
            }
            else
            {
                a /= 10;
                b /= 10;
                k--;
            }
        }
        if (k)
        {
            std::cout << std::get<0>(*it) + std::get<1>(*it);
        }
        else
        {
            std::cout << -1;
        }
        std::cout << std::endl;
    }

    return 0;
}