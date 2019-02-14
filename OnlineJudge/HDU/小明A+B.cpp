/*
Description
小明今年3岁了, 现在他已经能够认识100以内的非负整数, 并且能够进行100以内的非负整数的加法计算.
对于大于等于100的整数, 小明仅保留该数的最后两位进行计算, 如果计算结果大于等于100, 那么小明也仅保留计算结果的最后两位.

例如, 对于小明来说:
1) 1234和34是相等的
2) 35+80=15

给定非负整数A和B, 你的任务是代表小明计算出A+B的值.

Input
输入数据的第一行为一个正整数T, 表示测试数据的组数. 然后是T组测试数据. 每组测试数据包含两个非负整数A和B(A和B均在int型可表示的范围内).

Output
对于每组测试数据, 输出小明A+B的结果.

Sample Input
2
35 80
15 1152

Sample Output
15
67
*/

#include "iostream"
#include "vector"
int main() //AC.
{
    int T = 0;
    std::cin >> T;
    std::vector<std::pair<int, int>> data(T, std::pair<int, int>{});
    for (int i = 0; i < T; i++)
    {
        std::cin >> data[i].first >> data[i].second;
    }

    for (std::vector<std::pair<int, int>>::iterator it = data.begin(); it != data.end(); it++)
    {
        std::cout << ((*it).first % 100 + (*it).second % 100) % 100 << std::endl;
    }

    return 0;
}