/*
Description
给定两个正整数，计算这两个数的最小公倍数。

Input
输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.

Output
对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。

Sample Input
10 14

Sample Output
70
*/

#include "iostream"
#include "vector"
int main() //PE。
{
    std::vector<std::pair<int, int>> data{};
    int a = 0, b = 0;
    std::cin >> a >> b;
    while (!std::cin.eof())
    {
        data.push_back(std::pair<int, int>(a, b));
        std::cin >> a >> b;
    }

    for (std::vector<std::pair<int, int>>::iterator it = data.begin(); it != data.end(); it++)
    {
        if ((*it).first < (*it).second)
        {
            std::swap((*it).first, (*it).second);
        }
        for (int i = 1; i <= (*it).second; i++)
        {
            if (!((*it).first * i % (*it).second))
            {
                std::cout << (*it).first * i;
                break;
            }
        }
        if (it != data.end() - 1)
        {
            std::cout << std::endl;
        }
    }

    return 0;
}