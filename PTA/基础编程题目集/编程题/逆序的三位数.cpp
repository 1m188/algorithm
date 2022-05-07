/*
7-3 逆序的三位数 （10 分）
程序每次读入一个正3位数，然后输出按位逆序的数字。注意：当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。

输入格式：

每个测试是一个3位的正整数。

输出格式：

输出按位逆序的数。

输入样例：

123
输出样例：

321
*/

#include "iostream"
#include "sstream"
#include "string"
#include "algorithm"

int main()
{
    int num = 0;
    std::cin >> num;

    std::stringstream ss;
    ss << num;
    std::string str;
    ss >> str;
    std::reverse(str.begin(), str.end());
    ss.clear();
    ss << str;
    ss >> num;

    std::cout << num;

    return 0;
}