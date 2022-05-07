/*
7-25 念数字 （15 分）
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出fu字。十个数字对应的拼音如下：

0: ling
1: yi
2: er
3: san
4: si
5: wu
6: liu
7: qi
8: ba
9: jiu
输入格式：

输入在一行中给出一个整数，如：1234。

提示：整数包括负数、零和正数。

输出格式：

在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如 yi er san si。

输入样例：

-600
输出样例：

fu liu ling ling
*/

#include "iostream"
#include "string"
#include "map"

int main()
{
    const std::map<int, std::string> map{{0, "ling"}, {1, "yi"}, {2, "er"}, {3, "san"}, {4, "si"}, {5, "wu"}, {6, "liu"}, {7, "qi"}, {8, "ba"}, {9, "jiu"}};

    std::string num;
    std::cin >> num;

    int size = num.size();
    for (int i = 0; i < size; i++)
    {
        if (num[i] == '-')
        {
            std::cout << "fu";
        }
        else
        {
            std::cout << map.at(num[i] - '0');
        }
        if (i != size - 1)
        {
            std::cout << ' ';
        }
    }

    return 0;
}