/*
题目描述
有一种有趣的字符串价值计算方式:统计字符串中每种字符出现的次数,然后求所有字符次数的平方和作为字符串的价值
例如: 字符串"abacaba",里面包括4个'a',2个'b',1个'c',于是这个字符串的价值为4 * 4 + 2 * 2 + 1 * 1 = 21
牛牛有一个字符串s,并且允许你从s中移除最多k个字符,你的目标是让得到的字符串的价值最小。

输入描述:
输入包括两行,第一行一个字符串s,字符串s的长度length(1 ≤ length ≤ 50),其中只包含小写字母('a'-'z')。
第二行包含一个整数k(0 ≤ k ≤ length),即允许移除的字符个数。

输出描述:
输出一个整数,表示得到的最小价值
示例1
输入
aba
1
输出
2
*/

//有一点想叉了，关于如何使其变得最小价值的部分，这里还是看别人的想法才纠正过来的

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"

int main()
{
    //输入
    std::string s;
    std::cin >> s;
    int k = 0;
    std::cin >> k;

    //统计每个字符出现的次数
    std::vector<std::pair<char, int>> vec;
    for (auto cit = s.cbegin(); cit != s.cend(); cit++)
    {
        auto it = std::find_if(vec.begin(), vec.end(), [&](const std::pair<char, int> &p) { return p.first == *cit; });
        if (it == vec.end())
        {
            vec.push_back({*cit, 1});
        }
        else
        {
            it->second++;
        }
    }

    //在k次之中，每次削减最高位的次数，之后重新排序，这里的想法是尽量把所有的次数做的尽可能的持平，都保持在一个很低的水平上，价值最小
    for (int i = 0; i < k; i++)
    {
        std::sort(vec.begin(), vec.end(), [](const std::pair<char, int> &p1, const std::pair<char, int> &p2) { return p1.second > p2.second; });
        vec[0].second--;
    }

    //计算价值
    int value = 0;
    for (auto cit = vec.cbegin(); cit != vec.cend(); cit++)
    {
        value += cit->second * cit->second;
    }

    //输出
    std::cout << value;

    return 0;
}