/*
Description
messIDou和他的女友恩恩爱爱已经五年，但他的舍友yxcwudi出于羡慕嫉妒恨，老是诅咒他们会"七年之痒"，所以messIDou对“7”这个数字格外反感。即使买彩票的时候，与7有关的数字他也不会选。“与7有关”有如下定义：
1、数字的每一位的和含有7或为7的倍数（例：数字158.每一位的和1+5+8=14，是7的倍数）
2、数字本身含有7或为7的倍数（例：数字27.数字本身含有7）
我们知道，彩票有很多不同的玩法。对于n选m玩法即从1-n之间选择m个数。聪明的你，请帮messIDou算出，他到底有多少种不同的买法,与7有关的数可不在他的考虑范围内哦。

Input
第一行为t。表示下面有t组输入。
n，m（n和m均为正整数，且n≤40，m≤5）{哇！好小的数，甚至能直接把所有与7有关的数写出来}

Output
拒绝“与7有关”的数，有多少种购买彩票方案

Sample Input
4
1 1
7 3
7 5
3 5

Sample Output
1
20
6
0
*/

#include "iostream"
#include "vector"
int main() //WA?不知道为什么...
{
    int t = 0;
    std::cin >> t;
    std::vector<std::pair<int, int>> nm{};
    for (int i = 0; i < t; i++)
    {
        int n = 0, m = 0;
        std::cin >> n >> m;
        nm.push_back(std::pair<int, int>(n, m));
    }

    while (!nm.empty())
    {
        int num = nm[0].first;
        for (int i = 1; i <= nm[0].first; i++)
        {
            if (i % 7 == 0)
            {
                num--;
                continue;
            }
            if (i % 10 % 7 == 0)
            {
                num--;
                continue;
            }

            int j = 0, ix = i;
            j = ix % 10;
            while (ix /= 10)
            {
                j += ix % 10;
            }
            if (j % 7 == 0)
            {
                num--;
                continue;
            }
            if (j % 10 % 7 == 0)
            {
                num--;
                continue;
            }
        }
        int a = 1;
        for (int i = 1; i <= num; i++)
        {
            a *= i;
        }
        int b = 1;
        for (int i = 1; i <= nm[0].second; i++)
        {
            b *= i;
        }
        int c = 1;
        for (int i = 1; i <= num - nm[0].second; i++)
        {
            c *= i;
        }
        std::cout << a / (b * c);
        if (nm.size() != 1)
        {
            std::cout << std::endl;
        }
        nm.erase(nm.begin());
    }

    return 0;
}