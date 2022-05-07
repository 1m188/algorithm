/*
Description
读入两个小于100的正整数A和B,计算A+B.
需要注意的是:A和B的每一位数字由对应的英文单词给出.

Input
测试输入包含若干测试用例,每个测试用例占一行,格式为"A + B =",相邻两字符串有一个空格间隔.当A和B同时为0时输入结束,相应的结果不要输出. 

Output
对每个测试用例输出1行,即A+B的值.

Sample Input
one + two =
three four + five six =
zero seven + eight nine =
zero + zero =

Sample Output
3
90
96
*/

#include "iostream"
#include "string"
#include "vector"

int English2Int(std::string s)
{
    if (s == "zero")
    {
        return 0;
    }
    else if (s == "one")
    {
        return 1;
    }
    else if (s == "two")
    {
        return 2;
    }
    else if (s == "three")
    {
        return 3;
    }
    else if (s == "four")
    {
        return 4;
    }
    else if (s == "five")
    {
        return 5;
    }
    else if (s == "six")
    {
        return 6;
    }
    else if (s == "seven")
    {
        return 7;
    }
    else if (s == "eight")
    {
        return 8;
    }
    else if (s == "nine")
    {
        return 9;
    }
    else
    {
        return -1;
    }
}

int main() //AC.
{
    std::vector<std::pair<int, int>> num{};
    std::string input = "";
    while (std::getline(std::cin, input))
    {
        std::pair<int, int> numTemp{};
        std::string num1 = input.substr(0, input.find('+') - 1); //注意substr第一个参数是分割出来的字符串开始的索引，第二个参数是分割字符串的长度
        std::string num2 = input.substr(input.find('+') + 2, input.size() - input.find('+') - 4);
        if (num1.find(' ') == std::string::npos)
        {
            numTemp.first = English2Int(num1);
        }
        else
        {
            numTemp.first = English2Int(num1.substr(0, num1.find(' '))) * 10 + English2Int(num1.substr(num1.find(' ') + 1, num1.size() - num1.find(' ') - 1));
        }
        if (num2.find(' ') == std::string::npos)
        {
            numTemp.second = English2Int(num2);
        }
        else
        {
            numTemp.second = English2Int(num2.substr(0, num2.find(' '))) * 10 + English2Int(num2.substr(num2.find(' ') + 1, num2.size() - num2.find(' ') - 1));
        }
        if ((!numTemp.first) && (!numTemp.second))
        {
            break;
        }
        num.push_back(numTemp);
    }

    for (std::vector<std::pair<int, int>>::iterator it = num.begin(); it != num.end(); it++)
    {
        std::cout << (*it).first + (*it).second << std::endl;
    }

    return 0;
}