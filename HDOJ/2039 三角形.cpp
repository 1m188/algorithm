/*
Description
给定三条边，请你判断一下能不能组成一个三角形。
Input
输入数据第一行包含一个数M，接下有M行，每行一个实例，包含三个正数A,B,C。其中A,B,C <1000;
Output
对于每个测试实例，如果三条边长A,B,C能组成三角形的话，输出YES，否则NO。 
Sample Input
2
1 2 3
2 2 2
Sample Output
NO
YES
*/

#include "iostream"
#include "vector"
#include "tuple"
int main()
{
    int M = 0;
    std::cin >> M;
    std::vector<std::tuple<double, double, double>> input(M, std::tuple<double, double, double>{});
    for (int i = 0; i < M; i++)
    {
        std::cin >> std::get<0>(input[i]) >> std::get<1>(input[i]) >> std::get<2>(input[i]);
    }

    for (std::vector<std::tuple<double, double, double>>::iterator it = input.begin(); it != input.end(); it++)
    {
        if (std::get<0>(*it) + std::get<1>(*it) > std::get<2>(*it) && std::get<0>(*it) + std::get<2>(*it) > std::get<1>(*it) && std::get<1>(*it) + std::get<2>(*it) > std::get<0>(*it))
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }

    return 0;
}