/*
Description
给你2个分数，求他们的和，并要求和为最简形式。
Input
输入首先包含一个正整数T（T<=1000），表示有T组测试数据，然后是T行数据，每行包含四个正整数a,b,c,d（0<a,b,c,d<1000），表示两个分数a/b 和 c/d。
Output
对于每组测试数据，输出两个整数e和f，表示a/b + c/d的最简化结果是e/f，每组输出占一行。
Sample Input
2
1 2 1 3
4 3 2 3
Sample Output
5 6
2 1
*/

#include "iostream"
#include "vector"
#include "tuple"

int Gcd(int a, int b)
{
    if (b > a)
    {
        std::swap(a, b);
    }

    int c = a % b;
    while (c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main() //RE.Runtime Error，哪里出错了...
{
    int T = 0;
    std::cin >> T;
    std::vector<std::tuple<int, int, int, int>> input(T, std::tuple<int, int, int, int>{});
    for (int i = 0; i < T; i++)
    {
        std::cin >> std::get<0>(input[i]) >> std::get<1>(input[i]) >> std::get<2>(input[i]) >> std::get<3>(input[i]);
    }

    for (std::vector<std::tuple<int, int, int, int>>::iterator it = input.begin(); it != input.end(); it++)
    {
        std::pair<int, int> firstNum{}, secondNum{};
        firstNum.first = std::get<0>(*it);
        firstNum.second = std::get<1>(*it);
        secondNum.first = std::get<2>(*it);
        secondNum.second = std::get<3>(*it);

        int gcd = Gcd(firstNum.first, firstNum.second);
        firstNum.first /= gcd;
        firstNum.second /= gcd;
        gcd = Gcd(secondNum.first, secondNum.second);
        secondNum.first /= gcd;
        secondNum.second /= gcd;

        std::pair<int, int> result{};
        result.first = firstNum.first * secondNum.second + firstNum.second * secondNum.first;
        result.second = firstNum.second * secondNum.second;
        gcd = Gcd(result.first, result.second);
        result.first /= gcd;
        result.second /= gcd;

        std::cout << result.first << ' ' << result.second << std::endl;
    }

    return 0;
}