/*
问题描述
　　给定一个长度为n的字符串S，还有一个数字L，统计长度大于等于L的出现次数最多的子串（不同的出现可以相交），如果有多个，输出最长的，如果仍然有多个，输出第一次出现最早的。
输入格式
　　第一行一个数字L。
　　第二行是字符串S。
　　L大于0，且不超过S的长度。
输出格式
　　一行，题目要求的字符串。

　　输入样例1：
　　4
　　bbaabbaaaaa

　　输出样例1：
　　bbaa

　　输入样例2：
　　2
　　bbaabbaaaaa

　　输出样例2：
　　aa
数据规模和约定
　　n<=60
　　S中所有字符都是小写英文字母。
提示
　　枚举所有可能的子串，统计出现次数，找出符合条件的那个
*/

#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "algorithm"

bool paixu(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2)
{
    return p1.second > p2.second;
}

bool paixu1(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2)
{
    return p1.first.size() > p2.first.size();
}

int main()
{
    int L = 0;
    std::string str;
    std::cin >> L >> str;

    std::map<std::string, int> map;

    while (L <= str.size())
    {
        int index = 0;
        while (true)
        {
            std::string t = str.substr(index, L);
            if (t.size() < L)
            {
                break;
            }
            else
            {
                if (map.count(t) == 0)
                {
                    map.insert({t, 1});
                }
                else
                {
                    map.at(t)++;
                }
            }
            index++;
        }
        L++;
    }

    std::vector<std::pair<std::string, int>> vec;
    for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); it++)
    {
        vec.push_back({it->first, it->second});
    }

    std::sort(vec.begin(), vec.end(), paixu);
    std::vector<std::pair<std::string, int>>::iterator it = vec.begin() + 1;
    while (it->second == vec.begin()->second)
    {
        it++;
    }
    vec.erase(it, vec.end());

    if (vec.size() > 1)
    {
        std::sort(vec.begin(), vec.end(), paixu1);
        it = vec.begin() + 1;
        while (it->first.size() == vec.begin()->first.size())
        {
            it++;
        }
        vec.erase(it, vec.end());

        if (vec.size() > 1)
        {
            int index = str.find(vec[0].first);
            it = vec.begin() + 1;
            while (it < vec.end())
            {
                if (str.find(it->first) < index)
                {
                    index = str.find(it->first);
                    vec[0] = *it;
                }
                it++;
            }
        }
    }

    std::cout << vec[0].first;

    return 0;
}