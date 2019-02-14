/*
Description
幸运的你，今天碰到了这个世界上最简单的问题。在这个问题中，所有你要做的就是为一个给定的数加一。
并且，为了纪念出题者第一次为校赛出题，我甚至会告诉你这个最简单问题的做法(请见hint).
聪明的你，还不赶紧抓住这道题^_^?
hint:可以用字符串数组模拟这道题

Input
第一行给出一个整数T,表示case数，然后会有T行，每一行一个十进制正整数x。为了体现我们的人文关怀，我们保证每一个数据的长度不会超过100位。

Output
输出x+1

Sample Input
4
1
521
20100515
999

Sample Output
2
522
20100516
1000
*/

#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
int main()
{
    int T = 0;
    std::cin >> T;
    std::vector<std::string> str{};
    for (int i = 0; i < T; i++)
    {
        std::string temp = "";
        std::cin >> temp;
        str.push_back(temp);
    }

    for (std::vector<std::string>::iterator it = str.begin(); it != str.end(); it++)
    {
        int num = (*it).back() - '0' + 1;
        (*it)[(*it).size() - 1] = num + '0';
        for (int i = (*it).size() - 1; num == 10 && i > 0; i--)
        {
            (*it)[i] = '0';
            num = (*it)[i - 1] - '0' + 1;
            (*it)[i - 1] = num + '0';
        }
        if ((*it)[0] == 10 + '0')
        {
            (*it)[0] = '0';
            (*it).insert((*it).begin(), '1');
        }
    }

    for_each(str.begin(), str.end(), [&](std::string i) { std::cout << i << std::endl; });

    return 0;
}