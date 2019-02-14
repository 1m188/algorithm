/*
随意组合

小明被绑架到X星球的巫师W那里。

其时，W正在玩弄两组数据 (2 3 5 8) 和 (1 4 6 7)
他命令小明从一组数据中分别取数与另一组中的数配对，共配成4对（组中的每个数必被用到）。
小明的配法是：{(8,7),(5,6),(3,4),(2,1)}

巫师凝视片刻，突然说这个配法太棒了！

因为：
每个配对中的数字组成两位数，求平方和，无论正倒，居然相等：
87^2 + 56^2 + 34^2 + 21^2  =  12302
78^2 + 65^2 + 43^2 + 12^2  =  12302

小明想了想说：“这有什么奇怪呢，我们地球人都知道，随便配配也可以啊！”
{(8,6),(5,4),(3,1),(2,7)}

86^2 + 54^2 + 31^2 + 27^2 = 12002
68^2 + 45^2 + 13^2 + 72^2 = 12002

巫师顿时凌乱了。。。。。

请你计算一下，包括上边给出的两种配法，巫师的两组数据一共有多少种配对方案具有该特征。
配对方案计数时，不考虑配对的出现次序。
就是说：
{(8,7),(5,6),(3,4),(2,1)}
与
{(5,6),(8,7),(3,4),(2,1)}
是同一种方案。

注意：需要提交的是一个整数，不要填写任何多余内容（比如，解释说明文字等）
*/

#include "iostream"
#include "vector"
#include "cmath"

int Pair(const std::vector<std::vector<int>> &data, std::vector<std::pair<int, int>> &pair, std::vector<std::vector<bool>> &sign, int x = 0)
{ //DFS老套路，思想一样但是具体的实现手段由于有两组数据所以有些变通
    static int caseNum = 0;

    if (x == 4)
    {
        if (pow(pair[0].first * 10 + pair[0].second, 2) + pow(pair[1].first * 10 + pair[1].second, 2) + pow(pair[2].first * 10 + pair[2].second, 2) + pow(pair[3].first * 10 + pair[3].second, 2) == pow(pair[0].second * 10 + pair[0].first, 2) + pow(pair[1].second * 10 + pair[1].first, 2) + pow(pair[2].second * 10 + pair[2].first, 2) + pow(pair[3].second * 10 + pair[3].first, 2))
        {
            caseNum++;
        }
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!(sign[0][i] || sign[1][j]))
            {
                sign[0][i] = 1;
                sign[1][j] = 1;
                pair.push_back(std::pair<int, int>(data[0][i], data[1][j]));
                Pair(data, pair, sign, x + 1);
                pair.pop_back();
                sign[0][i] = 0;
                sign[1][j] = 0;
            }
        }
    }

    return caseNum / 24;
}

int main()
{
    const std::vector<std::vector<int>> data{std::vector<int>{2, 3, 5, 8}, std::vector<int>{1, 4, 6, 7}};
    std::vector<std::vector<bool>> sign(2, std::vector<bool>(4, 0));
    std::vector<std::pair<int, int>> pair(4, std::pair<int, int>(0, 0));
    std::cout << Pair(data, pair, sign) << std::endl;

    return 0;
}