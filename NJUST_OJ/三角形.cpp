/*
Description
给你三角形的三边，判断是否为直角三角形。

Input
第一行输入测试个数t。t<=100以下t行每行输入三个整数a，b，c

Output
如果是直角三角形，输出Y，否则输出N

Sample Input
2
3  4  5
6  8  9

Sample Output
Y
N
*/

#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
int main()
{
    int t = 0;
    std::cin >> t;
    std::vector<std::vector<int>> triangle(t, std::vector<int>(3, 0));
    for (int i = 0; i < t; i++)
    {
        std::cin >> triangle[i][0] >> triangle[i][1] >> triangle[i][2];
    }

    for (std::vector<std::vector<int>>::iterator it = triangle.begin(); it != triangle.end(); it++)
    {
        std::sort((*it).begin(), (*it).end()); //直角三角形一定是两条较小的边的平方和等于最大的边的平方
        if (pow((*it)[0], 2) + pow((*it)[1], 2) == pow((*it)[2], 2))
        {
            std::cout << "Y";
        }
        else
        {
            std::cout << "N";
        }
        if (it != triangle.end() - 1)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}